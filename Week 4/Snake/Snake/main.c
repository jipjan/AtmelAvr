#include "toolbox.h"
#include <avr/pgmspace.h>
#include "display.h"

int main( void )
{
	displayInit();	
	displayClr();
	display();
	displaySetPixel(5, 3);
	display();
	wait(500);
	displayClrPixel(5,3);
	display();
	/*
	while(true) {
		displayClr();
		wait(500);
		displaySetPixel(0, 0);
		display();
		wait(500);
	}
	*/

	return 1;
}