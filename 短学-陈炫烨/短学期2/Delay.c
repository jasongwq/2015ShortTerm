#include "delay.h"
unsigned char S1 = 0;
unsigned char S5 = 0;
unsigned char T5 = 0;
void TimeInit()
{
	TH0 = (65536-5000)/256;
	TL0 = (65536-5000)%256;
	TMOD = 0x01;
	ET0=1; EA = 1; TR0 = 1;
}

sbit P3_0 =  P3^0;
void InterTime1() interrupt 1
{
	static unsigned char t1;
	TH0 = (65536-50000)/256;
	TL0 = (65536-50000)%256;
	t1++;T5++;
	if(t1 == 10)
	{
		t1 = 0;
		S1 = !S1;
	}
	if(T5==50)
	{
		T5=0;
		S5=1;
	}
}
void delay_ms(unsigned char i)
{
	unsigned int j;
	for(;i>0;i--)
	for(j=0;j<125;j++)
	{;}
}

void delay(unsigned char n)
{		  
	while(n--) _nop_();
}