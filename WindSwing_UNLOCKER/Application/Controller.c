#include "Controller.h"
#include "Config.h"
extern struct TestStruct Test;
uint16_t i=0;
extern float SDS[4];
extern int8_t delta;
void TIM5_IRQHandler(void)
{
    if ( TIM_GetITStatus(TIM5 , TIM_IT_Update) != RESET )   
    {     
        TIM_ClearITPendingBit(TIM5 , TIM_FLAG_Update);   
				i++;
			if(i==5){
				LED_Toggle(1),i=0;
	//TIM3->CCR1 = Test.testduty;//4
	//TIM3->CCR2 = Test.testduty1;//1
	//TIM3->CCR3 = Test.testduty;//3
	//TIM3->CCR4 = Test.testduty2;//2
			}
    }     
}
//void Loop(void){
//	//int16_t gyrox=getAccX();
//	//SDS[0]=gyrox;
//	SDS[0]=Test.testduty;
//	SDS[1]=Test.testduty;
//	SDS[2]=Test.testduty1;
//	SDS[3]=Test.testduty2;
//	Plot(SDS);
//	Delay_ms(5);
//	//TIM3->CCR2 = Test.testduty;//2
//	//Test.testduty+=4;
//	TIM3->CCR1 = Test.testduty1;//4
//	//TIM3->CCR2 = Test.testduty;//1
//	TIM3->CCR3 = Test.testduty2;//3
//	//TIM3->CCR4 = Test.testduty;//2
//	//LCD_ShowNum(50, 210, (u32)Test.testduty, 1, RED, BLACK);//ÏÔÊ¾Êı×Ö

//}
void Loop(void){
	while(1){
		Delay_ms(500);
		//TIM3->CCR1= Test.testduty1;
//		Test.testduty1+=delta;
//		Test.testduty2-=delta;
//		if(Test.testduty2<=Test.testduty)Test.testduty2=Test.testduty;
//		TIM3->CCR1= Test.testduty1;
//		TIM3->CCR3=Test.testduty2;
//		
		TIM3->CCR1 = Test.testduty;//41	
	TIM3->CCR2 = Test.testduty;//2
	TIM3->CCR3 = Test.testduty;//3!
	TIM3->CCR4 = Test.testduty;//1
	SDS[0]=Test.testduty;
	SDS[1]=Test.testduty;
	SDS[2]=Test.testduty1;
	SDS[3]=Test.testduty2;
	Plot(SDS);
		
		
		
		if(Test.testduty1>=7025){
			//TIM3->CCR1=Test.testduty;
			break;
		}
		}
	while(1){
		Delay_ms(500);
		Test.testduty2+=delta;
		Test.testduty1-=delta;
		TIM3->CCR3= Test.testduty2;
		TIM3->CCR1=Test.testduty1;
		
	SDS[0]=Test.testduty;
	SDS[1]=Test.testduty;
	SDS[2]=Test.testduty1;
	SDS[3]=Test.testduty2;
	Plot(SDS);
		
		
		
		if(Test.testduty2>=7150){
			//TIM3->CCR3=Test.testduty;
			break;
		}
		
	}
}
