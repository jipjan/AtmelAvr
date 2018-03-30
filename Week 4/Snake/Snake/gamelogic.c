/*
 * gamelogic.c
 *
 * Created: 15-3-2018 13:19:40
 *  Author: jaapj
 */ 

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gamelogic.h"
#include "toolbox.h"
#include "display.h"
#include "segment.h"
#define DOTMATRIX_SIZE	8

uint8_t direction;
uint8_t snake_length;
uint8_t speed;

size_t loc_size = sizeof(location);

location* current;
location* temp;

location* foodLoc;

void gl_change_direction(uint8_t dir)
{
	if (dir == LEFT && direction == RIGHT)	return;
	if (dir == RIGHT && direction == LEFT)	return;
	if (dir == UP && direction == DOWN)		return;
	if (dir == DOWN && direction == UP)		return;
	direction = dir;
}

void gl_restart()
{
	spi_masterInit();
	displayDriverInit();
	srand(time(NULL));
	snake_length = 2;
	
	free(temp);
	free(current);
	free(foodLoc);
	
	foodLoc = malloc(loc_size);
	temp = malloc(loc_size * snake_length);
	current = malloc(loc_size * snake_length);
	
	current[0].x = 3;
	current[0].y = 4;
	current[1].x = 3;
	current[1].y = 5;
	
	direction = DOWN;
	
	gl_make_food();
	gl_loc_to_display();
}

int gl_check_collision(location* locations, location* other)
{
	for (uint8_t i = 0; i < snake_length; i++)
		if (gl_compare_locations(&locations[i], other))
			return 1;
	return 0;
}

int gl_compare_locations(location* first, location* second)
{
	return (first->x == second->x && first->y == second->y);
}

void gl_make_food()
{
	foodLoc->x = rand() % DOTMATRIX_SIZE;
	foodLoc->y = rand() % DOTMATRIX_SIZE;
	if (gl_check_collision(temp, foodLoc))
		gl_make_food();
}

void gl_set_speed(uint8_t setSpeed)
{
	speed = setSpeed;
}

void gl_speed_increase()
{
	uint8_t division = speed / 20;
	speed = speed - division;
}

uint8_t gl_get_speed()
{
	return speed;
}

void gl_gamestep()
{
	// Determine next location of head
	location nextLoc = current[0];
	switch (direction) {
		case UP:
		nextLoc.y = (nextLoc.y + DOTMATRIX_SIZE + 1) % DOTMATRIX_SIZE;
		break;
		case DOWN:
		nextLoc.y = (nextLoc.y + DOTMATRIX_SIZE - 1) % DOTMATRIX_SIZE;
		break;
		case LEFT:
		nextLoc.x = (nextLoc.x + DOTMATRIX_SIZE - 1) % DOTMATRIX_SIZE;
		break;
		case RIGHT:
		nextLoc.x = (nextLoc.x + DOTMATRIX_SIZE + 1) % DOTMATRIX_SIZE;
		break;
	}
	
	// Check collision
	if (gl_check_collision(current, &nextLoc) && !gl_compare_locations(&nextLoc, &current[snake_length - 1]))
	{
		wait(2000);
		gl_restart();
		return;
	}
	
	// Check food
	if (gl_compare_locations(&nextLoc, foodLoc)) {
		snake_length++;
		free(temp);
		temp = malloc(snake_length * loc_size);
		memcpy(temp + 1, current, snake_length * loc_size - loc_size);
		free(current);
		current = malloc(snake_length * loc_size);
		temp[0] = nextLoc;
		gl_make_food();
		gl_speed_increase();
	} else {
		memcpy(temp + 1, current, snake_length * loc_size - loc_size);
		temp[0] = nextLoc;
	}
	location* switcharoo = current;
	current = temp;
	temp = switcharoo;
	
	// display
	gl_loc_to_display();
}

void gl_loc_to_display() {
	emptyDisplay();
	writeLedDisplay(snake_length - 2);
	
	
	displayClr();
	for (int i = 0; i < snake_length; i++)
		displaySetPixel(current[i].x, current[i].y);
	displaySetPixel(foodLoc->x, foodLoc->y);
	display();
}