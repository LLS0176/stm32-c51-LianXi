/*************************************				  
 ***********按键配置头文件************				  
 *************************************/				  
#ifndef __KEY_H										  
#define __KEY_H
#define KEY1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)   //读取PC9的按键k1
#define KEY2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)   //读取PC12的按键k2
void KEY_Init(void); //I/O初始化
u8 KEY_Scan(void);
#endif
