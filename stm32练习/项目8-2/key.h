/*************************************				  
 ***********��������ͷ�ļ�************				  
 *************************************/				  
#ifndef __KEY_H										  
#define __KEY_H
#define KEY1 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0)   //��ȡPC0�İ���k1
void KEY_Init(void); //I/O��ʼ��
u8 KEY_Scan(void);
#endif
