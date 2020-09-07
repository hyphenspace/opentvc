#include "../driver/servo.h"


/** @defgroup group1 Servo Library
 *  This library contains all the neccessary code for controlling the two servos needed for pitch and yaw.
 *  @{
 */

/** Configures 16 bit PWM Registers for 50Hz  */
void servoInit(void) {
  TCCR1A |= ((1 << COM1A1) | (1 << COM1B1) | (1 << WGM11)); 
  TCCR1B |= ((1 << WGM12) | (1 << WGM13) | (1 << CS11));
  TCNT1 = 0;
  ICR1 = 40000;
  OCR1A = DEFAULT_PULSE_WIDTH;
  OCR1B = DEFAULT_PULSE_WIDTH;
}

/** This function writes angle values to the Y axis for pitch. */
void servoWriteY(signed int angle) {
  if (angle == MIN_ANGLE) {
    OCR1A = MIN_PULSE_WIDTH;
    _delay_ms(10);
  }
  if (angle == MAX_ANGLE) {
    OCR1A = MAX_PULSE_WIDTH;
    _delay_ms(10); 
  }
  OCR1A = map(angle, MIN_ANGLE, MAX_ANGLE, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  _delay_ms(10);
}

/** This function writes angle values to the Z axis for yaw. */
void servoWriteZ(signed int angle) {
  if (angle == MIN_ANGLE) {
    OCR1B = MIN_PULSE_WIDTH;
    _delay_ms(10); 
  }
  if (angle == MAX_ANGLE) {
    OCR1B = MAX_PULSE_WIDTH;
    _delay_ms(10);  
  }
  OCR1B = map(angle, MIN_ANGLE, MAX_ANGLE, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  _delay_ms(10);
}
/** Flip port bit on to attach servo for usage. */
void servoAttach(uint16_t port) {
  DDRB |= (1 << port);
}

/** Ardunio like map function. Re-maps a number from one range to another. That is, a value of fromLow would get mapped to toLow, a value of fromHigh to toHigh, values in-between to values in-between, etc.*/
signed long map(signed long angle, unsigned long in_min, unsigned long in_max, unsigned long out_min, unsigned long out_max) {
  static signed int value = 0;
  value = (angle - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return value;
}
