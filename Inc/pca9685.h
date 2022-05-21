#ifndef __PCA9685_H
#define __PCA9685_H
#include "i2c.h"


#define uint8 unsigned char
#define uint16 unsigned int
#define uint32 unsigned long
	
#define PCA9685_SUBADR1 0x2 
#define PCA9685_SUBADR2 0x3 
#define PCA9685_SUBADR3 0x4 
//#define pca_adrr 0x80
//#define pca_adrr 0x40
//#define pca_mode1 0x0 
//#define pca_pre 0xFE //????????
#define LED0_ON_L 0x6 //?0?
#define LED0_ON_H 0x7 
#define LED0_OFF_L 0x8 
#define LED0_OFF_H 0x9 
#define ALLLED_ON_L 0xFA 
#define ALLLED_ON_H 0xFB 
#define ALLLED_OFF_L 0xFC 
#define ALLLED_OFF_H 0xFD 

//void pca_write(uint8_t adrr,uint8_t data);
//uint8_t pca_read(uint8_t adrr);
//void pca_setfreq(float freq);
//void pca_setpwm(uint8_t num, uint32_t on, uint32_t off);
//void Thumb(void);//??
//void Index(void);//??
//void Middle(void);//??
//void Ring(void);//??
//void Little(void);//???
//void Wrist(void);//??

#define PCA9685_MODE1 0x0
#define PCA9685_PRESCALE 0xFE
#define PCA9685_adrr 0x80


void PCA9685_Reset();
void PCA9685_Go();
void SetPWMFreq(float freq);
void SetPWM(uint32_t num,uint32_t on,uint32_t off);
uint8_t PCA9685_read(uint8_t startAddress);
void PCA9685_write(uint8_t startAddress, uint8_t buffer);

#endif