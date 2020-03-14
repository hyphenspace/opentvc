#include "../drivers/spi.h"
// SPI Library 
void spiInit(void) {
   // Set SPI Data direction as output   
  DDR_SPI |= ((1 << DD_SS) | (1 << DD_SCK) | (1  << DD_MOSI));
  DDR_SPI &= ~(1 << DD_MISO);
  SPI_PORT |= (1 << SS);
  SPCR = ((1 << SPE) | (1 << CPHA) | (1 << CPOL) | (1 << MSTR)); // Enable SPI, Master, set clock rate fck/4.
}

unsigned char spi(unsigned char data) {
    SPDR = data;
    while(!((SPSR) & (1 << SPIF)));
    junk = SPDR; 
    return SPDR;
}

unsigned int spi_16bit(unsigned int data) {
  SPDR = (data >> 8);
  while(!(SPSR & (1 << SPIF)));
  SPDR = (data);
  while(!(SPSR & (1 << SPIF)));
  return SPDR;
}
