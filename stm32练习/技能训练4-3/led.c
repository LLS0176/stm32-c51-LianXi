/*************************************
 *************LED引脚*************
 *************************************/
#include "stm32f10x.h"
#include "led.h"
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_led;  //变量定义“GPIO_led”	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //使能GPIOA时钟（打开引脚PA的前提）
	GPIO_led.GPIO_Pin = GPIO_Pin_8;  //使用PA8引脚
	GPIO_led.GPIO_Mode  = GPIO_Mode_Out_PP;   //引脚配置为推挽输出
	GPIO_led.GPIO_Speed = GPIO_Speed_50MHz;   //设置PA引脚速度为50MHz
	GPIO_Init(GPIOA, &GPIO_led);      //初始化配置的引脚
	GPIO_SetBits(GPIOA,GPIO_Pin_8);  //设置PA8为高电平,led熄灭
}
