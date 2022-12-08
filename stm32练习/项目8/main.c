#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "key.h"
u8 t;	 //����������ֵ
u8 k1=0,k2=0,k3=0,k4=0;   //ledΪϨ��״̬
int main(void)
{	
    LED_Init(); //��ʼ��LED�˿�
	KEY_Init();	//��ʼ��key�����˿�
	while(1)
	{	
	    t=KEY_Scan();  //�õ������İ������
		if(t)
		{	
		    switch(t)
			{
			    case 1:
				    if(k1==0)
					    GPIO_ResetBits(GPIOA,GPIO_Pin_8);  //PA8Ϊ�͵�ƽ��LED1��
					else
					    GPIO_SetBits(GPIOA,GPIO_Pin_8);    //PA8Ϊ�ߵ�ƽ��LED1��
					k1=!k1;
					break;
				case 2:
					if(k2==0)
					    GPIO_ResetBits(GPIOA,GPIO_Pin_9);  //PA9Ϊ�͵�ƽ��LED2��
					else
					    GPIO_SetBits(GPIOA,GPIO_Pin_9);	   //PA9Ϊ�ߵ�ƽ��LED2��
					k2=!k2;							
					break;
				case 3:
				    if(k3==0)
					    GPIO_ResetBits(GPIOA,GPIO_Pin_10); 	//PA10Ϊ�͵�ƽ��LED3��
					else
					    GPIO_SetBits(GPIOA,GPIO_Pin_10);	//PA10Ϊ�ߵ�ƽ��LED3��  
					k3=!k3;
					break;
				case 4:
				    if(k4==0)
					    GPIO_ResetBits(GPIOA,GPIO_Pin_11);  //PA11Ϊ�͵�ƽ��LED4��
					else
					    GPIO_SetBits(GPIOA,GPIO_Pin_11);	//PA11Ϊ�ߵ�ƽ��LED4�� 
					k4=!k4;
					break;
					    
			}
		}
		else Delay(10);
	}
}
