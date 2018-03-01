/*
 * toolbox.c
 *
 * Created: 7-2-2018 19:24:10
 *  Author: Jaap-Jan
 */ 
#include "toolbox.h"

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}