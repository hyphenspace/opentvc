#ifndef SPI_H
#define SPI_H

#include <avr/io.h>

#define DDR_SPI DDRB
#define DD_SCK DDB5
#define DD_MOSI DDB3
#define DD_MISO DDB4
#define DD_SS_GYRO DDD2
#define DD_SS_AM DDC3
#define SS_GYRO PD2   // Slave select for gyroscope
#define SS_AM PC3     // Slave select for acceleromter & magnetometer
#define GYRO_SPI_PORT PORTC
#define AM_SPI_PORT PORTD

#define SLAVE_DESELECT_AM AM_SPI_PORT |= (1 << SS_AM)
#define SLAVE_SELECT_AM AM_SPI_PORT &= ~(1 << SS_AM)

#define SLAVE_DESELECT_GYRO GYRO_SPI_PORT |= (1 << SS_GYRO)
#define SLAVE_SELECT_GYRO GYRO_SPI_PORT &= ~(1 << SS_GYRO)

#define GYRO_SPI_PORT PORTC
#define AM_SPI_PORT PORTD
#define spiRead() spi(0xff)

unsigned char junk;
void spiInit(void);
unsigned char spi(unsigned char data);

#endif // SPI_H
