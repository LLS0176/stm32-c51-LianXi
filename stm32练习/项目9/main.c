#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "exit.h"
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();		//led��ʼ��
	KEY_Init();		//������ʼ��
	exit_config();	//�ж�
	while(1);
}
