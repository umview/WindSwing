/*******************************************************************************
  * Company: Wang Electronic Technology Co., Ltd.
  ******************************************************************************
  * �ļ����ƣ�main.c
  * ����˵������ţ��-LCDˢ��ʵ��
  * ��    ����V1.0
  * ��    �ߣ�openmcu666	
  * ��    ��: 2016-05-04
********************************************************************************
  * �ļ����ƣ�
  * ����˵����
  * ��    ����
  * ��������:	
  * ��    �ڣ�
  * ����ԭ��
********************************************************************************/
#include "Gpio.h"
#include "delay.h"
#include "USART.h"
#include "WB_LCD.h"
#include "Controller.h"
#include "mpu6050.h"
#include "Timer.h"
#include "Debug.h"
#include "Config.h"
/*****************************************************************************
**   Main Function  main()
******************************************************************************/
MPU6050_AxisTypeDef    Axis;
struct TestStruct Test;
int main(void)
{
  LED_Init();
  LCD_Init();
	USART1_Init();
	//MPU6050_Init();
  Delay_Init();   
	Key_Init();
	TIM5_Init();//max 9000
	//Delay_ms(5000);
	TIM_Init();
	Delay_ms(5000);
	UnlockMotor();	
	LCD_DisplayStr(96,120,"Powered by UMVIEW.COM",RED,BLACK);
	LCD_DisplayStr(110,180,"����",RED,BLACK);
	LCD_DisplayStr(100, 150, "LCD-Test",RED,BLACK);
	//LCD_DisplayStr(50, 210, "��������-��ţ������",RED,BLACK);
	Delay(3000);
	Test.testduty1=Test.testduty;
	Test.testduty2=Test.testduty;
	for(;;)Loop();
}
/*
		 switch(x)
		 {
		   	 case 0:LCD_Clear(WHITE);break;
			   case 1:LCD_Clear(BLACK);break;
			   case 2:LCD_Clear(BLUE);break;
			   case 3:LCD_Clear(RED);break;
			   case 4:LCD_Clear(MAGENTA);break;
			   case 5:LCD_Clear(GREEN);break;
			   case 6:LCD_Clear(CYAN);break;

			   case 7:LCD_Clear(YELLOW);break;
			   case 8:LCD_Clear(BRRED);break;
			   case 9:LCD_Clear(GRAY);break;
			   case 10:LCD_Clear(LGRAY);break;
			   case 11:LCD_Clear(BROWN);break;
			 
		 }

*/
