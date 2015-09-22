#include "24c08.h"
#include "delay.h"

void i2cinit()//总线初始化
{
 SDA = 1;
 delay(1);
 SCL = 1;
 delay(1);
}
void start()//启动信号
{
 SDA = 1;
 SCL = 1;
 delay(1);
 SDA = 0;
 delay(1);
}
void stop()//停止信号
{
 SDA = 0;
 delay(1);
 SCL = 1;
 delay(1);
 SDA = 1;
 delay(1);
}
void respons()//应答信号
{
 unsigned char i = 0;
 SCL = 1;
 delay(1);
 while(SDA == 1 && i < 255)//等待应答，过一段时间不应答退出循环
  i++;
 SCL = 0;
 delay(1);
}
void writebyte(unsigned char date)//写一个字节
{
 unsigned char i,temp;
 temp = date;
 for(i = 0; i < 8; i++)
 {
  temp <<= 1;//temp左移一位后高位进CY
  SCL = 0;
  delay(1);
  SDA = CY;
  delay(1);
  SCL = 1;
  delay(1);
 } 
 SCL = 0;//应答信号中SCL = 1，所以这里要置0
 delay(1);
 SDA = 1;//用完要释放数据总线
 delay(1);
}
unsigned char readbyte()//读一个字节 
{
 unsigned char i,k;
 SCL = 0;
 delay(1);
 SDA = 1;
 for(i = 0; i < 8; i++)
 {
  SCL = 1; 
  delay(1);
  k = (k << 1) | SDA; //和最低位或，一位位送到K
  SCL = 0;
  delay(1);
 }
 delay(1);
 return k;
}
void write_add(unsigned char address,unsigned char date)//向地址写一个字节数据
{
 start();
 writebyte(0xa0);//A0,A1,A2接地，AT24C02芯片地址为1010，送控制字为1010A2A1A0R/~W
 respons();
 writebyte(address);
 respons();
 writebyte(date);
 respons();
 stop();
}
unsigned char read_add(unsigned char address)//向地址读一个字节数据
{
 unsigned char date;
 start();
 writebyte(0xa0);//A0,A1,A2接地，AT24C02芯片地址为1010，送控制字为1010A2A1A0R/~W
 respons();
 writebyte(address);
 respons();
 start();
 writebyte(0xa1);//A0,A1,A2接地，AT24C02芯片地址为1010，送控制字为1010A2A1A0R/~W
 respons();
 date = readbyte();
 stop();
 return date;
}

//向地址写n个字节数据,数据存放在指针P指的数组中
unsigned char write_n_add(unsigned char * p,unsigned char address,unsigned char n)
{
	 unsigned char i;
	 for(i = 0; i < n; i++)
	 {
		  write_add((address + i),*(p + i));
		  //write_add(address++,*(p + i));
		  delay_ms(20);//一定要适当延时，不然写不进去
	 }
	 return  (address + i);
}
//向地址读n个字节数据,数据存放在指针P指的数组中
unsigned char read_n_add(unsigned char * p,unsigned char address,unsigned char n)
{
 unsigned char i;
 for(i = 0; i < n; i++)
 {
  *(p + i) = read_add(address + i);
 // *(p + i) = read_add(address++);
  
 }
 return  (address + i);
}

AlarmData Search(unsigned char count)
{
	AlarmData alarmdata;
	read_n_add((unsigned char *)&alarmdata, (count)*9, 9);		 
	return alarmdata;
}

unsigned char* Search2(unsigned char count)
{
	unsigned char dat[8];
	read_n_add(dat, (count-1)*8+1, 8);		 
	return dat;
}
