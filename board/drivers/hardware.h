#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define BUZZER_PORT PORTD
#define BUZZER PD3
#define LED_PORT PORTC
#define BLUE_LED PC0

void blueStatusLED(void);
void initStatusLED(void);
void initBuzzer(void);
