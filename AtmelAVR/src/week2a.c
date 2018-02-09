/*
 * week2.c
 *
 * Created: 8-2-2018 15:51:17
 *  Author: Trist
 */ 
#include "week2a.h"
#include <avr/interrupt.h>

/*
ISR(INT1_vect)
{
	if (PORTC == 0)
		PORTC = 1;
	else
		PORTC <<= 1;
}

ISR(INT2_vect)
{
	if (PORTC == 0)
		PORTC = BIT(7);
	else
		PORTC >>= 1;
}
*/

void opdr2B2()
{
	DDRC = 0xFF;
	
	// set first light C
	PORTC = 1;
	
	EICRA = 0b00101000;			// INT1 falling edge, INT2 rising edge
	EIMSK = 0b110;			// Enable INT1 & INT2
	
	sei();	
	
	while (true) {}	
}