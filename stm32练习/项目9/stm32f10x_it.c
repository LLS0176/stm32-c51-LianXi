/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
/******************************************************************************
 ***** 中断程序需要的头文件
 ***** 中断程序在在下面
 ******************************************************************************/
#include "key.h"
#include "delay.h"
#include "stm32f10x_exti.h"



/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/




/******************************************************************************
 **** 中断程序
 ******************************************************************************/
void EXTI15_10_IRQHandler(void)
{
    static u8 k1=0,k2=0,k3=0,k4=0;
	Delay(20);
	if(KEY1==0)
	{
	    if(k1==0)
			GPIO_ResetBits(GPIOA,GPIO_Pin_8);  //PA8为低电平，LED1灭
		else
			GPIO_SetBits(GPIOA,GPIO_Pin_8);    //PA8为高电平，LED1亮
		k1=!k1;
				
	}
	else if(KEY2==0)
	{
	    if(k2==0)
			GPIO_ResetBits(GPIOA,GPIO_Pin_9);  //PA9为低电平，LED2灭
		else
			GPIO_SetBits(GPIOA,GPIO_Pin_9);    //PA9为高电平，LED2亮
		k2=!k2;
				
	}
	else if(KEY3==0)
	{
	    if(k3==0)
			GPIO_ResetBits(GPIOA,GPIO_Pin_10);  //PA10为低电平，LED3灭
		else
			GPIO_SetBits(GPIOA,GPIO_Pin_10);    //PA10为高电平，LED3亮
		k3=!k3;
				
	}
	else if(KEY4==0)
	{
	    if(k4==0)
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);  //PA11为低电平，LED4灭
		else
			GPIO_SetBits(GPIOA,GPIO_Pin_11);    //PA11为高电平，LED4亮
		k4=!k4;
				
	}
	while(KEY1!=1||KEY2!=1||KEY3!=1||KEY4!=1); //等待按键松开
	EXTI_ClearITPendingBit(EXTI_Line12);  //清除Line12的中断
	EXTI_ClearITPendingBit(EXTI_Line13);  //清除Line13的中断
	EXTI_ClearITPendingBit(EXTI_Line14);  //清除Line14的中断
	EXTI_ClearITPendingBit(EXTI_Line15);  //清除Line15的中断
}















