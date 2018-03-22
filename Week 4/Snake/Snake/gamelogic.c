/*
 * gamelogic.c
 *
 * Created: 15-3-2018 13:19:40
 *  Author: jaapj
 */ 

#define UP		0
#define RIGHT	1
#define DOWN

static int snake_length = 2;




void gl_gamestep()
{
	
}

void generateDot ( void ){
	
	uint8_t overlap;
	
	do{
		
		overlap = 0;											/* Assume Not Found */
		
		rdot = (uint8_t) ( rand() % 8 );						/* Generate random points */
		cdot = (uint8_t) ( rand() % 8 );
		
		for( uint8_t i = 0; i < snake_length; i++ ){
			
			if( ( rdot == snakeRow[i] ) && ( cdot == snakeCol[i] ) ){
				overlap = 1;
				break;
			}
		}
		
	} while( overlap );
}