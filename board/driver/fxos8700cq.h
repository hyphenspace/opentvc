#ifndef FXOS8700CQ_H
#define FXOS8700CQ_H

#include <stdio.h>
#include <util/delay.h>
#include "spi.h"

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

unsigned char accel_x_high, accel_y_high, accel_z_high;
unsigned char accel_x_low, accel_y_low, accel_z_low;

unsigned char mag_x_high, mag_y_high, mag_z_high;
unsigned char mag_x_low, mag_y_low, mag_z_low;

volatile short raw_accel_x, raw_accel_y, raw_accel_z;
volatile short raw_mag_x, raw_mag_y, raw_mag_z;

unsigned char who_am_i;
volatile short raw_temp;
volatile float celsius;

void setupFXOS8700CQ(void);
void getAccelData(void);
void getMagData(void);
void getAccelMagTemp(void);
#endif // FXOS8700CQ_H 

