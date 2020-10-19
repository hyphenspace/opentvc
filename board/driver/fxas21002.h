#ifndef FXAS21002_H
#define FXAS21002_H

#include <stdio.h>
#include <util/delay.h>
#include <spi.h>

#define GYRO_STATUS   0b10000000 
#define WHO_AM_I      0b10001100 
#define GYRO_OUT_X_H  0b10000001 
#define GYRO_OUT_X_L  0b10000010 
#define GYRO_OUT_Y_H  0b10000011  
#define GYRO_OUT_Y_L  0b10000101 
#define GYRO_OUT_Z_H  0b10000100   
#define GYRO_OUT_Z_L  0b10000110 
#define GYRO_TEMP     0b10001101 

unsigned char gyro_x_high, gyro_y_high, gyro_z_high;
unsigned char gyro_x_low, gyro_y_low, gyro_z_low;
unsigned short raw_gyro_x, raw_gyro_y, raw_gyro_z;
unsigned char who_am_i;

unsigned short raw_temp;
volatile float celsius; 


void setupFXAS21002(void);
void getGyroData(void);
void getGyroTemp(void);
#endif // FXAS21002_H
