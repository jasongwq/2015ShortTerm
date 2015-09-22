#include "display.h"
#include "mian.h"
#include "ds1302.h"

void DisF(uchar n)
{
					SMG_display(0, 11);
					SMG_display(10, 10);
					SMG_display(11, n);
}