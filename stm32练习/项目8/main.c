#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "key.h"
u8 t;	 //按键返回数值
u8 k1=0,k2=0,k3=0,k4=0;   //led为熄灭状态
int main(void)
{	
    LED_Init(); //初始化LED端口
	KEY_Init();	//初始化key按键端口
	while(1)
	{	
	    t=KEY_Scan();  //得到按键的按下情况
		if(t)
		{	
		    switch(t)
			{
			    case 1:
				    if(k1==0)
					    GPIO_ResetBits(GPIOA,GPIO_Pin_8);  //PA8为低电平，LED1灭
					else
					    GPIO_SetBits(GPIOA,GPIO_Pin_8);    //PA8为高电平，LED1亮
					k1=!k1;
					break;
				case 2:
					if(k2==0)
					    GPIO_ResetBits(GPIOA,GPIO_Pin_9);  //PA9为低电平，LED2灭
					else
					    GPIO_SetBits(GPIOA,GPIO_Pin_9);	   //PA9为高电平，LED2亮
					k2=!k2;							
					break;
				case 3:
				    if(k3==0)
					    GPIO_ResetBits(GPIOA,GPIO_Pin_10); 	//PA10为低电平，LED3灭
					else
					    GPIO_SetBits(GPIOA,GPIO_Pin_10);	//PA10为高电平，LED3亮  
					k3=!k3;
					break;
				case 4:
				    if(k4==0)
					    GPIO_ResetBits(GPIOA,GPIO_Pin_11);  //PA11为低电平，LED4灭
					else
					    GPIO_SetBits(GPIOA,GPIO_Pin_11);	//PA11为高电平，LED4亮 
					k4=!k4;
					break;
					    
			}
		}
		else Delay(10);
	}
}
