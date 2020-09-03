#include "../driver/servo.h"

signed long map(signed long angle, unsigned long in_min, unsigned long in_max, unsigned long out_min, unsigned long out_max) {
  static signed int value = 0;
  value = (angle - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return value;
}


void servoInit(void) {
  TCCR1A |= ((1 << COM1A1) | (1 << COM1B1) | (1 << WGM11)); 
  TCCR1B |= ((1 << WGM12) | (1 << WGM13) | (1 << CS11));
  TCNT1 = 0;
  ICR1 = 40000;
  OCR1A = DEFAULT_PULSE_WIDTH;
  OCR1B = DEFAULT_PULSE_WIDTH;
}

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

void servoAttach(uint16_t port) {
  DDRB |= (1 << port);
}
