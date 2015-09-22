
#line 1 "24C08.c" /0
  
#line 1 "24c08.h" /0
 
 
  
#line 1 "D:\Keil_v5\C51\Inc\reg52.h" /0






 
 
 
 
 
 
 sfr P0    = 0x80;
 sfr P1    = 0x90;
 sfr P2    = 0xA0;
 sfr P3    = 0xB0;
 sfr PSW   = 0xD0;
 sfr ACC   = 0xE0;
 sfr B     = 0xF0;
 sfr SP    = 0x81;
 sfr DPL   = 0x82;
 sfr DPH   = 0x83;
 sfr PCON  = 0x87;
 sfr TCON  = 0x88;
 sfr TMOD  = 0x89;
 sfr TL0   = 0x8A;
 sfr TL1   = 0x8B;
 sfr TH0   = 0x8C;
 sfr TH1   = 0x8D;
 sfr IE    = 0xA8;
 sfr IP    = 0xB8;
 sfr SCON  = 0x98;
 sfr SBUF  = 0x99;
 
 
 sfr T2CON  = 0xC8;
 sfr RCAP2L = 0xCA;
 sfr RCAP2H = 0xCB;
 sfr TL2    = 0xCC;
 sfr TH2    = 0xCD;
 
 
 
 
 sbit CY    = PSW^7;
 sbit AC    = PSW^6;
 sbit F0    = PSW^5;
 sbit RS1   = PSW^4;
 sbit RS0   = PSW^3;
 sbit OV    = PSW^2;
 sbit P     = PSW^0;  
 
 
 sbit TF1   = TCON^7;
 sbit TR1   = TCON^6;
 sbit TF0   = TCON^5;
 sbit TR0   = TCON^4;
 sbit IE1   = TCON^3;
 sbit IT1   = TCON^2;
 sbit IE0   = TCON^1;
 sbit IT0   = TCON^0;
 
 
 sbit EA    = IE^7;
 sbit ET2   = IE^5;  
 sbit ES    = IE^4;
 sbit ET1   = IE^3;
 sbit EX1   = IE^2;
 sbit ET0   = IE^1;
 sbit EX0   = IE^0;
 
 
 sbit PT2   = IP^5;
 sbit PS    = IP^4;
 sbit PT1   = IP^3;
 sbit PX1   = IP^2;
 sbit PT0   = IP^1;
 sbit PX0   = IP^0;
 
 
 sbit RD    = P3^7;
 sbit WR    = P3^6;
 sbit T1    = P3^5;
 sbit T0    = P3^4;
 sbit INT1  = P3^3;
 sbit INT0  = P3^2;
 sbit TXD   = P3^1;
 sbit RXD   = P3^0;
 
 
 sbit SM0   = SCON^7;
 sbit SM1   = SCON^6;
 sbit SM2   = SCON^5;
 sbit REN   = SCON^4;
 sbit TB8   = SCON^3;
 sbit RB8   = SCON^2;
 sbit TI    = SCON^1;
 sbit RI    = SCON^0;
 
 
 sbit T2EX  = P1^1;  
 sbit T2    = P1^0;  
 
 
 sbit TF2    = T2CON^7;
 sbit EXF2   = T2CON^6;
 sbit RCLK   = T2CON^5;
 sbit TCLK   = T2CON^4;
 sbit EXEN2  = T2CON^3;
 sbit TR2    = T2CON^2;
 sbit C_T2   = T2CON^1;
 sbit CP_RL2 = T2CON^0;
 
 
#line 3 "24c08.h" /0
 
  
#line 1 "D:\Keil_v5\C51\Inc\intrins.h" /0






 
 
 
 
 
 #pragma SAVE
 
 
#line 15 "D:\Keil_v5\C51\Inc\intrins.h" /1
 
 
 
#line 18 "D:\Keil_v5\C51\Inc\intrins.h" /0
 
 extern void          _nop_     (void);
 extern bit           _testbit_ (bit);
 extern unsigned char _cror_    (unsigned char, unsigned char);
 extern unsigned int  _iror_    (unsigned int,  unsigned char);
 extern unsigned long _lror_    (unsigned long, unsigned char);
 extern unsigned char _crol_    (unsigned char, unsigned char);
 extern unsigned int  _irol_    (unsigned int,  unsigned char);
 extern unsigned long _lrol_    (unsigned long, unsigned char);
 extern unsigned char _chkfloat_(float);
 
