#include "../driver/fxas21002.h"

/** @defgroup group0 FXAS21002 Library
 *  This library contains all the neccessary code for using the triple-axis gyroscope from the FXAS21002.
 *  @{
 */

/** This function enables the gyroscope. */
void setupFXAS21002(void) {
	spiInit();
	SLAVE_SELECT_GYRO;
	spi(GYRO_STATUS);
	who_am_i = spiRead();
	SLAVE_DESELECT_GYRO;
    _delay_ms(1000);	
	if(who_am_i == 124) {
		printf("FXAS21002 is working properly!\n");
	    printf("WHO_AM_I is %d\n", who_am_i);
	} else {
		printf("Something is wrong, check wiring :(\n");
   	    printf("WHO_AM_I is %d but should be 124. Try again!\n");
	}
}

/** This function retrieves the gyroscopes angular rate data. **/
void getGyroData(void) {
		SLAVE_SELECT_GYRO;
		spi(GYRO_OUT_X_H);
		gyro_x_high = spiRead();
		spi(GYRO_OUT_X_L);
		gyro_x_low = spiRead();
		SLAVE_DESELECT_GYRO;

		SLAVE_SELECT_GYRO;
		spi(GYRO_OUT_Y_H);
		gyro_y_high = spiRead();
		spi(GYRO_OUT_Y_L);
		gyro_y_low = spiRead(); 
		SLAVE_DESELECT_GYRO;
		
		SLAVE_SELECT_GYRO;
		spi(GYRO_OUT_Z_H);
		gyro_z_high = spiRead();
		spi(GYRO_OUT_Z_L);
		gyro_z_low = spiRead();
		SLAVE_DESELECT_GYRO;
		
		raw_gyro_x = (gyro_x_high << 8) | gyro_x_low;
		raw_gyro_y = (gyro_y_high << 8) | gyro_y_low;
		raw_gyro_z = (gyro_z_high << 8) | gyro_z_low;

		printf("Raw X: %d, Raw Y: %d, Raw Z: %d\n", raw_gyro_x, raw_gyro_y, raw_gyro_z);
		_delay_ms(100);
}

/** This function retrieves the gyroscopes temperature value in celsius. **/
void getGyroTemp(void) {
		SLAVE_SELECT_GYRO;
		spi(GYRO_TEMP);
		raw_temp = spiRead();
		SLAVE_DESELECT_GYRO;
		celsius = raw_temp;
		printf("Raw gyro tempature: %.1f\n", celsius);
		_delay_ms(100);
}
