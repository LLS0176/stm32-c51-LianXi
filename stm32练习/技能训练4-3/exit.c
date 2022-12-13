/**************************************
 ***********外部中断配置***************
 **************************************/
#include "stm32f10x.h"
#include "stm32f10x_exti.h"
void exit_config(void)
{						 
    EXTI_InitTypeDef  EXTI_InitStructure;
	NVIC_InitTypeDef  NVIC_InitSturcture;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource9);  //设置中断
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource12);  //设置中断

	EXTI_InitStructure.EXTI_Line = EXTI_Line9|EXTI_Line12;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; 
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	//k1
	NVIC_InitSturcture.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitSturcture.NVIC_IRQChannelPreemptionPriority = 0X01;
	NVIC_InitSturcture.NVIC_IRQChannelSubPriority = 0X07;
	NVIC_InitSturcture.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitSturcture);
    //k2
	NVIC_InitSturcture.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitSturcture.NVIC_IRQChannelPreemptionPriority = 0X00;
	NVIC_InitSturcture.NVIC_IRQChannelSubPriority = 0X07;
	NVIC_InitSturcture.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitSturcture);
}
