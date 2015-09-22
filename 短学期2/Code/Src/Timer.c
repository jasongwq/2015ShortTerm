#include "DigitalTube.h"

#define T0_TH0 0xF8
#define T0_TL0 0xCD
void Timer0Init(void)		//200微秒@11.0592MHz
{
	TMOD |= 0x01;
	TH0 = T0_TH0;
	TL0 = T0_TL0;
	ET0 = 1; //开定时中断允许
	TR0 = 1;//启动定时器0
	EA = 1; //开总中断
}


void t0(void) interrupt 1 using 0 //定时中断服务函数
{
	static tim = 0; //时间计数
	int Tim80ms = 0;
	TH0 = T0_TH0;    //必须重新赋值才能让定时器循环工作
	TL0 = T0_TL0;
	tim++;
	if (tim > 0)
	{
		tim = 0;
		Tim80ms=1;
	}
}
