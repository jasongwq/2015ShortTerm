#include < reg52.h>
#include "mian.h"
#include "delay.h"
#include "key.h"
#include "ds1302.h"
#include "24c08.h"
#include "alarm.h"
#include "display.h"



void main()
{
	TimeInit();
	DS1302_Write(7, 0x13, 1, 0x20, 0x09, 0x04, 0x15);
	while (1)
	{
		uchar key;
		static uchar  fn1, fn2, esc = 1, alarm, n, alarmNum, enter;
		static Tim tim;
		/******************报警检测*********************/
		if (n = AlarmMonitor())
		{
			alarm = 1;
			esc = 0;
			T5 = 0;
			alarmNum = n;
			tim = DS1302_readtime();
			Alarm_Save(alarmNum, tim);
		}
		/******************按键扫描*********************/
		key = KeyGet();
		/******************功能*********************/
		if (key == KEY_FN)
		{
			esc = 0;
			fn1 = !fn1;
			fn2 = !fn1;
		}
		if (key == KEY_ESC)
		{
			esc = 1;
			alarm = 0;
			enter = 0;
			fn1 = 0;
			fn2 = 0;
		}
		if (key == KEY_ENTER)
		{
			enter = 1;
		}
		if (esc)
		{
			DS1302_readtime();
			DS1302_SMG_display_ex(13);
		}
		else
		{
			/*****报警检测状态*****/
			if (alarm)
			{
				if (S5)
				{
					S5 = 0;
					alarm = 0;
					esc = 1;
				}
				DS1302_SMG_display(0x20, tim.year, tim.month, tim.day, tim.hour, tim.min, alarmNum);
			}
			/*****F1功能*****/
			else if (fn1)
			{
				if (!enter)
				{
					DisF(1);/*显示F1*/
				}
				else if (!DS1302_RTC_Seting(key)) 
				{
					esc = 1;
					enter = 0;
					fn1 = 0;
					fn2 = 0;
				}
			}
			/*****F2功能*****/
			else if (fn2)
			{
				if (!enter)
				{
					DisF(2);/*显示F2*/
				}
				else
					AlarmList(key);
			}
		}
	}
}
