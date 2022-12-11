/*************************************
 ************按键引脚配置*************
 *************************************/
#include "stm32f10x.h"
#include "key.h"
#include "delay.h"
void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_key; //变量定义“GPIO_key”
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //使能GPIOC时钟（打开引脚PC的前提）
	GPIO_key.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;  //使用Pc0~Pc3引脚
	GPIO_key.GPIO_Mode  = GPIO_Mode_IPU;   //引脚配置为上拉输入
	GPIO_key.GPIO_Speed = GPIO_Speed_50MHz;   //设置Pc引脚速度为50MHz
	GPIO_Init(GPIOB, &GPIO_key);      //初始化配置的引脚	    
} 
u8 KEY_Scan(void)
{
    static u8 key_up=1;  //按键松开	
	if(key_up&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0))
	{
	    Delay(15);  //延时，去抖动
		key_up=0;
		if(KEY1==0)
		{
		    return 1;  //k1按下
		}
		else if(KEY2==0)
		{
		    return 2;  //k2按下
		}
		else if(KEY3==0)
		{
		    return 3;  //k3按下
		}else if(KEY4==0)
		{
		    return 4;  //k4按下
		}
	}
	else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1)
	    key_up=1; //没有按键按下
	return 0;
}
