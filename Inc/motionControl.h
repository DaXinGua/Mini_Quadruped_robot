#ifndef _motionControl_H
#define _motionControl_H
#include "pca9685.h"

#define LeftFront_hip 0
#define LeftFront_knee 1
#define RightBack_hip 2
#define RightBack_knee 3
#define RightFront_hip 4
#define RightFront_knee 5
#define LeftBack_hip 6
#define LeftBack_knee 7


void motionInit(float fre);//��ʼ��
void robotStand(void);//����վ��
void setTheta(uint32_t number, uint32_t theta);//���ƶ���Ƕ�

void hipControl(void);//�Źؽڿ���
void kneeControl(void);//ϥ�ؽڿ���

void forward(void); //ǰ��
void backward(void); //����
void rotate(void); //��ת

#endif
