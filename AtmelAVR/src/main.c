
#include "main.h"
#include <avr/io.h>
#include <util/delay.h>

#define BIT(x) (1 <<(X)))


void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

void opdrB2()
{
	DDRD = 0b11111111;			// All pins PORTD are set to output
	while (1)
	{		
		PORTD = 1 << 6;
		//PORTD = 0x80;			// Write 10101010b PORTD
		wait( 500 );
		PORTD = 1 << 7;			// Write 01010101b PORTD
		wait( 500 );
	}
};

void opdrB3()
{
	// set PORTD for output
	DDRD = 0b01111111;					// PORTD.7 input all other bits output
	PORTC = 0x10;						// ??
	
	while (1)
	{
		if (PINC & 0x01)
		{
			PORTD ^= (BIT(7) | BIT(6))			// write 1 to all the bits of PortD
		}
	}
};



int main (void)
{
	opdrB3();

	return 1;
}
