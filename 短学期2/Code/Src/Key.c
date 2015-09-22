#include "key.h"

#define P0G (P0 & 0x3f)
#define P0S(x) ((P0 & 0xc0) | (x))
#define XY(x,y) ((x<<3)|(y))
uchar KeyGet ()	//ȡ��ֵ����
{
	unsigned char X, Y, Z;
	P0 = P0S(0x07); //�ȶ�P3 ���� ��ɨ��
	if (P0G != 0x07) //�ж��Ƿ��м�����
	{
		//delay10ms(); //��ʱ,���ȥ����
		if (P0G != 0x07) //ȷ�ϰ�������
		{
			X = P0G; //������ɨ��ʱ�м�����ʱ״̬
			P0 = P0S(0x38); //��ɨ��
			Y = P0G;  //������ɨ��ʱ�м�����ʱ״̬
			Z = X | Y; //ȡ����ֵ
			/*********************************************************************/
			switch ( Z ) //�жϼ�ֵ����һ�������£�
			{
			case XY(6,6): return 1; //�Լ�ֵ��ֵ
			case XY(6,5): return 2;
			case XY(6,3): return 3;
			case XY(5,6): return 4;
			case XY(5,5): return 5;
			case XY(5,3): return 6;
			case XY(3,6): return 7;
			case XY(3,5): return 8;
			case XY(3,3): return 9;
			default:
				return 0;
			}
		}
	}

	return 0;
}