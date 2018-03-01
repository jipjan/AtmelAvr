#define F_CPU 8000000

#include <avr/io.h>
#include <avr/delay.h>
#include <string.h>
#include "LCD.h"

static char zin[] = "Ik hou van pannenkoeken en ook van stroop";
static char scrolltxt[] = "Aantal keer gedrukt: ";
int counter = 0;
int overflowCount = 0;

int main(void)
{
		DDRB = 0xFF;
		DDRC = 0xFF;
		DDRD = 0xFF;
		
		TCNT2 = 0;
		
		// Compare value
		OCR2 = 125;
		
		// Enable de interrupts
		TIMSK |= (1 << 7);
		
		SREG |= (1 << 7);
		
		// Set timer to clock /64
		TCCR2 = 0b00001011;
		sei();

		while (1)
		{
			
		}
}

int mainOpdr1(void)
{
	DDRD = 0xFF;
	DDRC = 0xFF;
	PORTC = 0x00;
	
	init();
	clr_display();
	display_text(zin);
	int length = strlen(zin);
	while (1)
	{
		for(int x = 0; x< length; x++) {
			set_display(1);
			wait(250);
		}
	}
	
	return 0;
}

int mainOpdr2(void)
{
	DDRB = 0xFF;
	DDRD = 0x00;
	DDRC = 0xFF;
	TCNT2 = -1;
	TIMSK |= (1 << 6);
	SREG |= (1 << 7);
	TCCR2 = 0b0000111;  //TCCR2 = 0b0010111;
	
	sei();
	
	PORTC = 0x00;
	
	init();
	clr_display();
	int length = strlen(scrolltxt) + 1;
	while (1)
	{
		for(int x = 0; x< length; x++) {
			PORTB = TCNT2;
			set_display(1);
			wait(250);
		}
	}
	
	return 0;
}

void wait(int ms) {
	for(int x= 0; x < ms; x++) {
		_delay_ms(1);
	}
}

ISR( TIMER2_COMP_vect )
{
	overflowCount++;
	overflowCount = overflowCount % 40;
	if(overflowCount == 0) {
		PORTD = 0b10000000;
		} else if(overflowCount == 15) {
		PORTD = 0b00000000;
	}
}