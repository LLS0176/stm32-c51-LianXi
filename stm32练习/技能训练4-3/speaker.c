/************************************
 **********扬声器配置C文件***********
 ************************************/
#include "stm32f10x.h"
#include "speaker.h"
void SPEAKER_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitSpeaker;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //使能GPIOA时钟（打开引脚PA的前提）
	GPIO_InitSpeaker.GPIO_Pin = GPIO_Pin_12;  //使用PA12引脚
	GPIO_InitSpeaker.GPIO_Mode = GPIO_Mode_Out_PP;  //引脚配置为推挽输出 
	GPIO_InitSpeaker.GPIO_Speed = GPIO_Speed_50MHz; //设置PA引脚速度为50MHz
	GPIO_Init(GPIOA, &GPIO_InitSpeaker); //初始化配置的PA引脚
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //设置PA12为高电平
}
