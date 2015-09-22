#ifndef _24C08_H_
#define _24C08_H_
#include "main.h"

void x24c08_init(void); //³õÊ¼»¯24C08
void x24c08_write(unsigned char address, unsigned char info);
unsigned char x24c08_read(unsigned char address);

#endif

