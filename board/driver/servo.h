#ifndef SERVO_H
#define SERVO_H

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#define Servo_VERSION 1  // software version of this library

#define MIN_PULSE_WIDTH 1350
#define MAX_PULSE_WIDTH 4750
#define DEFAULT_PULSE_WIDTH 3050
#define MIN_ANGLE -90
#define MAX_ANGLE 90

void servoInit(void); // Configures 16 bit PWM Registers for 50Hz 
void servoAttach(uint16_t port); // Flip port bit on to attach servo for usage. 

void servoWriteY(signed int angle); // write angle value to X axis 
void servoWriteZ(signed int angle); // writes angle value to Z axis
signed long map(signed long angle, unsigned long in_min, unsigned long in_max, unsigned long out_min, unsigned long out_max);

#endif // SERVO_H
