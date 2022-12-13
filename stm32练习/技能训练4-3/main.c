#include "stm32f10x.h"
#include "speaker.h" 
#include "delay.h"
#include "key.h"
#include "led.h"
#include "exit.h"

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	SPEAKER_Init();		//SPEAKER初始化
	LED_Init();
	KEY_Init();		//按键初始化
	exit_config();	//中断
	while(1);
}
