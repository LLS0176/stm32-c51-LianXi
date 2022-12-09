#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "key.h"
u8 ID;	
int main(void)
{	
    LED_Init(); //初始化LED端口
	KEY_Init();	//初始化key按键端口
	while(1)
	{	
	    if(KEY1==0)
		{	
		    Delay(20);
		    if(KEY1==0)
			{
			    ID++;
				if(ID==4)
				{
				    ID=0; 
				}
				while(KEY1==0);	    
			}
		}
		switch(ID)
		{
		    case 0:
			    GPIO_SetBits(GPIOA,GPIO_Pin_8);	  //PA8为高电平，LED1亮
				GPIO_ResetBits(GPIOA,GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11); //PA9,PA10,PA11为低电平，LED2,3,4灭
				break;
			case 1:
			    GPIO_SetBits(GPIOA,GPIO_Pin_9);	  //PA9为高电平，LED2亮
				GPIO_ResetBits(GPIOA,GPIO_Pin_8|GPIO_Pin_10|GPIO_Pin_11); //PA8,PA10,PA11为低电平，LED1,3,4灭
				break;
			case 2:
			    GPIO_SetBits(GPIOA,GPIO_Pin_10);  //PA10为高电平，LED3亮
				GPIO_ResetBits(GPIOA,GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_11); //PA9,PA8,PA11为低电平，LED2,1,4灭
				break;
			case 3:
			    GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //PA11为高电平，LED4亮
				GPIO_ResetBits(GPIOA,GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10); //PA9,PA10,PA8为低电平，LED2,3,1灭
				break;
		}
	}
}



