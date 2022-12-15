#include "stm32f10x.h"
int main(void)
{
    GPIO_InitTypeDef  LEDDL;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	LEDDL.GPIO_Pin = GPIO_Pin_8;
	LEDDL.GPIO_Mode = GPIO_Mode_Out_PP;
	LEDDL.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,  &LEDDL);
	GPIO_SetBits(GPIOB,GPIO_Pin_8);
	while(1)
	{
         GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	}	   
}


