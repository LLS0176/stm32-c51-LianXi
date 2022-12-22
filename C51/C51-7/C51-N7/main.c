#include <reg51.h>
void delay1s(); //1s
void disp1();   //Êý×Ö
void main()     //Ö÷º¯Êý
{
    while(1)
	{
	    disp1();
	}
}

void disp1()			//ÏÔÊ¾
{
    unsigned char led[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	                    // 0 ,  1 , 2  ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9
	unsigned char i,g,s;
//	for(i=7;i<100;i+=7)
	for(i=7;i<100;i++)
	{
	    if(i%7 == 0 || i%10 == 7 || i/10 == 7)
	    {
	        g = i%10;
		    s = i/10;
	        P2 = led[g]; //g
		    P3 = led[s]; //s
		    delay1s();
		}
	}
}

void delay1s()
{
    unsigned char i;
	TMOD = 0x10;
	for(i=0;i<0x14;i++)
	{
	    TH1=0X3C;
	    TL1=0XB0;
    	TR1=1;
	    while(! TF1);
    	TF1=0;
	}
}

