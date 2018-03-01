/*
 * week1.c
 *
 * Created: 7-2-2018 19:23:41
 *  Author: Jaap-Jan
 */ 

#include "week1.h"
#include "toolbox.h"

const int sdelay = 50, mdelay = 100, ldelay = 500;

void opdrB2()
{
	DDRD = 0b11111111;			// All pins PORTD are set to output
	while (true)
	{		
		PORTD = BIT(6);
		wait( 500 );
		PORTD = BIT(7);
		wait( 500 );
	}
};

void opdrB3()
{
	// set PORTD for output
	DDRD = 0b01111111;					// PORTD.7 input all other bits output
	while (true)
	{		
		if (PINC & true)
		{			
			PORTD = BIT(7);
			wait(500);
		}
		PORTD = 0;
		if (PINC & true)
		{			
			wait(500);
		}
	}
};

void opdrB4() 
{
	DDRD = 0b11111111;
	PORTD = 1;
	while(true)
	{		
		wait(50);
		PORTD <<= 1;
		if (PORTD == 0)
		{
			PORTD = 1;
		}
	}
};

void opdrB5()
{	
	DDRD = 0b11111111;
	const int mask = 0b111100001111;
	const int steps = 16;
	int index = 0;
	int mode = 0;	
	while(true)
	{			
		int temp = mode++ / steps;
		wait (mdelay);
		if (temp == 0)
		{			
			PORTD = mask >> index++;
			index %= 8;
		}
		else if (temp == 1)
		{
			if (mode % 8 == 1)
			{
				PORTD = 1;
			}
			else
			{			
				PORTD <<= 1;				
			}
		}
		else
		{
			mode = 0;
		}
	}
}

void yieldSleep(int sleep, int step, int* state)
{
	for (int i = 0; i < step; i++)
	{
		if (PINC & true)
		{
			*state = *state == 1 ? 4 : 1;
		}
		wait(sleep / step);
	}
}

void opdrB6()
{
	int state = 1;
	const int waitT = 1000;
	
	while(true)
	{		
		if (PINC & true)
		{
			state = state == 1 ? 4 : 1;
		}		
		
		PORTD = BIT(7);
		yieldSleep(100, 75, &state);		
		PORTD = 0;
		yieldSleep(waitT / state, 200 / state, &state);
	}
}


void*start()
{	
	PORTD = BIT(0);
	
	if (PIND & BIT(5))
		return &s2;
	if (PIND & BIT(6))	
		return &s1;		
	return &start;
}

void*s1()
{
	PORTD = BIT(1);
	
	if (PIND & BIT(5))
		return &s2;
	if (PIND & BIT(7))
		return &start;
	return &s1;
}

void*s2()
{	
	PORTD = BIT(2);
	
	if (PIND & BIT(5))
		return &s3;
	if (PIND & BIT(6))
		return &s1;
	if (PIND & BIT(7))
		return &start;
	return &s2;
}

void*s3()
{
	PORTD = BIT(3);
	
	if (PIND & BIT(5) || PIND & BIT(6))
		return &end;
	if (PIND & BIT(7))
		return &start;	
	return &s3;
}

void*end()
{
	PORTD = BIT(4);
	
	if (PIND & BIT(7))
		return &start;
	return &end;
}


void opdrB7a() 
{
	void* (*state)();
	state = &start;
	
	while (true)
	{
		state = state();
		wait(200);
	}
}