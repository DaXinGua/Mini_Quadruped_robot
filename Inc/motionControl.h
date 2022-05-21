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


void motionInit(float fre);//初始化
void robotStand(void);//四足站立
void setTheta(uint32_t number, uint32_t theta);//控制舵机角度

void hipControl(void);//髋关节控制
void kneeControl(void);//膝关节控制

void forward(void); //前进
void backward(void); //后退
void rotate(void); //旋转

#endif
