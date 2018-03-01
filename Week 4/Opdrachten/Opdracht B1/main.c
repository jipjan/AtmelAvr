/*
 * Opdracht B1.c
 *
 * Created: 1-3-2018 19:25:47
 * Author : jaapj
 */ 
#include "toolbox.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void initAdc() {
	// ADC ref. spanning op internal 2.56V ref
	// 'hoge byte gevuld' en ADC0 aanzetten
	ADMUX = 0b11100000;
	
	// enable, start en met freerunning en /64
	ADCSRA = 0b11100110;
}

int main(void)
{
	// Alle poorten op F naar input voor de adc
	DDRF = 0x00;
	
	// A en B voor het aanzetten van lampjes, dus output van adc
	DDRA = 0xFF;
	DDRB = 0xFF;
	
	initAdc();
		
	
    while (1) 
    {
		PORTA = ADCL;
		PORTB = ADCH;
		
		wait(100);
    }
}

