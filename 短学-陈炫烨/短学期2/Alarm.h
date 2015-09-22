#ifndef __ALARM_H__
#define __ALARM_H__
#include "mian.h"
#include "ds1302.h"

uchar AlarmMonitor(void);
void Alarm_Save(uchar n,Tim tim);
void AlarmList(uchar key);

#endif


