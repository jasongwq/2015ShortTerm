#include "ds1302.h"
#include "delay.h"
#include "key.h"
code uchar seg7code[12] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x8e, 0xff};	 //所需的段的位码
code uchar wei[13] = {0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc}; //位的控制端

uchar   sec, min, hour, day, month, week, year; //时间变量
uchar 	secH, secL, minH, minL, hourH, hourL, dayH, dayL, monthH, monthL, week, yearH, yearL;
//**************************
uchar DS1302_RTC_Seting(uchar key)
{
	static uchar wela;
	if (key == KEY_RIGHT)
	{
		if (wela == 12)
		{
			wela = 0;
		}
		else
		{
			wela++;
		}
	}
	else if (key == KEY_LEFT)
	{
		if (wela == 0)
		{
			wela = 12;
		}
		else
		{
			wela--;
		}
	}
	else if (key == KEY_UP)
	{
		switch (wela)
		{
		case 12: if (week++ == 7) week = 0 ; break;
		case 11: if (minL++ == 9) minL = 0 ; break;
		case 10: if (minH++ == 6) minH = 0 ; break;
		case 9: if (hourL++ == 9) hourL = 0; break;
		case 8: if (hourH++ == 6) hourH = 0; break;
		case 7: if (dayL++ == 9) dayL = 0 ; break;
		case 6: if (dayH++ == 3) dayH = 0 ; break;
		case 5: if (monthL++ == 9) monthL = 0 ; break;
		case 4: if (monthH++ == 1) monthH = 0 ; break;
		case 3: if (yearL++ == 9) yearL = 0 ; break;
		case 2: if (yearH++ == 9) yearH = 0 ; break;
		case 1:  break;
		case 0:  break;
		default: break;
		}
	}
	else if (key == KEY_DOWN)
	{
		switch (wela)
		{
		case 12: if (week-- == 0) week = 7; break;
		case 11: if (minL-- == 0) minL = 9; break;
		case 10: if (minH-- == 0) minH = 6; break;
		case 9: if (hourL-- == 0) hourL = 9; break;
		case 8: if (hourH-- == 0) hourL = 6; break;
		case 7: if (dayL-- == 0) dayL = 9; break;
		case 6: if (dayH-- == 0) dayH = 3; break;
		case 5: if (monthL-- == 0) monthL = 9; break;
		case 4: if (monthH-- == 0) monthL = 1; break;
		case 3: if (yearL-- == 0) yearL = 9; break;
		case 2: if (yearH-- == 0) yearH = 9; break;
		default: break;
		}
	}
	else if (key == KEY_ENTER)
	{	static uchar n;
		n = !n;
		sec = secH << 4 | secL;
		min = minH << 4 | minL;
		hour = hourH << 4 | hourL;
		day = dayH << 4 | dayL;
		month = monthH << 4 | monthL;
		year = yearH << 4 | yearL;
		DS1302_Write(sec, min, hour, day, month, week, year);
		if (!n) return 0;
	}
	if (minH * 10 + minL > 60)
	{
		minH = 6;
		minL = 0;
	}
	if (hourH * 10 + hourL > 60)
	{
		hourH = 6;
		hourL = 0;
	}
	if (monthH * 10 + monthL > 12)
	{
		monthH = 1;
		monthL = 2;
	}
	if (dayH * 10 + dayL > 31)
	{
		dayH = 3;
		dayL = 1;
	}
	DS1302_SMG_display_ex(wela);
	return 1;
}

uchar  DS1302_addr[] = {
	0x80, //0,写入秒(Second)寄存器
	0x81, //1,读出秒(Second)寄存器
	0x8a, //10,写入周(Week)寄存器
	0x8b, //11,读出周(Week)寄存器
	0x82, //2,写入分(Minute)寄存器
	0x83, //3,读出分(Minute)寄存器
	0x84, //4,写入小时(Hour)寄存器
	0x85, //5,读出小时(Hour)寄存器
	0x86, //6,写入日(Day)寄存器
	0x87, //7,读出日(Day)寄存器
	0x88, //8,写入月份(Month)寄存器
	0x89, //9,读出月份(Month)寄存器
	0x8c, //12,写入年份(Year)寄存器
	0x8d, //13,读出年份(Year)寄存器
	0x8e, //14,写保护_寄存器
	0x8f  //15,涓流充电

}  ;

