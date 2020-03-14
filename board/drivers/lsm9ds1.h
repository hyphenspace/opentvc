#ifndef LSM9DS1 
#define LSM9DS1

#define WHO_AM_I 0b10001111 
#define ORIENT_CFG_G 0b00010011 // Read from orient
#define STATUS_REG 0b10010111 // Read status reg
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
#define CTRL_REG6_XL 0b00100000
#define OUT_X_L_XL 0b10101000
#define OUT_X_H_XL 0b10101001
#define OUT_Y_L_XL
#define OUT_Y_H_XL
#define OUT_Z_L_XL
#define OUT_Z_H_XL 

#endif

