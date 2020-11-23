/* 
 opentvc AVR firmware 
 Created by Akil Hylton El
*/
#include <util/delay.h>
#include "driver/servo.h"

int main (void) {
    servoInit();
    servoAttach(Z_SERVO);
    servoAttach(Y_SERVO);
    servoWriteY(0);
    servoWriteZ(0);
    _delay_ms(5000);
    
    while(1) {
		// Test TVC Y and Z axises.	    
		for (int i = -20; i <= 20; i++) {
    		servoWriteY(i);
			servoWriteZ(-i);
		}
		for (int i = 20; i >= -20; i-- ) {
			servoWriteY(i);
			servoWriteZ(-i);
		}	
	}	
	return 0;
}
