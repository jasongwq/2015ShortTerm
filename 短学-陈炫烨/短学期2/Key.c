#include "key.h"


unsigned char KeyScan()//按键扫描程序
{
	unsigned char hCode, lCode;
	P0 = 0xf8;
	if ((P0 & 0xf8) != 0xf8)
	{
		if ((P0 & 0xf8) != 0xf8)
		{
			hCode = 0xfe;
			while ((hCode & 0x08) != 0x00)
			{
				P0 = hCode;
				if ((P0 & 0xf8) != 0xf8)
				{
					lCode = (P0 & 0xf8) | 0x07;
					return ~hCode + ~lCode;
				}
				else
					hCode = _crol_(hCode, 1);//循环左移
			}
		}
	}
	return 0;
}

unsigned char KeyGet()
{
	static unsigned char KeyPress;
	unsigned char Key;
	Key = KeyScan();
	if (Key) KeyPress = Key;
	else if (KeyPress)//松开检测
	{
		Key = KeyPress;
		KeyPress = 0;
		return Key;//返回键值
	}
	return 0;
}





