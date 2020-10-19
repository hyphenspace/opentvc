/* 
 opentvc AVR firmware 
 Created by Akil Hylton El
*/
#include <math.h>
#include <avr/interrupt.h>
#include "driver/servo.h"
#include "driver/usart.h"
#include "driver/hardware.h"

static FILE mystdout = FDEV_SETUP_STREAM(print, NULL, _FDEV_SETUP_RW); // ONLY HERE FOR DEBUGGING. 

int main (void) {
    sei();
    usartInit(MYUBRR);
    stdout = &mystdout;
    servoInit();
    servoAttach(Y_SERVO);
    while(1) {
	servoWriteY(0);
    }	
    return 0;
}
