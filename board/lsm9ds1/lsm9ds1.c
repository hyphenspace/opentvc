#include "../driver/lsm9ds1.h"

void setupLSM9DS1(void) {
	spiInit();
	// Enable Mag
	SLAVE_SELECT_MAG;
	spi(CTRL_REG3_M);
	spi(0b10100000);
	SLAVE_DESELECT_MAG;
	_delay_ms(1000);
	// Enable Gyro 	
	SLAVE_SELECT;
	spi(CTRL_REG1_G);
	spi(0b01000001);
	SLAVE_DESELECT;
	_delay_ms(1000);
	
	// Enable accel
	SLAVE_SELECT;
	spi(CTRL_REG6_XL);
	spi(0b00100000);
	SLAVE_DESELECT;	
	_delay_ms(1000);
	
	SLAVE_SELECT;
	spi(CTRL_REG7_XL);
	spi(0b10000000);
	SLAVE_DESELECT;
	_delay_ms(1000);
	
	SLAVE_SELECT;
	spi(WHO_AM_I);
	who_am_i = spiRead();
	SLAVE_DESELECT;
	_delay_ms(1000);
	
	SLAVE_SELECT_MAG;
	spi(WHO_AM_I);
	who_am_i_mag = spiRead();
	SLAVE_DESELECT_MAG;
	_delay_ms(1000);
	if(who_am_i == 104 && who_am_i_mag == 61) {
		printf("LSM9DS1 WORKING PROPERLY!\n");
	} 
	else {
		printf("Something is wrong, check wiring :(\n");
	}
	
}

