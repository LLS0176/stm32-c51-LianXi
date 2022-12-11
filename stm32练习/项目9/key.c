/*************************************
 ************������������*************
 *************************************/
#include "stm32f10x.h"
#include "key.h"
#include "delay.h"
void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_key; //�������塰GPIO_key��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //ʹ��GPIOCʱ�ӣ�������PC��ǰ�ᣩ
	GPIO_key.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;  //ʹ��Pc0~Pc3����
	GPIO_key.GPIO_Mode  = GPIO_Mode_IPU;   //��������Ϊ��������
	GPIO_key.GPIO_Speed = GPIO_Speed_50MHz;   //����Pc�����ٶ�Ϊ50MHz
	GPIO_Init(GPIOB, &GPIO_key);      //��ʼ�����õ�����	    
} 
u8 KEY_Scan(void)
{
    static u8 key_up=1;  //�����ɿ�	
	if(key_up&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0))
	{
	    Delay(15);  //��ʱ��ȥ����
		key_up=0;
		if(KEY1==0)
		{
		    return 1;  //k1����
		}
		else if(KEY2==0)
		{
		    return 2;  //k2����
		}
		else if(KEY3==0)
		{
		    return 3;  //k3����
		}else if(KEY4==0)
		{
		    return 4;  //k4����
		}
	}
	else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1)
	    key_up=1; //û�а�������
	return 0;
}
