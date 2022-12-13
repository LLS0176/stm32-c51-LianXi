#include "stm32f10x.h"
#include "speaker.h" 
#include "delay.h"
#include "key.h"
#include "led.h"
#include "exit.h"

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	SPEAKER_Init();		//SPEAKER��ʼ��
	LED_Init();
	KEY_Init();		//������ʼ��
	exit_config();	//�ж�
	while(1);
}
