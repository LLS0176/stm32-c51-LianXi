#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "exit.h"
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();		//led初始化
	KEY_Init();		//按键初始化
	exit_config();	//中断
	while(1);
}
