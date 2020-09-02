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
#include "driver/lsm9ds1.h"

static FILE mystdout = FDEV_SETUP_STREAM(usartTransmit, NULL, _FDEV_SETUP_WRITE); // ONLY HERE FOR DEBUGGING. 

lsm9ds1Vector_t a;
unsigned long time;
unsigned long d;
int main (void) {
	usartInit(MYUBRR);
	stdout = &mystdout;
	setupLSM9DS1();
	sei();
  while(1) {
	a = getAccelData();
	printf("a_x: %f, a_y: %f, a_z: %f\n", a.x, a.y, a.z);	
	_delay_ms(150);
	}	
  return 0;
}
