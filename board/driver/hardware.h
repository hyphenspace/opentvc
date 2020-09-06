#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define BUZZER_PORT PORTD
#define BUZZER PD3
#define LED_PORT PORTC
#define BLUE_LED PC1
#define GREEN_LED PC0 
#define RED_LED PC2
#define BEEP_COUNT 150

void blueStatusLED(void);
void initStatusLED(void);
void initBuzzer(void);
