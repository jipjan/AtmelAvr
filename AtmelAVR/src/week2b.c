/*
 * week2b.c
 *
 * Created: 9-2-2018 12:32:37
 *  Author: Trist
 */ 
#include "week2b.h"
#include <avr/interrupt.h>

const int numbers[] = {
	0x3F, 0x06, 0x5B, 0x4F , 0x66, 0x6D, 0x7D, 0x7, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
};

int counter = 0;

ISR(INT1_vect)
{
	display(++counter);
	wait(200);
}

ISR(INT2_vect)
{
	display(--counter);
	wait(200);
}

void display (int digit)
{
	DDRC = 0b11111111;
	if (digit < 0 || digit > 15)
		PORTC = numbers[14];
	else
		PORTC = numbers[digit];
}

void opdr2B3()
{
	DDRC = 0xFF;
	
	EICRA = 0b00101000;			// INT1 falling edge, INT2 rising edge
	EIMSK = 0b110;			// Enable INT1 & INT2
	
	sei();
	
	display(counter);	
	
	while (true) {
		wait(1);
	}	
}