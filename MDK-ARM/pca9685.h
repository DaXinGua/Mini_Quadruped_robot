#ifndef _PCA9685_H
#define _PCA9685_H
#include "i2c.h"

#define uint8 unsigned char
#define uint16 unsigned int
#define uint32 unsigned long
	
#define PCA9685_SUBADR1 0x2 
#define PCA9685_SUBADR2 0x3 
#define PCA9685_SUBADR3 0x4 

#define LED0_ON_L 0x6 //?0?
#define LED0_ON_H 0x7 
#define LED0_OFF_L 0x8 
#define LED0_OFF_H 0x9 
#define ALLLED_ON_L 0xFA 
#define ALLLED_ON_H 0xFB 
#define ALLLED_OFF_L 0xFC 
#define ALLLED_OFF_H 0xFD 

#define PCA9685_MODE1 0x0
#define PCA9685_PRESCALE 0xFE //‘§∑÷∆µ…Ë÷√µÿ÷∑
#define PCA9685_adrr 0x80

void PCA9685_Reset(void);
void PCA9685_Go(void);
void SetPWMFreq(float freq);
void SetPWM(uint32_t num,uint32_t on,uint32_t off);
uint8_t PCA9685_read(uint8_t startAddress);
void PCA9685_write(uint8_t startAddress, uint8_t buffer);

#endif
