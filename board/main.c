/* 
 spiral's AVR firmware 
 Created by Akil Hylton El
*/
#include <math.h>
#include <avr/interrupt.h>
#include "driver/servo.h"
#include "driver/usart.h"
#include "driver/hardware.h"
#include "driver/time.h"

static FILE mystdout = FDEV_SETUP_STREAM(usartTransmit, NULL, _FDEV_SETUP_WRITE); // ONLY HERE FOR DEBUGGING. 

unsigned long time;
unsigned long d;
int main (void) {
	usartInit(MYUBRR);
	stdout = &mystdout;
	init_millis(16000000UL);
	time = millis();	
	sei();
  while(1) {
			
	if (millis() - time > 1000) {
		d++;
		time = millis();
		printf("time: %lu\n", d);
  		}
	}	
  return 0;
}
