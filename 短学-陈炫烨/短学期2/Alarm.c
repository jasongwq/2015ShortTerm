#include "alarm.h"
#include "key.h"
#include "24c08.h"
#include "mian.h"
#include "delay.h"



uchar AlarmCnt;
/******************报警列表*********************/
void AlarmList(uchar key)
{
	static uchar  count, n;
	static idata uchar dat[8];
	if (key == KEY_ENTER)
	{
		n = count = read_add(0);
		read_n_add(dat, (n - 1) * 8 + 1, 8);
	}
	else if (key == KEY_UP)
	{
		if (n++ == count)n = 1;
		read_n_add(dat, (n - 1) * 8 + 1, 8);
	}
	else if (key == KEY_DOWN)
	{
		if (n-- == 1) n = count;
		read_n_add(dat, (n - 1) * 8 + 1, 8);
	}
	else if (key == KEY_5) AlarmCnt = 0;
	DS1302_SMG_display(n / 10 * 16 + n % 10, dat[0], dat[1], dat[2], dat[3], dat[4], dat[7]);
}
/******************报警检测*********************/
uchar AlarmMonitor()
{
	uchar n = 0;
	if (!P1_4) {P3_0 = 0; return 1;}
	if (!P1_5) {P3_1 = 0; return 2;}
	if (!P1_6) {P3_2 = 0; return 3;}
	if (!P1_7) {P3_3 = 0; return 4;}
	return 0;
}
/******************报警保存*********************/
void Alarm_Save(uchar n, Tim tim)
{
	static uchar address = 1;
	idata uchar dat[8];
	dat[0] = tim.year;
	dat[1] = tim.month;
	dat[2] = tim.day;
	dat[3] = tim.hour;
	dat[4] = tim.min;
	dat[5] = tim.sec;
	dat[6] = tim.week;
	dat[7] = n;
	write_add(0, ++AlarmCnt);
	delay_ms(20);
	address = write_n_add(dat, address, 8);
}