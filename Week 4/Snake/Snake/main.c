#include "toolbox.h"
#include <avr/pgmspace.h>
#include "display.h"
#include "gamelogic.h"

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

	return 1;
}