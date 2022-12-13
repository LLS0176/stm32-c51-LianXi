/*************************************
 *************LED����*************
 *************************************/
#include "stm32f10x.h"
#include "led.h"
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_led;  //�������塰GPIO_led��	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //ʹ��GPIOAʱ�ӣ�������PA��ǰ�ᣩ
	GPIO_led.GPIO_Pin = GPIO_Pin_8;  //ʹ��PA8����
	GPIO_led.GPIO_Mode  = GPIO_Mode_Out_PP;   //��������Ϊ�������
	GPIO_led.GPIO_Speed = GPIO_Speed_50MHz;   //����PA�����ٶ�Ϊ50MHz
	GPIO_Init(GPIOA, &GPIO_led);      //��ʼ�����õ�����
	GPIO_SetBits(GPIOA,GPIO_Pin_8);  //����PA8Ϊ�ߵ�ƽ,ledϨ��
}
