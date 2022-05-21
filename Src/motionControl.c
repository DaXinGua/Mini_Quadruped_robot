#include "motionControl.h"
#include "pca9685.h"

const uint8 stepNumber = 30;//髋关节轨迹取点数
const uint8 hipTheta = 60; //髋关节转动角度
uint8 hitStep = hipTheta/stepNumber; //髋关节电机转动步长
const uint8 kneeTheta = 30; //膝关节转动角度
uint8 kneeStep = kneeTheta/stepNumber; //膝关节电机转动步长

//
void motionInit(float fre) {
	PCA9685_Go();
	SetPWMFreq(fre);
}

//控制舵机转角，计数值转换为角度值  
void setTheta(uint32_t number, uint32_t theta) {
	uint32_t count = 0;
	if (theta < 180) {
		count = 102 + theta*4096/90/20;
		SetPWM(number, 0, count);		
	}
}

//髋关节运动控制
//void hipControl() {
//}

//膝关节运动控制
//void kneeControl() {
//}



//四足站立
void robotStand() {
	//第一组: 左前、右后
	setTheta(LeftFront_hip, 90); //105
	setTheta(LeftFront_knee, 102); //120
	setTheta(RightBack_hip, 90);  //115
	setTheta(RightBack_knee, 85); //120
	HAL_Delay(5);
	
	//第二组：右前、左后
	setTheta(RightFront_hip, 90);
	setTheta(RightFront_knee, 82);
	setTheta(LeftBack_hip, 90);
	setTheta(LeftBack_knee, 90);
	HAL_Delay(5);
}

//前进
void forward() {

	//前半周期
	for (uint8 i = 0; i <= stepNumber; ++i) {
		//髋关节
		setTheta(LeftFront_hip, 60 + hitStep*i);
		setTheta(RightBack_hip, 120 - hitStep*i);
		setTheta(RightFront_hip, 60 + hitStep*i);
		setTheta(LeftBack_hip, 120 - hitStep*i);
		//膝关节
		if (i <= stepNumber/2) {
			setTheta(LeftFront_knee, 102 + kneeStep*i*2);
			setTheta(RightBack_knee, 85 + kneeStep*i*2);
			setTheta(RightFront_knee, 82);
			setTheta(LeftBack_knee, 90);
		} else {
			setTheta(LeftFront_knee, 162 - 2*kneeStep*i);
			setTheta(RightBack_knee, 145 -  2*kneeStep*i);
			setTheta(RightFront_knee, 82);
			setTheta(LeftBack_knee, 90);
		}
		HAL_Delay(5);
	}
	
	//后半周期
	for (uint8 i = 0; i <= stepNumber; ++i) {
		//髋关节
		setTheta(LeftFront_hip, 120 - hitStep*i);
		setTheta(RightBack_hip, 60 + hitStep*i);
		setTheta(RightFront_hip, 120 - hitStep*i);
		setTheta(LeftBack_hip, 60 + hitStep*i);
		//膝关节
		if (i <= stepNumber/2) {
			setTheta(LeftFront_knee, 102);
			setTheta(RightBack_knee, 85);
			setTheta(RightFront_knee, 82 - kneeStep*i*2);
			setTheta(LeftBack_knee, 90 - kneeStep*i*2);
		} else {
			setTheta(LeftFront_knee, 102);
			setTheta(RightBack_knee, 85);
			setTheta(RightFront_knee, 22 + 2*kneeStep*i);
			setTheta(LeftBack_knee, 30 + 2*kneeStep*i);
		}
		HAL_Delay(5);
	}
}

//旋转
//void rotate(void) {
//		
//	
//}

