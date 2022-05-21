#include "motionControl.h"
#include "pca9685.h"

const uint8 stepNumber = 30;//�Źؽڹ켣ȡ����
const uint8 hipTheta = 60; //�Źؽ�ת���Ƕ�
uint8 hitStep = hipTheta/stepNumber; //�Źؽڵ��ת������
const uint8 kneeTheta = 30; //ϥ�ؽ�ת���Ƕ�
uint8 kneeStep = kneeTheta/stepNumber; //ϥ�ؽڵ��ת������

//
void motionInit(float fre) {
	PCA9685_Go();
	SetPWMFreq(fre);
}

//���ƶ��ת�ǣ�����ֵת��Ϊ�Ƕ�ֵ  
void setTheta(uint32_t number, uint32_t theta) {
	uint32_t count = 0;
	if (theta < 180) {
		count = 102 + theta*4096/90/20;
		SetPWM(number, 0, count);		
	}
}

//�Źؽ��˶�����
//void hipControl() {
//}

//ϥ�ؽ��˶�����
//void kneeControl() {
//}



//����վ��
void robotStand() {
	//��һ��: ��ǰ���Һ�
	setTheta(LeftFront_hip, 90); //105
	setTheta(LeftFront_knee, 102); //120
	setTheta(RightBack_hip, 90);  //115
	setTheta(RightBack_knee, 85); //120
	HAL_Delay(5);
	
	//�ڶ��飺��ǰ�����
	setTheta(RightFront_hip, 90);
	setTheta(RightFront_knee, 82);
	setTheta(LeftBack_hip, 90);
	setTheta(LeftBack_knee, 90);
	HAL_Delay(5);
}

//ǰ��
void forward() {

	//ǰ������
	for (uint8 i = 0; i <= stepNumber; ++i) {
		//�Źؽ�
		setTheta(LeftFront_hip, 60 + hitStep*i);
		setTheta(RightBack_hip, 120 - hitStep*i);
		setTheta(RightFront_hip, 60 + hitStep*i);
		setTheta(LeftBack_hip, 120 - hitStep*i);
		//ϥ�ؽ�
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
	
	//�������
	for (uint8 i = 0; i <= stepNumber; ++i) {
		//�Źؽ�
		setTheta(LeftFront_hip, 120 - hitStep*i);
		setTheta(RightBack_hip, 60 + hitStep*i);
		setTheta(RightFront_hip, 120 - hitStep*i);
		setTheta(LeftBack_hip, 60 + hitStep*i);
		//ϥ�ؽ�
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

//��ת
//void rotate(void) {
//		
//	
//}

