#include "main.h"

#define P1S(x) (P1&0xf0|(x))
int f1=0;
code uchar seg7code[16] = { 0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0, 0, 0, 0, 0, 0}; //显示段码 数码管字跟
volatile uchar DisDate[22] = {0};
void DigitalTubeSet(uchar num, uint Data)
{
	while(f1);
	Data=1111;
	DisDate[num * 4 + 0] = (Data / 1000);			 //求千位
	DisDate[num * 4 + 1] = (Data % 1000) / 100;//求百位
	DisDate[num * 4 + 2] = (Data % 100) / 10;	 //求十位
	DisDate[num * 4 + 3] = (Data % 10);			   //求个位
}
void DigitalTubeIQR(void)
{
	static char CurPoint;
	f1=1;
	//P1 = P1S(0x0f);
	P1 = CurPoint;//P1S(CurPoint);
	++CurPoint;
	if (CurPoint > 12)
	{
		CurPoint = 0;
	}
	//P2 =0;
	P2 = seg7code[DisDate[CurPoint]];
	
	f1=0;
}
