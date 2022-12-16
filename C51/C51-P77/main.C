#include <REG51.H>
#include <INTRINS.H>  //�⺯��ͷ�ļ���������������_nop_()����
// ��������źŶ˿�
sbit RS=P3^0;
sbit RW=P3^1;                     
sbit E= P3^2;                     
// �������ú���
void lcd_w_cmd(unsigned char com);//д�����ֺ���
void lcd_w_dat(unsigned char dat);//д���ݺ���
unsigned char lcd_r_start();      //��״̬����
void lcd_init();                  //LCD��ʼ������
void delay100us(unsigned char t); //�ɿ���ʱ����
void delay5us(unsigned char n);   //����ʵ����ʱ������n*5����������
void main()//������
{
   unsigned char Disp[]="Hello Everyone";  //�����ַ�����Disp
   unsigned char i;
   P1=0xff;   // ��ȫ1��P1��
   lcd_init();  // ��ʼ��LCD
   delay100us(255);
   lcd_w_cmd(0xc2); // ��λ���������ʾλ��
   delay100us(255);
   for(i=0;i<14;i++) // ��ʾ�ַ���
   {                    
    lcd_w_dat(Disp[i]);
    delay100us(200);
    }
   while(1);  // ��ʾ���
}

//��ʱ100us
void delay100us(unsigned char t)     
{
   unsigned char j,i;
   for(i=0;i<t;i++)
   for(j=0;j<10;j++); 
}

//��ʱ5us����
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

//lcd��ʼ��
void lcd_init()           
{
    lcd_w_cmd(0x3c);                 // ���ù�����ʽ
    lcd_w_cmd(0x0e);                 // ���ù��
    lcd_w_cmd(0x01);                 // ����
    lcd_w_cmd(0x06);                 // �������뷽ʽ
    lcd_w_cmd(0x80);                 // ���ó�ʼ��ʾλ��
}

//��״̬
unsigned char lcd_r_start()          
{
    unsigned char s;
    RW=1;         //RW=1��RS=0����LCD״̬
    delay5us(1);
    RS=0;
    delay5us(1);
    E=1;          //E��ʱ��
    delay5us(1);
    s=P1;         //��LCD�����ݿڶ�״̬
    delay5us(1);
    E=0;
    delay5us(1);
    RW=0;
    delay5us(1);
    return(s);    //���ض�ȡ��LCD״̬��
}

//д������
void lcd_w_cmd(unsigned char com)   
{
    unsigned char i;
    //do{                 // ��LCDæ����
    //i=lcd_r_start();  // ���ö�״̬�ֺ���
    //i=i&0x80;         // ��������ε���7λ 
    //delay100us(2);
    //}while(i!=0);    // LCDæ��������ѯ�������˳�ѭ��
    RW=0;
    delay5us(1);
    RS=0;            // RW=1��RS=0��дLCD������
    delay5us(1);
    E=1;             //E��ʱ��
    delay5us(1);
    P1=com;          //��com�е�������д��LCD���ݿ�
    delay5us(1);
    E=0;
    delay5us(1);
    RW=1;
    delay100us(255);
}

//д����
void lcd_w_dat(unsigned char dat)   
{
    unsigned char i;
    //do{                // ��æ����
    //i=lcd_r_start();   // ���ö�״̬�ֺ���
    //i=i&0x80;          // ��������ε���7λ 
    //delay100us(2);            
    //}while(i!=0);      // LCDæ��������ѯ�������˳�ѭ��
    RW=0;
    delay5us(1);
    RS=1;         // RW=1��RS=0��дLCD������
    delay5us(1);
    E=1;          // E��ʱ��
    delay5us(1);
    P1=dat;       // ��dat�е���ʾ����д��LCD���ݿ�
    delay5us(1);
    E=0;
    delay5us(1);
    RW=1;
    delay100us(255);
}