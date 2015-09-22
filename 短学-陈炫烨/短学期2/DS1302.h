#ifndef __DS1302_H__
#define __DS1302_H__
#include "reg52.h"
#include "intrins.h"
#include "mian.h"

sbit ACC_0 = ACC^0;
sbit ACC_1 = ACC^1;
sbit ACC_2 = ACC^2;
sbit ACC_3 = ACC^3;
sbit ACC_4 = ACC^4;
sbit ACC_5 = ACC^5;
sbit ACC_6 = ACC^6;
sbit ACC_7 = ACC^7; 
//**************************
sbit T_SCLK = P3^6;                    // DS1302时钟信号       7脚
sbit T_DIO= P3^7;                      // DS1302数据信号       6脚
sbit T_CE = P3^5;
//**************************
typedef struct
{
	uchar sec,min,hour,day,month,week,year;    //时间变量

}Tim;
void DS1302_Write( uchar sec_w,min_w,hour_w,day_w,month_w,week_w,year_w );
Tim DS1302_readtime();
uchar DS1302_RTC_Seting(uchar key);
void DS1302_SMG_display(uchar dat0,dat1,dat2,dat3,dat4,dat5,dat6);
void DS1302_SMG_display_ex(uchar wela);
void SMG_display(uchar wela, uchar n);
#endif
