/* 
 opentvc AVR firmware 
 Created by Akil Hylton El
*/
#include "driver/servo.h"
#include "driver/hardware.h"

int main (void) {
    servoInit();
    servoAttach(Y_SERVO);
    while(1) {
	servoWriteY(0);
    }	
    return 0;
}
