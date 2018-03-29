#include "toolbox.h"
#include <avr/pgmspace.h>
//#include <avr/interrupt.h>
#include "display.h"
#include "gamelogic.h"

/*
ISR(INT0_vect)
{
	gl_change_direction(LEFT);
}

ISR(INT1_vect)
{
	gl_change_direction(RIGHT);
}

ISR(INT2_vect)
{
	gl_change_direction(UP);
}

ISR(INT3_vect)
{
	gl_change_direction(DOWN);
}
*/

int main( void )
{
	displayInit();	
	displayClr();
	display();
	
	/*
	DDRB = 0xff;
		
	EICRA = 0b11111111;			// INT1 falling edge, INT2 rising edge
	EIMSK = 0b1111;			// Enable INT1 & INT2
		
	sei();
	*/
	
	gl_restart();
	
	DDRB = 0xFF;
	DDRA = 0xFF;	
	
	while(1) {
		wait(500);
		if (PINA & BIT(5))
			gl_change_direction(RIGHT);
		else if (PINA & BIT(6))
			gl_change_direction(DOWN);
		else if (PINA & BIT(7))
			gl_change_direction(LEFT);
		else if (PINB & BIT(6))
			gl_change_direction(UP);
		
		gl_gamestep();
	}

	return 1;
}