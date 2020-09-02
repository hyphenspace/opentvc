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


lsm9ds1Vector_t getAccelData(void) {
	SLAVE_SELECT;
	spi(OUT_X_H_XL);
	accel_x_high = spiRead();
	spi(OUT_X_L_XL);
	accel_x_low = spiRead();
	SLAVE_DESELECT;

	SLAVE_SELECT;
	spi(OUT_Y_H_XL);
	accel_y_high = spiRead();
	spi(OUT_Y_L_XL);
	accel_y_low = spiRead();
	SLAVE_DESELECT;

	SLAVE_SELECT;
	spi(OUT_Z_H_XL);
	accel_z_high = spiRead();
	spi(OUT_Z_L_XL);
	accel_z_low = spiRead();
	SLAVE_DESELECT;

	raw_accel_x = (accel_x_high << 8) | accel_x_low;
	raw_accel_y = (accel_y_high << 8) | accel_y_low;
	raw_accel_z = (accel_z_high << 8) | accel_z_low;
	
	x_g_force = ((float)raw_accel_x * ACCEL_SENSITIVITY) * 0.001;
	y_g_force = ((float)raw_accel_y * ACCEL_SENSITIVITY) * 0.001;
	z_g_force = ((float)raw_accel_z * ACCEL_SENSITIVITY) * 0.001;

	accelData.x = x_g_force;
	accelData.y = y_g_force;
	accelData.z = z_g_force;
	
	return accelData;
}

lsm9ds1Vector_t getGyroData(void) {
	SLAVE_SELECT;
	spi(OUT_X_H_G);
	gyro_x_high = spiRead();
	spi(OUT_X_L_G);
	gyro_x_low = spiRead();
	SLAVE_DESELECT;

	SLAVE_SELECT;
	spi(OUT_Y_H_G);
	gyro_y_high = spiRead();
	spi(OUT_Y_L_G);
	gyro_y_low = spiRead();
	SLAVE_DESELECT;

	SLAVE_SELECT;
	spi(OUT_Z_H_G);
	gyro_z_high = spiRead();
	spi(OUT_Z_L_G);
	gyro_z_low = spiRead();
	SLAVE_DESELECT;

	raw_gyro_x = (gyro_x_high << 8) | gyro_x_low;
	raw_gyro_y = (gyro_y_high << 8) | gyro_y_low;
	raw_gyro_z = (gyro_z_high << 8) | gyro_z_low;
	
	gyroData.x = ((float)raw_gyro_x * GYRO_SENSITIVITY) * 0.001;
	gyroData.y = ((float)raw_gyro_y * GYRO_SENSITIVITY) * 0.001;
	gyroData.z = ((float)raw_gyro_z * GYRO_SENSITIVITY) * 0.001;	
	
	gyroData.x -= GYRO_X_OFFSET;
	gyroData.y -= GYRO_Y_OFFSET;
	gyroData.z -= GYRO_Z_OFFSET;
		
	return gyroData;
}

