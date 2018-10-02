#include "Debug.h"
#include "math.h"
extern struct TestStruct Test;
extern struct Infostruct Info;
extern float SDS[4];
void EXTI9_5_IRQHandler(void)
{    
  if(EXTI_GetITStatus(EXTI_IMR_MR8) != RESET)
  {	
		Delay_ms(100);
		Info.MotorEnable*=-1;
		LED_Toggle(1);                                         //??PD11(LED1)??
    EXTI_ClearITPendingBit(EXTI_IMR_MR8);                  //???????	
    
  }
}
void UnlockMotor(void){
	
	while(Test.testduty<Info.Thr){
	Test.testduty+=50;
	TIM3->CCR1 = Test.testduty;//41
	TIM3->CCR2 = Test.testduty;//2
	TIM3->CCR3 = Test.testduty;//3!
	TIM3->CCR4 = Test.testduty;//1
	Delay_ms(100);	
	SDS[1]=Test.testduty;
	SDS[2]=Test.testduty1;
	SDS[3]=Test.testduty2;
	Plot(SDS);
	}
}
void reset(void)
{
//	static uint8_t i=0;
//	while(1){
//	MPU_Get_Gyroscope(&Info.gx,&Info.gy,&Info.gz);
//	i++;
//	Info.Gyrox+=Info.gx;
//	Info.Gyroy+=Info.gy;
//	Info.Gyroz+=Info.gz;
//	Delay_ms(5);
//	if(i==200)
//	{
//		i=0;
//		Info.Gyrox/=200.0f;
//		Info.Gyroy/=200.0f;
//		Info.Gyroz/=200.0f;
//		break;
//	}
//}
	Info.GyroyIntegral=atan(1.0f*Info.ax/(1.0f*Info.az))*180/3.1415926535;
	Info.GyroxIntegral=atan(1.0f*Info.ay/(1.0f*Info.az))*180/3.1415926535;
	Info.anglex =	Info.GyroxIntegral;
	Info.angley =	Info.GyroyIntegral;
Info.Gyrox=-22.0f;
Info.Gyroy=19.0f;
}

