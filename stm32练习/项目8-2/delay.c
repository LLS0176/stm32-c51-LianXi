/*************************************
 **************延时配置***************
 *************************************/
#include "delay.h"
void Delay(unsigned int count)   //延时函数
{
    unsigned int i;
	for(;count!=0;count--)
	{
	    i=5000;
		while(i--);	 //这里是--，不要写成++
	}
}	


	

