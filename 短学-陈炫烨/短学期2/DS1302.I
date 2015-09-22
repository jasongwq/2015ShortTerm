
#line 1 "DS1302.c" /0
  
#line 1 "ds1302.h" /0
 
 
  
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
 
 
  
#line 1 "D:\Keil_v5\C51\Inc\reg52.h" /0






 
 
 
#line 10 "D:\Keil_v5\C51\Inc\reg52.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 3 "mian.h" /0
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
 
#line 1 "DS1302.c" /0
 
  
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
 
 
 
#line 2 "DS1302.c" /0
 
  
#line 1 "key.h" /0
 
 
  
#line 1 "D:\Keil_v5\C51\Inc\reg52.h" /0






 
 
 
#line 10 "D:\Keil_v5\C51\Inc\reg52.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 3 "key.h" /0
#line 3 "key.h" /0
 
  
#line 1 "D:\Keil_v5\C51\Inc\intrins.h" /0






 
 
 
#line 10 "D:\Keil_v5\C51\Inc\intrins.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 39 "D:\Keil_v5\C51\Inc\intrins.h" /0
 
#line 4 "key.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 unsigned char KeyGet();
 
#line 3 "DS1302.c" /0
 
 code uchar seg7code[12] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x8e, 0xff};	  
 code uchar wei[13] = {0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc};  
 
 uchar   sec, min, hour, day, month, week, year;  
 uchar 	secH, secL, minH, minL, hourH, hourL, dayH, dayL, monthH, monthL, week, yearH, yearL;
 
 uchar DS1302_RTC_Seting(uchar key)
 {
 static uchar wela;
 if (key == 0x11)
 {
 if (wela == 12)
 {
 wela = 0;
 }
 else
 {
 wela++;
 }
 }
 else if (key == 0x14)
 {
 if (wela == 0)
 {
 wela = 12;
 }
 else
 {
 wela--;
 }
 }
 else if (key == 0x22)
 {
 switch (wela)
 {
 case 12: if (week++ == 7) week = 0 ; break;
 case 11: if (minL++ == 9) minL = 0 ; break;
 case 10: if (minH++ == 6) minH = 0 ; break;
 case 9: if (hourL++ == 9) hourL = 0; break;
 case 8: if (hourH++ == 6) hourH = 0; break;
 case 7: if (dayL++ == 9) dayL = 0 ; break;
 case 6: if (dayH++ == 3) dayH = 0 ; break;
 case 5: if (monthL++ == 9) monthL = 0 ; break;
 case 4: if (monthH++ == 1) monthH = 0 ; break;
 case 3: if (yearL++ == 9) yearL = 0 ; break;
 case 2: if (yearH++ == 9) yearH = 0 ; break;
 case 1:  break;
 case 0:  break;
 default: break;
 }
 }
 else if (key == 0x0a)
 {
 switch (wela)
 {
 case 12: if (week-- == 0) week = 7; break;
 case 11: if (minL-- == 0) minL = 9; break;
 case 10: if (minH-- == 0) minH = 6; break;
 case 9: if (hourL-- == 0) hourL = 9; break;
 case 8: if (hourH-- == 0) hourL = 6; break;
 case 7: if (dayL-- == 0) dayL = 9; break;
 case 6: if (dayH-- == 0) dayH = 3; break;
 case 5: if (monthL-- == 0) monthL = 9; break;
 case 4: if (monthH-- == 0) monthL = 1; break;
 case 3: if (yearL-- == 0) yearL = 9; break;
 case 2: if (yearH-- == 0) yearH = 9; break;
 default: break;
 }
 }
 else if (key == 0x09)
 {	static uchar n;
 n = !n;
 sec = secH << 4 | secL;
 min = minH << 4 | minL;
 hour = hourH << 4 | hourL;
 day = dayH << 4 | dayL;
 month = monthH << 4 | monthL;
 year = yearH << 4 | yearL;
 DS1302_Write(sec, min, hour, day, month, week, year);
 if (!n) return 0;
 }
 if (minH * 10 + minL > 60)
 {
 minH = 6;
 minL = 0;
 }
 if (hourH * 10 + hourL > 60)
 {
 hourH = 6;
 hourL = 0;
 }
 if (monthH * 10 + monthL > 12)
 {
 monthH = 1;
 monthL = 2;
 }
 if (dayH * 10 + dayL > 31)
 {
 dayH = 3;
 dayL = 1;
 }
 DS1302_SMG_display_ex(wela);
 return 1;
 }
 
 uchar  DS1302_addr[] = {
 0x80,  
 0x81,  
 0x8a,  
 0x8b,  
 0x82,  
 0x83,  
 0x84,  
 0x85,  
 0x86,  
 0x87,  
 0x88,  
 0x89,  
 0x8c,  
 0x8d,  
 0x8e,  
 0x8f   
 
 }  ;
 
 void SMG_display(uchar wela, uchar n)
 {
 P1 = 0XFF;
 P2 = seg7code[n];
 P1 = wei[wela];
 delay(10);
 }
 
 void DS1302_Input_Byte(uchar Input)   
 {
 uchar i;
 ACC = Input;
 for (i = 8; i > 0; i--)
 {
 T_DIO = ACC_0;             
 T_SCLK = 1;
 T_SCLK = 0;
 ACC = ACC >> 1;
 }
 }
 
 uchar DS1302_Output_Byte(void)       
 {
 uchar i;
 for (i = 8; i > 0; i--)
 {
 ACC >>= 1; T_DIO = 1;
 ACC_7 = T_DIO;
 T_SCLK = 1;                  
 T_SCLK = 0;
 }
 return (ACC);
 }
 
 void DS1302_Write_one( uchar addr, dat )       
 {
 T_CE = 0;                            
 T_SCLK = 0;                         
 T_CE = 1;                           
 DS1302_Input_Byte(addr);            
 DS1302_Input_Byte(dat);           
 T_SCLK = 1;
 T_CE = 0;
 }
 
 uchar DS1302_Read ( uchar addr )     
 {
 uchar date;
 T_CE = 0;
 T_SCLK = 0;
 T_CE = 1;
 DS1302_Input_Byte(addr);         
 date = DS1302_Output_Byte();          
 T_SCLK = 1;
 T_CE = 0;
 return (date);
 }
 
 void DS1302_Write( uchar sec_w, min_w, hour_w, day_w, month_w, week_w, year_w )
 {
 DS1302_Write_one(0x8e, 0x00);
 DS1302_Write_one(0x80, sec_w);
 DS1302_Write_one(0x82, min_w);
 DS1302_Write_one(0x84, hour_w);
 DS1302_Write_one(0x86, day_w);
 DS1302_Write_one(0x88, month_w);
 DS1302_Write_one(0x8a, week_w);
 DS1302_Write_one(0x8c, year_w);
 DS1302_Write_one(0x8e, 0x80);
 }
 
 
 
 
 
 
 
 Tim DS1302_readtime()
 {
 Tim timdat;
 sec = DS1302_Read(0x81);                   
 secH = sec >> 4;
 secL = sec & 0x0f;
 min = DS1302_Read(0x83);                   
 minH = min >> 4;
 minL = min & 0x0f;
 hour = DS1302_Read(0x85);                  
 hourH = hour >> 4;
 hourL = hour & 0x0f;
 day = DS1302_Read(0x87);                   
 dayH = day >> 4;
 dayL = day & 0x0f;
 month = DS1302_Read(0x89);                 
 monthH = month >> 4;
 monthL = month & 0x0f;
 year = DS1302_Read(0x8d);    
 yearH = year >> 4;
 yearL = year & 0x0f;
 week = DS1302_Read(0x8b);     
 timdat.sec = sec;
 timdat.min = min;
 timdat.hour = hour;
 timdat.day = day;
 timdat.month = month;
 timdat.year = year;
 timdat.week = week;
 return timdat;
 }
 
 void DS1302_SMG_display_ex(uchar wela)
 {
 static uchar s1;
 s1 = S1;
 if (wela == 12 && s1) {SMG_display(12, 11);}
 else SMG_display(12, week);
 if (wela == 11 && s1) {SMG_display(11, 11);}
 else  SMG_display(11, minL);
 if (wela == 10 && s1) {SMG_display(10, 11);}
 else SMG_display(10, minH);
 if (wela == 9 && s1) {SMG_display(9, 11);}
 else SMG_display(9, hourL);
 if (wela == 8 && s1) {SMG_display(8, 11);}
 else SMG_display(8, hourH);
 if (wela == 7 && s1) {SMG_display(7, 11);}
 else SMG_display(7, dayL);
 if (wela == 6 && s1) {SMG_display(6, 11);}
 else SMG_display(6, dayH);
 if (wela == 5 && s1) {SMG_display(5, 11);}
 else SMG_display(5, monthL);
 if (wela == 4 && s1) {SMG_display(4, 11);}
 else SMG_display(4, monthH);
 if (wela == 3 && s1) {SMG_display(3, 11);}
 else SMG_display(3, yearL);
 if (wela == 2 && s1) {SMG_display(2, 11);}
 else SMG_display(2, yearH);
 if (wela == 1 && s1) {SMG_display(1, 11);}
 else SMG_display(1, 0);
 if (wela == 0 && s1) {SMG_display(0, 11);}
 else SMG_display(0, 2);
 }
 void DS1302_SMG_display(uchar dat0, dat1, dat2, dat3, dat4, dat5, dat6)
 {
 SMG_display(12, dat6);
 SMG_display(11, dat5 % 0x10);
 SMG_display(10, dat5 / 0x10);
 SMG_display(9, dat4 % 0x10);
 SMG_display(8, dat4 / 0x10);
 SMG_display(7, dat3 % 0x10);
 SMG_display(6, dat3 / 0x10);
 SMG_display(5, dat2 % 0x10);
 SMG_display(4, dat2 / 0x10);
 SMG_display(3, dat1 % 0x10);
 SMG_display(2, dat1 / 0x10);
 SMG_display(1, dat0 % 0x10);
 SMG_display(0, dat0 / 0x10);
 }