#line 29 "D:\Keil_v5\C51\Inc\intrins.h" /1
 
 
#line 31 "D:\Keil_v5\C51\Inc\intrins.h" /0
 
 extern void          _push_    (unsigned char _sfr);
 extern void          _pop_     (unsigned char _sfr);
 
 
 #pragma RESTORE
 
 
 
#line 4 "24c08.h" /0
 
 typedef struct
 {
 unsigned char sec,min,hour,day,month,week,year;
 unsigned char n;  
 }AlarmData;
 
 sbit SCL = P0^6;
 sbit SDA = P0^7;
 void i2cinit();
 unsigned char* Search2(unsigned char count);
 AlarmData Search(unsigned char count);
 unsigned char read_add(unsigned char address);
 void write_add(unsigned char address,unsigned char date);
 unsigned char write_n_add(unsigned char * p,unsigned char address,unsigned char n);
 unsigned char read_n_add(unsigned char * p,unsigned char address,unsigned char n);
 
#line 1 "24C08.c" /0
 
  
#line 1 "delay.h" /0
 
 
 
  
#line 1 "D:\Keil_v5\C51\Inc\reg52.h" /0






 
 
 
#line 10 "D:\Keil_v5\C51\Inc\reg52.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 4 "delay.h" /0
#line 4 "delay.h" /0
 
  
#line 1 "D:\Keil_v5\C51\Inc\intrins.h" /0






 
 
 
#line 10 "D:\Keil_v5\C51\Inc\intrins.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 39 "D:\Keil_v5\C51\Inc\intrins.h" /0
 
#line 5 "delay.h" /0
 
 
 void TimeInit();
 void delay_ms(unsigned char i);
 void delay(unsigned char n);
 extern unsigned char S1;
 extern unsigned char S5;
 extern unsigned char T5;
 
 
 
#line 2 "24C08.c" /0
 
 
 void i2cinit() 
 {
 SDA = 1;
 delay(1);
 SCL = 1;
 delay(1);
 }
 void start() 
 {
 SDA = 1;
 SCL = 1;
 delay(1);
 SDA = 0;
 delay(1);
 }
 void stop() 
 {
 SDA = 0;
 delay(1);
 SCL = 1;
 delay(1);
 SDA = 1;
 delay(1);
 }
 void respons() 
 {
 unsigned char i = 0;
 SCL = 1;
 delay(1);
 while(SDA == 1 && i < 255) 
 i++;
 SCL = 0;
 delay(1);
 }
 void writebyte(unsigned char date) 
 {
 unsigned char i,temp;
 temp = date;
 for(i = 0; i < 8; i++)
 {
 temp <<= 1; 
 SCL = 0;
 delay(1);
 SDA = CY;
 delay(1);
 SCL = 1;
 delay(1);
 } 
 SCL = 0; 
 delay(1);
 SDA = 1; 
 delay(1);
 }
 unsigned char readbyte() 
 {
 unsigned char i,k;
 SCL = 0;
 delay(1);
 SDA = 1;
 for(i = 0; i < 8; i++)
 {
 SCL = 1; 
 delay(1);
 k = (k << 1) | SDA;  
 SCL = 0;
 delay(1);
 }
 delay(1);
 return k;
 }
 void write_add(unsigned char address,unsigned char date) 
 {
 start();
 writebyte(0xa0); 
 respons();
 writebyte(address);
 respons();
 writebyte(date);
 respons();
 stop();
 }
 unsigned char read_add(unsigned char address) 
 {
 unsigned char date;
 start();
 writebyte(0xa0); 
 respons();
 writebyte(address);
 respons();
 start();
 writebyte(0xa1); 
 respons();
 date = readbyte();
 stop();
 return date;
 }
 
 
 unsigned char write_n_add(unsigned char * p,unsigned char address,unsigned char n)
 {
 unsigned char i;
 for(i = 0; i < n; i++)
 {
 write_add((address + i),*(p + i));
 
 delay_ms(20); 
 }
 return  (address + i);
 }
 
 unsigned char read_n_add(unsigned char * p,unsigned char address,unsigned char n)
 {
 unsigned char i;
 for(i = 0; i < n; i++)
 {
 *(p + i) = read_add(address + i);
 
 
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
