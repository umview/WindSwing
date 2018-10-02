#include "Debug.h"
extern struct TestStruct Test;
int8_t delta=25;
extern float SDS[4];
void EXTI9_5_IRQHandler(void)
{    
	Delay_ms(1);
  if(EXTI_GetITStatus(EXTI_IMR_MR8) != RESET)
  {	
		LED_Toggle(1);                                         //??PD11(LED1)??
		Test.testduty2+=delta;
		if(Test.testduty1>=8000)delta*=-1;
    //Test.testduty=0;
		EXTI_ClearITPendingBit(EXTI_IMR_MR8);                  //???????	
    
  }
}
void UnlockMotor(void){
	
	while(Test.testduty<6100){
	Test.testduty+=50;
	TIM3->CCR1 = Test.testduty;//41	
	TIM3->CCR2 = Test.testduty;//2
	TIM3->CCR3 = Test.testduty;//3!
	TIM3->CCR4 = Test.testduty;//1
	Delay_ms(200);	
	SDS[1]=Test.testduty;
	SDS[2]=Test.testduty1;
	SDS[3]=Test.testduty2;
	Plot(SDS);
	}
}
