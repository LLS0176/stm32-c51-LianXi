/*************************************				  
 ***********按键配置头文件************				  
 *************************************/				  
#ifndef __KEY_H										  
#define __KEY_H
#define KEY1 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0)   //读取PC0的按键k1
void KEY_Init(void); //I/O初始化
u8 KEY_Scan(void);
#endif
