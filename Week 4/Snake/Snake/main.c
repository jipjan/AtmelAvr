/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** ledmatrix.c
**
** Beschrijving:	Simple HT16K33 Ledmatix demo.
** Target:			AVR mcu
** Build:			avr-gcc -std=c99 -Wall -O3 -mmcu=atmega128 -D F_CPU=8000000UL -c ledmatrix.c
**					avr-gcc -g -mmcu=atmega128 -o ledmatrix.elf ledmatrix.o
**					avr-objcopy -O ihex ledmatrix.elf ledmatrix.hex 
**					or type 'make'
** Program:			avrdude.exe" -c usbasp -p m168 -U flash:w:LedMatrixToBb.hex
** Author: 			dkroeske@gmail.com
** -------------------------------------------------------------------------*/

#include "toolbox.h"
#include <avr/pgmspace.h>
#include "display.h"


/******************************************************************/
int main( void )
/* 
short:			main() loop, entry point of executable
inputs:			
outputs:	
notes:			Looping forever, trashing the HT16K33
Version :    	DMK, Initial code
*******************************************************************/
{
	displayInit();
	wait(500);

	displayChar('1', 0, 0);
	display();
	
	while(1==1) {

	}

	return 1;
}