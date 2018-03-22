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

int * generateDot (int snake_c, int snake_r ){
	
	static int dots[2];
	
	int overlap = 0;
	
	do{
		
		overlap = 0;										   
												//dots[0] = collumn
												//dots[1] = row
		dots[0] = rand() % 8;					//Generate points
		dots[1] = rand() % 8;
			
		if( snake_c == dots[0] || snake_r == dots[1] )
		{
			overlap = 1;
			break;
		}
		
	} while( overlap );
	
	return dots;
}