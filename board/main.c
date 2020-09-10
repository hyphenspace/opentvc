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

//double delta_t;
//unsigned long t;
lsm9ds1Vector_t a;
<<<<<<< HEAD

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
=======
lsm9ds1Vector_t g;
int main (void) {
	sei();
	usartInit(12);
	stdout = &mystdout;
	//init_micros();
	//setupLSM9DS1();
	//t = micros();

  while(1) {
	printf("Hello: %d\n",100);
	//delta_t = ((double)(micros() - t) / 1000000.0);
	//t = micros();
	//printf("%f\n",delta_t);
	 //g = getGyroData();
	 //a = getAccelData();
	 //printf("a_pitch: %f, a_roll: %f\n", a.pitch, a.roll);	
	 //printf("a_pitch: %f, a_roll: %f\n", a.pitch, a.roll);	
	 //printf("g_x: %f, g_y: %f\n", g.x / 100.0, g.y);	

	_delay_ms(25);
	}	
  return 0;
>>>>>>> 48ea5f06d279f72c2659be5e5da53c5e1cf3dbb0
}
