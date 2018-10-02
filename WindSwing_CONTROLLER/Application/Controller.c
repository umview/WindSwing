#include "Controller.h"
#include "Config.h"
#include "Filter.h"
#include "math.h"
extern struct TestStruct Test;
extern struct Infostruct Info;
extern struct PIDstruct PID;
uint16_t i=0;
extern float SDS[4];
void TIM5_IRQHandler(void)
{
    if ( TIM_GetITStatus(TIM5 , TIM_IT_Update) != RESET )   
    {     
        TIM_ClearITPendingBit(TIM5 , TIM_FLAG_Update);   
				i++;
			if(i==5){
				Angle();
				Controller();
				UpdateDuty();
				LED_Toggle(1),i=0;
			}
    }     
}
void Controller(void){
	//Info.angley=Info.Yout;
	uint8_t i=0;
	static float Yerror[50]={0},Xerror[50]={0};

	for(i=0;i<49;i++){
		Yerror[i]=Yerror[i+1];
		Xerror[i]=Xerror[i+1];
	}
	Yerror[49]=Info.angley+Ybias-Info.setpointy;
	Xerror[49]=Info.anglex+Xbias-Info.setpointx;
	Info.XInt=0;Info.YInt=0;
	for(i=0;i<50;i++){
		Info.XInt+=Xerror[i];
		Info.YInt+=Yerror[i];
	}
	Info.gy=LIMIT(Info.gy,-2000,2000);
	Info.gx=LIMIT(Info.gx,-2000,2000);
	//Info.Yout=(int16_t)(-Info.gy/2.0f*2.0+Yerror[1]*30);//(int16_t)(Yerror[1]*20.0);//+Info.gy*1.0);
	//Info.Yout=(int16_t)(Info.gy/2.0f);//*2.0+Yerror[1]*30);//(int16_t)(Yerror[1]*20.0);//+Info.gy*1.0);
	Info.Yout=(int16_t)(-Yerror[1]*KP+Info.gy*KD-KI*Info.YInt);//(int16_t)(Yerror[1]*20.0);//+Info.gy*1.0);
	//Info.Xout=(int16_t)(-Xerror[1]*20);
	Info.Xout=(int16_t)(Info.gx*KD-Xerror[1]*KP-KI*Info.XInt);
}
void UpdateDuty(void){
	uint16_t M[5]={0};
	M[1]=Info.Thr;
	M[2]=Info.Thr;
	M[3]=Info.Thr;
	M[4]=Info.Thr;
	if(Info.Yout>=0){
		M[1]+=Info.Yout;
		M[3]=Info.Thr;
		M[1]=LIMIT(M[1],Info.Thr,ThrMax);
		M[3]=LIMIT(M[3],Info.Thr,ThrMax);
	}else{
		M[3]-=Info.Yout;
		M[1]=Info.Thr;
		M[1]=LIMIT(M[1],Info.Thr,ThrMax);
		M[3]=LIMIT(M[3],Info.Thr,ThrMax);
	}
	if(Info.Xout>=0){
		M[2]+=Info.Xout;
		M[4]=Info.Thr;
		M[2]=LIMIT(M[2],Info.Thr,ThrMax);
		M[4]=LIMIT(M[4],Info.Thr,ThrMax);
	}else{
		M[4]-=Info.Xout;
		M[2]=Info.Thr;
		M[2]=LIMIT(M[2],Info.Thr,ThrMax);
		M[4]=LIMIT(M[4],Info.Thr,ThrMax);
	}
		 TIM3->CCR1 = M[1];
	 	 TIM3->CCR2 = M[2];
		 	 TIM3->CCR3 = M[3];
			 TIM3->CCR4 = M[4];
	if(Info.MotorEnable==-1){
			 TIM3->CCR1 = 0;
	 	 TIM3->CCR2 = 0;
		 	 TIM3->CCR3 = 0;
			 TIM3->CCR4 = 0;
	}
}
void Loop(){
 // MPU_Get_Gyroscope(&gx,&gy,&gz);
	//MPU_Get_Accelerometer(&ax,&ay,&az);
	
	SDS[0]=(int16_t)((Info.anglex+Xbias)*100);
	SDS[1]=(int16_t)((Info.angley+Ybias)*100);
	//SDS[0]=(int16_t)(Info.anglex*100);
	//SDS[1]=(int16_t)(Info.angley*100);
	SDS[2]=(int16_t)Info.XInt;
	SDS[3]=(int16_t)Info.YInt;
	Plot(SDS);
	Delay_ms(5);
	//LCD_ShowNum(10, 10, gx, 16, RED, BLACK);//显示数字
}
//void PID1(float setpoint,float angle_x){
//  float  iError,Errorsum,dError,last_iError;
//	PID.setpointone = setpoint;
//	iError=PID.setpointone-angle_x;
//	Errorsum+=iError;
//	dError=iError-last_iError;
//	last_iError = iError;
//	PID.duty1=(int16_t)(PID.Kp*iError+PID.Ki*Errorsum+PID.Kd*dError); 
//	PID.duty2=(int16_t)(PID.Kp*iError+PID.Ki*Errorsum+PID.Kd*dError); 
//}

//void PID2(float setpoint,float angle_x){
//	float  iError,Errorsum,dError,last_iError;
//	PID.setpointtwo = setpoint;
//	iError=PID.setpointtwo-angle_x;
//	Errorsum+=iError;
//	dError=iError-last_iError;
//	last_iError = iError;
//	PID.duty1=(int16_t)(PID.Kp*iError+PID.Ki*Errorsum+PID.Kd*dError); 
//	PID.duty2=(int16_t)(PID.Kp*iError+PID.Ki*Errorsum+PID.Kd*dError); 
//}
//void PID3(float setpoint,float angle_x,float angle_y){
//	float  iError,Errorsum,dError,last_iError;
//	float Ax,Ay;
//	Ax = angle_x*cos(angle*0.017453);	             //计算出X方向摆幅分量0.017453为弧度转换
//	Ay = angle_y*sin(angle*0.017453);
//	PID.setpointtwo = setpoint;
//	iError=PID.setpointtwo-angle_x;
//	Errorsum+=iError;
//	dError=iError-last_iError;
//	last_iError = iError;
//	PID.duty1=PID.Kp*iError+PID.Ki*Errorsum+PID.Kd*dError; 
//	PID.duty2=PID.Kp*iError+PID.Ki*Errorsum+PID.Kd*dError; 
//	
//}







//	
