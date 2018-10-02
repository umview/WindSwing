#include "stm32f10x.h"
#include "math.h"
#include "Filter.h"
#include "MPU6050.h"
#include "Config.h"
extern struct Infostruct Info;
void Angle()
{
  MPU_Get_Gyroscope(&Info.gx,&Info.gy,&Info.gz);
	MPU_Get_Accelerometer(&Info.ax,&Info.ay,&Info.az);
	Info.gx-=Info.Gyrox;
	Info.gy-=Info.Gyroy;
	Info.thx=atan(1.0f*Info.ax/(1.0f*Info.az))*180/3.1415926535;
	Info.thy=atan(1.0f*(-Info.ay)/(1.0f*Info.az))*180/3.1415926535;
	//Info.GyroxIntegral-=Info.gx*0.005f/15.41667;
	//Info.GyroyIntegral-=Info.gy*0.005f/15.41667;
	
	Info.angley=k1*(Info.angley-Info.gy*0.005f/15.41667)+(1-k1)*Info.thx;
	Info.anglex=k1*(Info.anglex-Info.gx*0.005f/15.41667)+(1-k1)*Info.thy;
	
}

