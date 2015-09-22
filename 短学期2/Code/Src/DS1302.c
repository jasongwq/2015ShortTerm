#include "reg52.h"
#include "stdio.h"
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
//д��ʱ���ǵ͵�ƽ�ı����ݣ���������������
//����ʱ���ǵ͵�ƽ�������ݣ��½���ʹ�ô��豸�����ݷŵ�������
//����ʱ���ǵ͵�ƽ������û�ж������ṩ�½���ʹ�ô��豸�����ݷŵ�������

sbit P11 = P1 ^ 1;	//��ʱ��ʱ���л�
sbit P12 = P1 ^ 2;	//ʱ����
sbit P13 = P1 ^ 3;	//�ֵ���
sbit P14 = P1 ^ 4;	//�����

sbit CLK = P3 ^ 6;
sbit IO  = P3 ^ 7;
sbit RST = P3 ^ 5;

volatile uchar m, m10, f, f10, s, s10, n, n10, y, y10, r, r10, x, x10;

/////////////////////DS1302////////////////////////
//--------------WriteOneByteData-----------------/
void WriteByte(uchar ucda)
{
	uchar i;
	for (i = 8; i > 0; i--)
	{
		IO = (bit)(ucda & 0x01);
		CLK = 1;
		CLK = 0;
		ucda >>= 1;
	}
}

//--------------ReadOneByteData-----------------/
uchar ReadByte(void)
{
	uchar i, a;
	for (i = 8; i > 0; i--)
	{
		a >>= 1;
		if (IO)a |= 0x80;
		CLK = 1;
		CLK = 0;
	}
	return (a);
}
//--------------WriteAddrFist,ThenWriteData-----------------/

void write1302(uchar Addr, uchar Data)
{
	RST = 0;
	CLK = 0;
	RST = 1;
	WriteByte(Addr);
	WriteByte(Data);
	CLK = 1;
	RST = 0;
}

//--------------WriteAddrFirst,ThenReadData-----------------/

uchar read1302(uchar Addr)
{
	uchar Data;
	RST = 0;
	CLK = 0;
	RST = 1;
	WriteByte(Addr);
	Data = ReadByte();
	CLK = 1;
	RST = 0;
	return (Data);
}


/************************************************************************/
////////////////ds1302��ʼ��//////////////////����ʱ��ʱ��
void csh1302(void)
{
	CLK = 0;
	RST = 0;
	write1302(0x8e, 0x00); //��д����
	write1302(0x90, 0x06); //��ֹ���
/////////////////////////////////////////////////
	write1302(0x80, 0x20); //Ԥ����
	write1302(0x82, 0x30); //Ԥ�÷�
	write1302(0x84, 0x08); //Ԥ��ʱ
	write1302(0x86, 0x17); //Ԥ������
	write1302(0x88, 0x07); //Ԥ����
	//write1302(0x8a,0x02);//Ԥ������
	write1302(0x8c, 0x08); //Ԥ����
////////////////////////////////////////////////
	write1302(0x80, 0x00); //����ʱ��
	write1302(0x8e, 0x80); //�ر�д����
}
/************************************************************************/
//////////////////��ʾ����////////////////////////////
void Ds1302Get(void)
{
	////////////////////////////////////
	n10 = read1302(0x8c);			 //��
	n = read1302(0x8c) & 0x0f;
	n10 = n10 >> 4;
	n10 = n10 & 0x07;


	x = read1302(0x8a) % 0x07;//����
	
	////////////////////////////////////
	y10 = read1302(0x89);			//��
	y = read1302(0x89) & 0x0f;
	y10 = y10 >> 4;
	y10 = y10 & 0x07;
	////////////////////////////////////
	r10 = read1302(0x87);			 //��
	r = read1302(0x87) & 0x0f;
	r10 = r10 >> 4;
	r10 = r10 & 0x07;

	s10 = read1302(0x85);
	s = read1302(0x85) & 0x0f;		//ʱ
	s10 = s10 >> 4;
	s10 = s10 & 0x07;
	////////////////////////////////////
	f10 = read1302(0x83);			//��
	f = read1302(0x83) & 0x0f;
	f10 = f10 >> 4;
	f10 = f10 & 0x07;
	////////////////////////////////////
	m10 = read1302(0x81);			 //��
	m = read1302(0x81) & 0x0f;
	m10 = m10 >> 4;
	m10 = m10 & 0x07;
}


