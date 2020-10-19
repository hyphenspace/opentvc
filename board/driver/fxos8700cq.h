#ifndef FXOS8700CQ_H
#define FXOS8700CQ_H

#include <stdio.h>
#include <util/delay.h>
#include <spi.h>

#define WHO_AM_I 		0b10001101
#define AM_TEMP  		0b11010001

#define ACCEL_OUT_X_H  	 	0b10000001
#define ACCEL_OUT_X_L 		0b10000010
#define ACCEL_OUT_Y_H		0b10000011
#define ACCEL_OUT_Y_L   	0b10000100
#define ACCEL_OUT_Z_H   	0b10000101
#define ACCEL_OUT_Z_L   	0b10000110

#define XYZ_DATA_CFG 		0b00001110

#define MAG_OUT_X_H		0b10110011
#define MAG_OUT_X_L		0b10110100
#define MAG_OUT_Y_H		0b10110101
#define MAG_OUT_Y_L     	0b10110110
#define MAG_OUT_Z_H     	0b10110111
#define MAG_OUT_Z_L		0b10111000

#define ACCEL_SENSITIVITY 	1024 // 8g - LSB/g
#define MAG_SENSITIVITTY	0.1  // μT/LSB

unsigned char who_am_i, ra;
signed short raw_temp;
volatile float celsius;

void setupFXOS8700CQ(void);
void getAccelMagTemp(void);
#endif // FXOS8700CQ_H 

