/* 
 opentvc AVR firmware 
 Created by Akil Hylton El
*/
#include <avr/interrupt.h>
#include "driver/servo.h"
#include "driver/usart.h"
#include "driver/hardware.h"
#include "driver/lsm9ds1.h"

static FILE mystdout = FDEV_SETUP_STREAM(print, NULL, _FDEV_SETUP_RW); // ONLY HERE FOR DEBUGGING. 

lsm9ds1Vector_t a;

int main (void) {
	    sei();
	    usartInit(MYUBRR);
	    stdout = &mystdout;
	    servoInit();
	    servoAttach(Y_SERVO);
	    setupLSM9DS1();
  	while(1) {
		a = getAccelData();
		servoWirteY(a.pitch);		
    }	
    return 0;
}
