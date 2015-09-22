#ifndef __24C08_H__
#define __24C08_H__
#include "reg52.h"
#include "intrins.h"
typedef struct
{
	unsigned char sec,min,hour,day,month,week,year;
	unsigned char n;  
}AlarmData;

sbit SCL = P0^6;
sbit SDA = P0^7;
void i2cinit();
unsigned char* Search2(unsigned char count);
AlarmData Search(unsigned char count);
unsigned char read_add(unsigned char address);
void write_add(unsigned char address,unsigned char date);
unsigned char write_n_add(unsigned char * p,unsigned char address,unsigned char n);
unsigned char read_n_add(unsigned char * p,unsigned char address,unsigned char n);
#endif