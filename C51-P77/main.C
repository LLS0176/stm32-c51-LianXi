#include <REG51.H>
#include <INTRINS.H>  //库函数头文件，代码中引用了_nop_()函数
// 定义控制信号端口
sbit RS=P3^0;
sbit RW=P3^1;                     
sbit E= P3^2;                     
// 声明调用函数
void lcd_w_cmd(unsigned char com);//写命令字函数
void lcd_w_dat(unsigned char dat);//写数据函数
unsigned char lcd_r_start();      //读状态函数
void lcd_init();                  //LCD初始化函数
void delay100us(unsigned char t); //可控延时函数
void delay5us(unsigned char n);   //软件实现延时函数，n*5个机器周期
void main()//主函数
{
   unsigned char Disp[]="Hello Everyone";  //定义字符数组Disp
   unsigned char i;
   P1=0xff;   // 送全1到P1口
   lcd_init();  // 初始化LCD
   delay100us(255);
   lcd_w_cmd(0xc2); // 定位光标设置显示位置
   delay100us(255);
   for(i=0;i<14;i++) // 显示字符串
   {                    
    lcd_w_dat(Disp[i]);
    delay100us(200);
    }
   while(1);  // 显示完成
}

//延时100us
void delay100us(unsigned char t)     
{
   unsigned char j,i;
   for(i=0;i<t;i++)
   for(j=0;j<10;j++); 
}

//延时5us　　
void delay5us(unsigned char n)
{  
    do
    {
     _nop_();
     _nop_();
     _nop_();
     n--;
     }
     while(n);
}

//lcd初始化
void lcd_init()           
{
    lcd_w_cmd(0x3c);                 // 设置工作方式
    lcd_w_cmd(0x0e);                 // 设置光标
    lcd_w_cmd(0x01);                 // 清屏
    lcd_w_cmd(0x06);                 // 设置输入方式
    lcd_w_cmd(0x80);                 // 设置初始显示位置
}

//读状态
unsigned char lcd_r_start()          
{
    unsigned char s;
    RW=1;         //RW=1，RS=0，读LCD状态
    delay5us(1);
    RS=0;
    delay5us(1);
    E=1;          //E端时序
    delay5us(1);
    s=P1;         //从LCD的数据口读状态
    delay5us(1);
    E=0;
    delay5us(1);
    RW=0;
    delay5us(1);
    return(s);    //返回读取的LCD状态字
}

//写命令字
void lcd_w_cmd(unsigned char com)   
{
    unsigned char i;
    //do{                 // 查LCD忙操作
    //i=lcd_r_start();  // 调用读状态字函数
    //i=i&0x80;         // 与操作屏蔽掉低7位 
    //delay100us(2);
    //}while(i!=0);    // LCD忙，继续查询，否则退出循环
    RW=0;
    delay5us(1);
    RS=0;            // RW=1，RS=0，写LCD命令字
    delay5us(1);
    E=1;             //E端时序
    delay5us(1);
    P1=com;          //将com中的命令字写入LCD数据口
    delay5us(1);
    E=0;
    delay5us(1);
    RW=1;
    delay100us(255);
}

//写数据
void lcd_w_dat(unsigned char dat)   
{
    unsigned char i;
    //do{                // 查忙操作
    //i=lcd_r_start();   // 调用读状态字函数
    //i=i&0x80;          // 与操作屏蔽掉低7位 
    //delay100us(2);            
    //}while(i!=0);      // LCD忙，继续查询，否则退出循环
    RW=0;
    delay5us(1);
    RS=1;         // RW=1，RS=0，写LCD命令字
    delay5us(1);
    E=1;          // E端时序
    delay5us(1);
    P1=dat;       // 将dat中的显示数据写入LCD数据口
    delay5us(1);
    E=0;
    delay5us(1);
    RW=1;
    delay100us(255);
}
