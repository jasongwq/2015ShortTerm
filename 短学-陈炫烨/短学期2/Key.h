#ifndef __KEY_H__
#define __KEY_H__
#include "reg52.h"
#include "intrins.h"

#define KEY_FN    0x21
#define KEY_UP    0x22
#define KEY_ESC   0x24

#define KEY_RIGHT 0x11
#define KEY_5     0x12
#define KEY_LEFT  0x14

#define KEY_ENTER 0x09
#define KEY_DOWN  0x0a
#define KEY_7     0x0c

unsigned char KeyGet();
#endif