#ifndef LSM9DS1_H
#define LSM9DS1_H

#include <stdio.h>
#include <math.h>
#include <util/delay.h>
#include "spi.h"
#include "time.h"


#define WHO_AM_I 0b10001111 
#define CTRL_REG7_XL 0b00100001 
#define ORIENT_CFG_G 0b00010011 
#define STATUS_REG 0b10010111 
#define CTRL_REG1_G 0b00010000 
#define OUT_TEMP_H 0b10010110
#define OUT_TEMP_L 0b10010101
//Gyroscope reg
#define OUT_X_L_G 0b10011000
#define OUT_X_H_G 0b10011001
#define OUT_Y_L_G 0b10011010
#define OUT_Y_H_G 0b10011011
#define OUT_Z_L_G 0b10011100
#define OUT_Z_H_G 0b10011101
//Accelerometer reg
#define CTRL_REG6_XL 0b10100011
#define OUT_X_L_XL 0b11001000
#define OUT_X_H_XL 0b10101001
#define OUT_Y_L_XL 0b10101010
#define OUT_Y_H_XL 0b10101011
#define OUT_Z_L_XL 0b10101100
#define OUT_Z_H_XL 0b10101101
// Magnetometer 
#define STATUS_REG_M 0b10100111 // Read Status of Magnetometer 
#define CTRL_REG1_M 0b00100000
#define CTRL_REG3_M 0b00100010
#define OUT_X_H_M 0b10101001
#define OUT_X_L_M 0b10101000
#define OUT_Y_H_M 0b10101011
#define OUT_Y_L_M 0b10101010
#define OUT_Z_H_M 0b10101101
#define OUT_Z_L_M 0b10101100

#define GYRO_SENSITIVITY 8.75 // Angular rate 245 dps
#define ACCEL_SENSITIVITY 0.061 // Linear acceleration 2g
#define TEMP_SENSITIVITY 16
// Gyro offsets
#define GYRO_X_OFFSET 4.5
#define GYRO_Y_OFFSET -2.2
#define GYRO_Z_OFFSET 6.6

unsigned char accel_x_high, accel_y_high, accel_z_high;
unsigned char accel_x_low, accel_y_low, accel_z_low;
unsigned char mag_x_high, mag_y_high, mag_z_high;
unsigned char mag_x_low, mag_y_low, mag_z_low;
unsigned char gyro_x_high, gyro_y_high, gyro_z_high;
unsigned char gyro_x_low, gyro_y_low, gyro_z_low;
unsigned char raw_temp_high, raw_temp_low;

volatile short raw_temp;
volatile short raw_mag_x, raw_mag_y, raw_mag_z;
volatile short raw_accel_x, raw_accel_y, raw_accel_z;
volatile short raw_gyro_x, raw_gyro_y, raw_gyro_z;

unsigned char who_am_i, who_am_i_mag, mag_status;

volatile float x_g_force, y_g_force, z_g_force;
volatile float celsius;


typedef struct vector_s {
    volatile float x;
    volatile float y;
    volatile float z;
    volatile float pitch;
    volatile float roll;
} lsm9ds1Vector_t;

lsm9ds1Vector_t gyroData;
lsm9ds1Vector_t accelData;
lsm9ds1Vector_t magData;

void setupLSM9DS1(void);
lsm9ds1Vector_t getAccelData(void);
lsm9ds1Vector_t getGyroData(void);
lsm9ds1Vector_t getMagData(void);
void getTempData(void);

#endif // LSM9DS1_H 

