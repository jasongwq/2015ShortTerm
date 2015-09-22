#include "alarm.h"

sbit AlarmSrc1=P1 ^ 4;
sbit AlarmSrc2=P1 ^ 5;
sbit AlarmSrc3=P1 ^ 6;
sbit AlarmSrc4=P1 ^ 7;


uchar AlarmGet(void)
{
	
	if(0==AlarmSrc1)return 1;
	if(0==AlarmSrc2)return 2;
	if(0==AlarmSrc3)return 3;
	if(0==AlarmSrc4)return 4;
	return 0;
}