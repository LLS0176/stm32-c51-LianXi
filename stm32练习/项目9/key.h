/*************************************				  
 ***********��������ͷ�ļ�************				  
 *************************************/				  
#ifndef __KEY_H										  
#define __KEY_H
#define KEY1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)   //��ȡPC0�İ���k1
#define KEY2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)   //��ȡPC1�İ���k2
#define KEY3 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)   //��ȡPC2�İ���k3
#define KEY4 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15)   //��ȡPC3�İ���k4
void KEY_Init(void); //I/O��ʼ��
u8 KEY_Scan(void);
#endif
