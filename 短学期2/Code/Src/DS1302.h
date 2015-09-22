#ifndef _DS1302_H__
#define _DS1302_H_

#include "main.h"
void Ds1302Get(void);
void csh1302(void);
extern volatile uchar m, m10, f, f10, s, s10, n, n10, y, y10, r, r10, x, x10;


#endif