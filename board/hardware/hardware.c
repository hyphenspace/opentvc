#include "../driver/hardware.h"

void initStatusLED(void) {
  DDRC |= (1 << DDC0);
}

void blueStatusLED(void) {
  LED_PORT |= (1 << BLUE_LED);
  _delay_ms(500);
  LED_PORT &= ~(1 << BLUE_LED);
  _delay_ms(250);
}
/*
void redStatusLED(void) {
  
}

void greenStatusLED(void) {
  
}
*/

void initBuzzer(void) {
  DDRD |= (1 << DDD3);
  for (int i = 0; i < 150; i++) {
    BUZZER_PORT |= (1 <<  BUZZER);
    _delay_us(1000);
    BUZZER_PORT &= ~(1 << BUZZER);
    _delay_us(1000);
  }
}
