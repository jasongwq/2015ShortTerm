#include "Timer.h"
#include "DS1302.h"
#include "24C08.h"
#include "DigitalTube.h"
#include "key.h"
#include "alarm.h"



void Init(void)
{
	Timer0Init();
	csh1302();
	x24c08_init();
	x24c08_write(2, 1);
	x24c08_read(2);
	
}
int main(void)
{
	Init();
	Timer0Init();
	delay(255);

	for (;;)
	{
		if()
				DigitalTubeIQR();
//		delay(255);
//		DigitalTubeSet(0,2013);
//		DigitalTubeSet(1,2013);
//		DigitalTubeSet(2,2013);
//		DigitalTubeSet(3,2013);
		
//		delay(255);
//		DigitalTubeSet(1,2013);
//		delay(255);
//		DigitalTubeSet(2,2013);
//		delay(255);
//		DigitalTubeSet(3,2013);
		
//		DigitalTubeSet(0, 2000);
//		DigitalTubeSet(1, y10 * 1000 + y * 100 + r10 * 10 + r);
//		DigitalTubeSet(2, s10 * 1000 + s * 100 + f10 * 10 + f);
//		
		//Ds1302Get();
//		KeyGet();
//		DigitalTubeSet(3, ((uint)AlarmGet())*1000);
	}
	return;
}
void delay(uchar t)
{
	uchar i, j;
	for (i = 0; i < t; i++)
	{
		for (j = 13; j > 0; j--);
		{	;
		}
	}
}


