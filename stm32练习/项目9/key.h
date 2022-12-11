/*************************************				  
 ***********按键配置头文件************				  
 *************************************/				  
#ifndef __KEY_H										  
#define __KEY_H
#define KEY1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)   //读取PC0的按键k1
#define KEY2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)   //读取PC1的按键k2
#define KEY3 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)   //读取PC2的按键k3
#define KEY4 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15)   //读取PC3的按键k4
void KEY_Init(void); //I/O初始化
u8 KEY_Scan(void);
#endif