void SMG_display(uchar wela, uchar n)
{
	P1 = 0XFF;
	P2 = seg7code[n];
	P1 = wei[wela];
	delay(10);
}
//***************写入一字节***********************
void DS1302_Input_Byte(uchar Input)  //向时钟IC写入一字节
{
	uchar i;
	ACC = Input;
	for (i = 8; i > 0; i--)
	{
		T_DIO = ACC_0;            //相当于汇编中的 RRC
		T_SCLK = 1;
		T_SCLK = 0;
		ACC = ACC >> 1;
	}
}
//**************读取一字节()*************************
uchar DS1302_Output_Byte(void)      //从时钟IC读取一字节()
{
	uchar i;
	for (i = 8; i > 0; i--)
	{
		ACC >>= 1; T_DIO = 1;
		ACC_7 = T_DIO;
		T_SCLK = 1;                 //相当于汇编中的 RRC
		T_SCLK = 0;
	}
	return (ACC);
}
//**************向时钟IC写数据*************************
void DS1302_Write_one( uchar addr, dat )      // 写入地址、数据子程序
{
	T_CE = 0;                           //T_CE引脚为低，数据传送中止
	T_SCLK = 0;                        //清零时钟总线
	T_CE = 1;                          //T_CE引脚为高，逻辑控制有效
	DS1302_Input_Byte(addr);           // 地址，命令
	DS1302_Input_Byte(dat);          // 写1Byte数据
	T_SCLK = 1;
	T_CE = 0;
}
//************从数据读取数据*****************************
uchar DS1302_Read ( uchar addr )    //数据读取子程序
{
	uchar date;
	T_CE = 0;
	T_SCLK = 0;
	T_CE = 1;
	DS1302_Input_Byte(addr);        // 地址，命令
	date = DS1302_Output_Byte();         // 读1Byte数据
	T_SCLK = 1;
	T_CE = 0;
	return (date);
}
//************从数据读取数据****************************
void DS1302_Write( uchar sec_w, min_w, hour_w, day_w, month_w, week_w, year_w )
{
	DS1302_Write_one(0x8e, 0x00);
	DS1302_Write_one(0x80, sec_w);
	DS1302_Write_one(0x82, min_w);
	DS1302_Write_one(0x84, hour_w);
	DS1302_Write_one(0x86, day_w);
	DS1302_Write_one(0x88, month_w);
	DS1302_Write_one(0x8a, week_w);
	DS1302_Write_one(0x8c, year_w);
	DS1302_Write_one(0x8e, 0x80);
}

//************从数据读取数据*****************************
//void DS1302_readtime_ex(uchar* )
//{
//
//}

Tim DS1302_readtime()
{
	Tim timdat;
	sec = DS1302_Read(0x81);                  //读秒
	secH = sec >> 4;
	secL = sec & 0x0f;
	min = DS1302_Read(0x83);                  //读分
	minH = min >> 4;
	minL = min & 0x0f;
	hour = DS1302_Read(0x85);                 //读时
	hourH = hour >> 4;
	hourL = hour & 0x0f;
	day = DS1302_Read(0x87);                  //读日
	dayH = day >> 4;
	dayL = day & 0x0f;
	month = DS1302_Read(0x89);                //读月
	monthH = month >> 4;
	monthL = month & 0x0f;
	year = DS1302_Read(0x8d);   //读年
	yearH = year >> 4;
	yearL = year & 0x0f;
	week = DS1302_Read(0x8b);    //读星期
	timdat.sec = sec;
	timdat.min = min;
	timdat.hour = hour;
	timdat.day = day;
	timdat.month = month;
	timdat.year = year;
	timdat.week = week;
	return timdat;
}
//************数码管DS1302显示*****************************
void DS1302_SMG_display_ex(uchar wela)
{
	static uchar s1;
	s1 = S1;
	if (wela == 12 && s1) {SMG_display(12, 11);}
	else SMG_display(12, week);
	if (wela == 11 && s1) {SMG_display(11, 11);}
	else  SMG_display(11, minL);
	if (wela == 10 && s1) {SMG_display(10, 11);}
	else SMG_display(10, minH);
	if (wela == 9 && s1) {SMG_display(9, 11);}
	else SMG_display(9, hourL);
	if (wela == 8 && s1) {SMG_display(8, 11);}
	else SMG_display(8, hourH);
	if (wela == 7 && s1) {SMG_display(7, 11);}
	else SMG_display(7, dayL);
	if (wela == 6 && s1) {SMG_display(6, 11);}
	else SMG_display(6, dayH);
	if (wela == 5 && s1) {SMG_display(5, 11);}
	else SMG_display(5, monthL);
	if (wela == 4 && s1) {SMG_display(4, 11);}
	else SMG_display(4, monthH);
	if (wela == 3 && s1) {SMG_display(3, 11);}
	else SMG_display(3, yearL);
	if (wela == 2 && s1) {SMG_display(2, 11);}
	else SMG_display(2, yearH);
	if (wela == 1 && s1) {SMG_display(1, 11);}
	else SMG_display(1, 0);
	if (wela == 0 && s1) {SMG_display(0, 11);}
	else SMG_display(0, 2);
}
void DS1302_SMG_display(uchar dat0, dat1, dat2, dat3, dat4, dat5, dat6)
{
	SMG_display(12, dat6);
	SMG_display(11, dat5 % 0x10);
	SMG_display(10, dat5 / 0x10);
	SMG_display(9, dat4 % 0x10);
	SMG_display(8, dat4 / 0x10);
	SMG_display(7, dat3 % 0x10);
	SMG_display(6, dat3 / 0x10);
	SMG_display(5, dat2 % 0x10);
	SMG_display(4, dat2 / 0x10);
	SMG_display(3, dat1 % 0x10);
	SMG_display(2, dat1 / 0x10);
	SMG_display(1, dat0 % 0x10);
	SMG_display(0, dat0 / 0x10);
}
