/*
 * gamelogic.h
 *
 * Created: 15-3-2018 13:19:55
 *  Author: jaapj
 */ 


#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_

#define UP		1
#define RIGHT	2
#define DOWN	3
#define LEFT	4

typedef struct _location {
	uint8_t x;
	uint8_t y;
} location;

void gl_restart(void);
void gl_gamestep(void);
void gl_make_food(void);
void gl_change_direction(uint8_t);
int gl_compare_locations(location* first, location* second);
void gl_loc_to_display(void);

#endif /* GAMELOGIC_H_ */