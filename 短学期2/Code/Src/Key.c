#include "key.h"

#define P0G (P0 & 0x3f)
#define P0S(x) ((P0 & 0xc0) | (x))
#define XY(x,y) ((x<<3)|(y))
uchar KeyGet ()	//取键值函数
{
	unsigned char X, Y, Z;
	P0 = P0S(0x07); //先对P3 置数 行扫描
	if (P0G != 0x07) //判断是否有键按下
	{
		//delay10ms(); //延时,软件去干扰
		if (P0G != 0x07) //确认按键按下
		{
			X = P0G; //保存行扫描时有键按下时状态
			P0 = P0S(0x38); //列扫描
			Y = P0G;  //保存列扫描时有键按下时状态
			Z = X | Y; //取出键值
			/*********************************************************************/
			switch ( Z ) //判断键值（那一个键按下）
			{
			case XY(6,6): return 1; //对键值赋值
			case XY(6,5): return 2;
			case XY(6,3): return 3;
			case XY(5,6): return 4;
			case XY(5,5): return 5;
			case XY(5,3): return 6;
			case XY(3,6): return 7;
			case XY(3,5): return 8;
			case XY(3,3): return 9;
			default:
				return 0;
			}
		}
	}

	return 0;
}