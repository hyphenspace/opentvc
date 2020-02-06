#include <avr/io.h>

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
#define WHO_AM_I 0b10001111 
#define ORIENT_CFG_G 0b00010011 // Read from orient
#define STATUS_REG 0b10010111 // Read status reg
#define CTRL_REG1_G 0b00010000 
#define OUT_TEMP_H 0b10010110
#define OUT_TEMP_L 0b10010101
#define OUT_X_L_G 0b10011000
#define OUT_X_H_G 0b10011001
#define OUT_Y_L_G 0b10011010
#define OUT_Y_H_G 0b10011011
#define OUT_Z_L_G 0b10011100
#define OUT_Z_H_G 0b10011101

#define spiWrite(data) spi(data) 
#define spiRead() spi(0xff)

unsigned char junk, status;
void spiInit(void);
unsigned int spi_16bit(unsigned int data);
unsigned char spi(unsigned char data);
