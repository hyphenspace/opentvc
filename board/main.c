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

static FILE mystdout = FDEV_SETUP_STREAM(usartTransmit, NULL, _FDEV_SETUP_WRITE); // ONLY HERE FOR DEBUGGING. 

lsm9ds1Vector_t a;
lsm9ds1Vector_t g;
int main (void) {
	usartInit(MYUBRR);
	stdout = &mystdout;
	setupLSM9DS1();
	sei();
  while(1) {
	 //g = getGyroData();
	 a = getAccelData();
	 printf("a_pitch: %f, a_roll: %f\n", a.pitch, a.roll);	

	_delay_ms(150);
	}	
  return 0;
}
