#include "../driver/fxos8700cq.h"

/** @defgroup group7 FXOS8700CQ Library
   *  This library contains all the neccessary code for using the triple axis linear accelerometer and magnetometer from the FXOS8700CQ.
   *  @{
*/

/** This function enables the accelerometer and magnetometer. */
void setupFXOS8700CQ(void) {
    spiInit();
	SLAVE_SELECT_AM;
    spi(WHO_AM_I);
	who_am_i = spiRead();
	SLAVE_DESELECT_AM;
    _delay_ms(1000);
   
	SLAVE_SELECT_AM;
    spi(XYZ_DATA_CFG);
	spi(0b00000010); // Full scale range ±8g
	SLAVE_DESELECT_AM;
    _delay_ms(1000);

	if(who_am_i == 99) {
		printf("FXOS8700CQ is working properly!\n");
		printf("WHO_AM_I is %d\n", who_am_i);
	} else {
		printf("Something is wrong, check wiring :(\n");
		printf("WHO_AM_I is %d but should be 99. Try again!\n", who_am_i);
	} 
}

void getAccelMagTemp(void) {	
    SLAVE_SELECT_AM;
    spi(AM_TEMP);
    raw_temp = spiRead();
	SLAVE_DESELECT_AM;
	celsius = raw_temp;

	printf("Raw FXOS8700CQ Temp: %.1f\n", celsius);
	_delay_ms(100);
}
