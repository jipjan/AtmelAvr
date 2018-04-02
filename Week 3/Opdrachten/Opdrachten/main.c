/*
 * Opdrachten.c
 *
 * Created: 2-4-2018 12:39:12
 * Author : Jaap-Jan
 */ 

#include <avr/io.h>
#include "LCD.h"
#include "toolbox.h"

int main(void)
{
    lcd_init();
	lcd_display_text("test");
	lcd_set_cursor(0);
	
    while (1) 
    {
		wait(500);
    }
}

