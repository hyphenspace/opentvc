/* 
 spiral's AVR firmware 
 Created by Akil Hylton El
*/
#include <math.h>
#include <avr/interrupt.h>
#include "driver/servo.h"
#include "driver/usart.h"
#include "driver/hardware.h"
#include "driver/lsm9ds1.h"
#include "driver/time.h"

static FILE mystdout = FDEV_SETUP_STREAM(print, NULL, _FDEV_SETUP_RW); // ONLY HERE FOR DEBUGGING. 

double delta_t;
unsigned long t;
lsm9ds1Vector_t a;
lsm9ds1Vector_t g;
int main (void) {
	sei();
	initStatusLED();
	usartInit(12);
	stdout = &mystdout;	
	blueStatusLED();
	
  while(1) {
	blueStatusLED();
	printf("T 30\n");
	printf("P -5\n");
	printf("Y 2\n");
	printf("R 3\n");
	}	
  return 0;
}
