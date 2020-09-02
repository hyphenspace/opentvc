#include <avr/io.h>
#include "lsm9ds1.h"

#define DDR_SPI DDRB
#define DD_SCK DDB5
#define DD_MOSI DDB3
#define DD_MISO DDB4
#define DD_SS DDB1
#define DD_SS_MAG DDB2
#define SS PB1 // Slave select for gyro and accel
#define SS_MAG PB2 // Slave select for magnetometer
#define SLAVE_DESELECT_MAG SPI_PORT |= (1 << SS_MAG)
#define SLAVE_SELECT_MAG SPI_PORT &= ~(1 << SS_MAG)
#define SLAVE_DESELECT SPI_PORT |= (1 << SS)
#define SLAVE_SELECT SPI_PORT &= ~(1 << SS)
#define SPI_PORT PORTB
#define spiWrite(data) spi(data) 
#define spiRead() spi(0xff)

unsigned char junk, status;
void spiInit(void);
unsigned int spi_16bit(unsigned int data);
unsigned char spi(unsigned char data);
