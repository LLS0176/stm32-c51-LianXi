/*************************************				  
 ***********��������ͷ�ļ�************				  
 *************************************/				  
#ifndef __KEY_H										  
#define __KEY_H
#define KEY1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)   //��ȡPC9�İ���k1
#define KEY2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)   //��ȡPC12�İ���k2
void KEY_Init(void); //I/O��ʼ��
u8 KEY_Scan(void);
#endif
