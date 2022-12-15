#include "stm32f10x.h"
void Delay(unsigned int count)
{
	unsigned int i;
	for(;count!=0;count--)
	{
	i=5000;
	while(i--);
	}
}

int main(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;    
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,  &GPIO_InitStructure);
	GPIO_SetBits(GPIOB,GPIO_Pin_8);
	while(1)
	{
        GPIO_ResetBits(GPIOB,GPIO_Pin_8);
        Delay (100);
        GPIO_SetBits(GPIOB,GPIO_Pin_8);
        Delay (100);
	}	   
}

