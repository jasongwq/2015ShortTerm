
#line 1 "DisPlay.c" /0
  
#line 1 "display.h" /0
 
 
  
#line 1 "mian.h" /0
 
 
  
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
 
 
#line 3 "mian.h" /0
 
 typedef unsigned char uchar;
 typedef unsigned int uint;
 
 sbit P3_0 = P3^0;
 sbit P3_1 = P3^1;
 sbit P3_2 = P3^2;
 sbit P3_3 = P3^3;
 
 sbit P1_4 = P1^4;
 sbit P1_5 = P1^5;
 sbit P1_6 = P1^6;
 sbit P1_7 = P1^7;
 
 
 
 
#line 3 "display.h" /0
 
 void DisF(uchar n);
 
 
 
 
#line 1 "DisPlay.c" /0
 
  
#line 1 "mian.h" /0
 
#line 2 "mian.h" /1
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 18 "mian.h" /0
 
 
#line 2 "DisPlay.c" /0
 
  
#line 1 "ds1302.h" /0
 
 
  
#line 1 "D:\Keil_v5\C51\Inc\reg52.h" /0






 
 
 
#line 10 "D:\Keil_v5\C51\Inc\reg52.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 3 "ds1302.h" /0
#line 3 "ds1302.h" /0
 
  
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
 
 
 
#line 4 "ds1302.h" /0
 
  
#line 1 "mian.h" /0
 
#line 2 "mian.h" /1
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 18 "mian.h" /0
 
 
#line 5 "ds1302.h" /0
 
 
 sbit ACC_0 = ACC^0;
 sbit ACC_1 = ACC^1;
 sbit ACC_2 = ACC^2;
 sbit ACC_3 = ACC^3;
 sbit ACC_4 = ACC^4;
 sbit ACC_5 = ACC^5;
 sbit ACC_6 = ACC^6;
 sbit ACC_7 = ACC^7; 
 
 sbit T_SCLK = P3^6;                     
 sbit T_DIO= P3^7;                       
 sbit T_CE = P3^5;
 
 typedef struct
 {
 uchar sec,min,hour,day,month,week,year;     
 
 }Tim;
 void DS1302_Write( uchar sec_w,min_w,hour_w,day_w,month_w,week_w,year_w );
 Tim DS1302_readtime();
 uchar DS1302_RTC_Seting(uchar key);
 void DS1302_SMG_display(uchar dat0,dat1,dat2,dat3,dat4,dat5,dat6);
 void DS1302_SMG_display_ex(uchar wela);
 void SMG_display(uchar wela, uchar n);
 
#line 3 "DisPlay.c" /0
 
 
 void DisF(uchar n)
 {
 SMG_display(0, 11);
 SMG_display(10, 10);
 SMG_display(11, n);
 }
