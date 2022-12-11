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
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource12);  //设置中断
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource13);  //设置中断
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);  //设置中断
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource15);  //设置中断
	EXTI_InitStructure.EXTI_Line = EXTI_Line12|EXTI_Line13|EXTI_Line14|EXTI_Line15;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; 
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	NVIC_InitSturcture.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitSturcture.NVIC_IRQChannelPreemptionPriority = 0X0;
	NVIC_InitSturcture.NVIC_IRQChannelSubPriority = 0X0F;
	NVIC_InitSturcture.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitSturcture);
}
