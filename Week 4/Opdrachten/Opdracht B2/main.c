/*
 * Opdracht B2.c
 *
 * Created: 1-3-2018 20:37:21
 * Author : jaapj
 */ 

#include "toolbox.h"
#include <avr/io.h>

void initAdc() {
	// ADC ref. spanning op internal 2.56V ref met external capacitor at AREF pin
	// 'hoge byte gevuld' en ADC0 aanzetten
	ADMUX = 0b11100000;
	
	// enable, start en zonder freerunning en /64
	ADCSRA = 0b10000110;
}

int main(void)
{
	// Alle poorten op F naar input voor de adc
	DDRF = 0x00;
	
	// A en B voor het aanzetten van lampjes, dus output van adc
	DDRA = 0xFF;   
	
	initAdc();
	
    while (1) 
    {
		ADCSRA |= BIT(6);
		while (ADCSRA & BIT(6));
		PORTA = ADCH;
		wait (500);
    }
}

