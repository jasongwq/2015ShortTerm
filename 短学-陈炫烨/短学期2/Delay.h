#ifndef __DELAY_H__
#define __DELAY_H__

#include "reg52.h"
#include "intrins.h"

void TimeInit();
void delay_ms(unsigned char i);
void delay(unsigned char n);
extern unsigned char S1;
extern unsigned char S5;
extern unsigned char T5;
#endif


