#include "../driver/fxos8700cq.h"

/** @defgroup group5 FXOS8700CQ Library
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

/** This function retrieves the accelerometer's G force data. **/
void getAccelData(void) {
     SLAVE_SELECT_AM;
	 spi(ACCEL_OUT_X_H);
	 accel_x_high = spiRead();
	 spi(ACCEL_OUT_X_L); 
     accel_x_low = spiRead();
	 SLAVE_DESELECT_AM;

	 SLAVE_SELECT_AM;
     spi(ACCEL_OUT_Y_H);
	 accel_y_high = spiRead();
	 spi(ACCEL_OUT_Y_L);
	 accel_y_low = spiRead();
	 SLAVE_DESELECT_AM;

     SLAVE_SELECT_AM;
     spi(ACCEL_OUT_Z_H);
	 accel_z_high = spiRead();
	 spi(ACCEL_OUT_Z_L);
	 accel_z_low = spiRead();
	 SLAVE_DESELECT_AM;

	 raw_accel_x = (accel_x_high << 8) | accel_x_low;
	 raw_accel_y = (accel_y_high << 8) | accel_y_low;
	 raw_accel_z = (accel_z_high << 8) | accel_z_low;

	 printf("Raw x accel: %d\nRaw y accel: %d\nRaw z accel: %d\n", raw_accel_x, raw_accel_y, raw_accel_z);
	 _delay_ms(100);
}

/** This function retrieves the magnetometer's magnetic measurement data. **/
void getMagData(void) {
    SLAVE_SELECT_AM;
    spi(MAG_OUT_X_H);
    mag_x_high = spiRead();
	spi(MAG_OUT_X_L);
	mag_x_low = spiRead();
	SLAVE_DESELECT_AM;

	SLAVE_SELECT_AM;
    spi(MAG_OUT_Y_H);
    mag_y_high = spiRead();
	spi(MAG_OUT_Y_L);
	mag_y_high = spiRead();
	SLAVE_DESELECT_AM;
    
	SLAVE_SELECT_AM;
    spi(MAG_OUT_Z_H);
    mag_z_high = spiRead();
	spi(MAG_OUT_Z_L);
	mag_z_low = spiRead();
	SLAVE_DESELECT_AM;

    raw_mag_x = (mag_x_high << 8) | mag_x_low;
	raw_mag_y = (mag_y_high << 8) | mag_y_low;
	raw_mag_z = (mag_z_high << 8) | mag_z_low;

    printf("Raw x mag: %d\nRaw y mag: %d\nRaw z mag: %d\n", raw_mag_x, raw_mag_y, raw_mag_z);
    _delay_ms(100);
}



/** This function retrieves the accelerometer and magnetometer's temperature value in celsius. **/
void getAccelMagTemp(void) {	
    SLAVE_SELECT_AM;
    spi(AM_TEMP);
    raw_temp = spiRead();
	SLAVE_DESELECT_AM;
	celsius = raw_temp;

	printf("Raw FXOS8700CQ Temp: %.1f\n", celsius);
	_delay_ms(100);
}

/** @} */ // end of group5
