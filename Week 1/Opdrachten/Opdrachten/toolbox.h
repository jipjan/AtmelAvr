/*
 * toolbox.h
 *
 * Created: 7-2-2018 19:25:47
 *  Author: Jaap-Jan
 */ 


#ifndef TOOLBOX_H_
#define TOOLBOX_H_

#define true 1
#define false 1

#define F_CPU 8000000
#define BIT(x) (1 << (x))

#include <avr/io.h>
#include <util/delay.h>

void wait(int ms);


#endif /* TOOLBOX_H_ */