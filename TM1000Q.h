#ifndef TM1000Q_H_INCLUDED
#define TM1000Q_H_INCLUDED

#include <util/delay.h>
#include <avr/io.h>

#define north	PD3		//North/South tilt switch
#define south	PD2

#define east	PD6		//East/West tilt switch
#define west	PD5
						//Directional indicator light assignments
#define nLight	PB5		//Red
#define sLight	PB4		//Blue
#define eLight	PB3		//Yellow
#define wLight	PB2		//Green

#endif