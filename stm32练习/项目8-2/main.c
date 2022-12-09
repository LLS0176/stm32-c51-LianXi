#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "key.h"
u8 ID;	
int main(void)
{	
    LED_Init(); //��ʼ��LED�˿�
	KEY_Init();	//��ʼ��key�����˿�
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
			    GPIO_SetBits(GPIOA,GPIO_Pin_8);	  //PA8Ϊ�ߵ�ƽ��LED1��
				GPIO_ResetBits(GPIOA,GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11); //PA9,PA10,PA11Ϊ�͵�ƽ��LED2,3,4��
				break;
			case 1:
			    GPIO_SetBits(GPIOA,GPIO_Pin_9);	  //PA9Ϊ�ߵ�ƽ��LED2��
				GPIO_ResetBits(GPIOA,GPIO_Pin_8|GPIO_Pin_10|GPIO_Pin_11); //PA8,PA10,PA11Ϊ�͵�ƽ��LED1,3,4��
				break;
			case 2:
			    GPIO_SetBits(GPIOA,GPIO_Pin_10);  //PA10Ϊ�ߵ�ƽ��LED3��
				GPIO_ResetBits(GPIOA,GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_11); //PA9,PA8,PA11Ϊ�͵�ƽ��LED2,1,4��
				break;
			case 3:
			    GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //PA11Ϊ�ߵ�ƽ��LED4��
				GPIO_ResetBits(GPIOA,GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10); //PA9,PA10,PA8Ϊ�͵�ƽ��LED2,3,1��
				break;
		}
	}
}



