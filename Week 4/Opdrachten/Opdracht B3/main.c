/*
 * Opdracht B3.c
 *
 * Created: 1-3-2018 20:59:48
 * Author : jaapj
 */ 

#include "toolbox.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

void initAdc() {
	// ADC ref. spanning op internal 2.56V ref
	// 'hoge byte gevuld' en ADC0 aanzetten
	ADMUX = 0b11100010;
	
	// enable, start en met freerunning en /64
	ADCSRA = 0b11100110;
}


int main(void)
{
    // Input for D, F
	DDRD = 0x00;
    DDRF = 0x00;
    
    // Output for A, B and C
    DDRA = 0xFF;
    DDRB = 0xFF;
	DDRC = 0xFF;
    
    initAdc();
    init();
	char string[8];
    while (1)
    {	
	    clr_display();
		// temp2 = (temp * 2) + (tempL / 128);
	    sprintf(string, "Temp: %d", ADCH * 2);
	    display_text(string);
	    
		// Show ADCH on leds
		PORTA = ADCH;
		PORTB = ADCL;
	    wait(500);
    }
	return 0;
}

