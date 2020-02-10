#include <avr/io.h>
#include "lsm9ds1.h"

#define DDR_SPI DDRB
#define DD_SCK DDB5
#define DD_MOSI DDB3
#define DD_MISO DDB4
#define DD_SS DDB2
#define SS PB1
#define SERVO_Y
#define SERVO_X
#define SLAVE_DESELECT PORTB |= (1 << SS)
#define SLAVE_SELECT PORTB &= ~(1 << SS)
#define SPI_PORT PORTB
#define spiWrite(data) spi(data) 
#define spiRead() spi(0xff)

unsigned char junk, status;
void spiInit(void);
unsigned int spi_16bit(unsigned int data);
unsigned char spi(unsigned char data);
