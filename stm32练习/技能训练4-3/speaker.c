/************************************
 **********����������C�ļ�***********
 ************************************/
#include "stm32f10x.h"
#include "speaker.h"
void SPEAKER_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitSpeaker;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //ʹ��GPIOAʱ�ӣ�������PA��ǰ�ᣩ
	GPIO_InitSpeaker.GPIO_Pin = GPIO_Pin_12;  //ʹ��PA12����
	GPIO_InitSpeaker.GPIO_Mode = GPIO_Mode_Out_PP;  //��������Ϊ������� 
	GPIO_InitSpeaker.GPIO_Speed = GPIO_Speed_50MHz; //����PA�����ٶ�Ϊ50MHz
	GPIO_Init(GPIOA, &GPIO_InitSpeaker); //��ʼ�����õ�PA����
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //����PA12Ϊ�ߵ�ƽ
}
