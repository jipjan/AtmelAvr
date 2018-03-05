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
	ADMUX = 0b11100000;
	
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
	
    while (1)
    {
	    // Show ADCH on leds
	    PORTA = ADCH;
		
	    clr_display();
	    char string[16];
	    int temp = ADCH;
	    sprintf(string, "Temp: 0x%.2X", temp);
	    display_text(string);
	    
	    wait(100);
    }
}

