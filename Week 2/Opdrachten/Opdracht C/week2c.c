/*
 * week2c.c
 *
 * Created: 9-2-2018 13:26:52
 *  Author: Trist
 */ 
#include "week2c.h"

const int pattern[] = {
	0b00001000, 0b00010000, 0b00100000, 0b00000001, 0b00000010, 0b00000100
};

void opdr2B4()
{
	DDRC = 0b11111111;
	while(true)
	{
		for (int i = 0; i < 6; i++)
		{
			PORTC = pattern[i];
			wait(200);
		}
		for (int i = 0; i < 6; i++)
		{
			PORTC = pattern[i];
			wait(100);
		}
	}
}