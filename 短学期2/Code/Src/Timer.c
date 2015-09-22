#include "DigitalTube.h"

#define T0_TH0 0xF8
#define T0_TL0 0xCD
void Timer0Init(void)		//200΢��@11.0592MHz
{
	TMOD |= 0x01;
	TH0 = T0_TH0;
	TL0 = T0_TL0;
	ET0 = 1; //����ʱ�ж�����
	TR0 = 1;//������ʱ��0
	EA = 1; //�����ж�
}


void t0(void) interrupt 1 using 0 //��ʱ�жϷ�����
{
	static tim = 0; //ʱ�����
	int Tim80ms = 0;
	TH0 = T0_TH0;    //�������¸�ֵ�����ö�ʱ��ѭ������
	TL0 = T0_TL0;
	tim++;
	if (tim > 0)
	{
		tim = 0;
		Tim80ms=1;
	}
}
