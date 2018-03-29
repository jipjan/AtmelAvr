/*
 * segment.h
 *
 * Created: 29-3-2018 22:23:44
 *  Author: jaapj
 */ 


#ifndef SEGMENT_H_
#define SEGMENT_H_

void spi_masterInit();
void displayDriverInit();
void spi_slaveSelect(unsigned char);
void emptyDisplay();
void writeLedDisplay(int value);

#endif /* SEGMENT_H_ */