#include "24c08.h"
#include "delay.h"

void i2cinit()//���߳�ʼ��
{
 SDA = 1;
 delay(1);
 SCL = 1;
 delay(1);
}
void start()//�����ź�
{
 SDA = 1;
 SCL = 1;
 delay(1);
 SDA = 0;
 delay(1);
}
void stop()//ֹͣ�ź�
{
 SDA = 0;
 delay(1);
 SCL = 1;
 delay(1);
 SDA = 1;
 delay(1);
}
void respons()//Ӧ���ź�
{
 unsigned char i = 0;
 SCL = 1;
 delay(1);
 while(SDA == 1 && i < 255)//�ȴ�Ӧ�𣬹�һ��ʱ�䲻Ӧ���˳�ѭ��
  i++;
 SCL = 0;
 delay(1);
}
void writebyte(unsigned char date)//дһ���ֽ�
{
 unsigned char i,temp;
 temp = date;
 for(i = 0; i < 8; i++)
 {
  temp <<= 1;//temp����һλ���λ��CY
  SCL = 0;
  delay(1);
  SDA = CY;
  delay(1);
  SCL = 1;
  delay(1);
 } 
 SCL = 0;//Ӧ���ź���SCL = 1����������Ҫ��0
 delay(1);
 SDA = 1;//����Ҫ�ͷ���������
 delay(1);
}
unsigned char readbyte()//��һ���ֽ� 
{
 unsigned char i,k;
 SCL = 0;
 delay(1);
 SDA = 1;
 for(i = 0; i < 8; i++)
 {
  SCL = 1; 
  delay(1);
  k = (k << 1) | SDA; //�����λ��һλλ�͵�K
  SCL = 0;
  delay(1);
 }
 delay(1);
 return k;
}
void write_add(unsigned char address,unsigned char date)//���ַдһ���ֽ�����
{
 start();
 writebyte(0xa0);//A0,A1,A2�ӵأ�AT24C02оƬ��ַΪ1010���Ϳ�����Ϊ1010A2A1A0R/~W
 respons();
 writebyte(address);
 respons();
 writebyte(date);
 respons();
 stop();
}
unsigned char read_add(unsigned char address)//���ַ��һ���ֽ�����
{
 unsigned char date;
 start();
 writebyte(0xa0);//A0,A1,A2�ӵأ�AT24C02оƬ��ַΪ1010���Ϳ�����Ϊ1010A2A1A0R/~W
 respons();
 writebyte(address);
 respons();
 start();
 writebyte(0xa1);//A0,A1,A2�ӵأ�AT24C02оƬ��ַΪ1010���Ϳ�����Ϊ1010A2A1A0R/~W
 respons();
 date = readbyte();
 stop();
 return date;
}

//���ַдn���ֽ�����,���ݴ����ָ��Pָ��������
unsigned char write_n_add(unsigned char * p,unsigned char address,unsigned char n)
{
	 unsigned char i;
	 for(i = 0; i < n; i++)
	 {
		  write_add((address + i),*(p + i));
		  //write_add(address++,*(p + i));
		  delay_ms(20);//һ��Ҫ�ʵ���ʱ����Ȼд����ȥ
	 }
	 return  (address + i);
}
//���ַ��n���ֽ�����,���ݴ����ָ��Pָ��������
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
