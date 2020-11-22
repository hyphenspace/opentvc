#include "../driver/spi.h"

/** @defgroup group2 SPI Library
 *  This library contains all the neccessary code for Serial Peripheral Interface communication.
 *  @{
 */

/** Enable SPI, Master, set clock rate fck/4. */
void spiInit(void) {
  DDR_SPI |= ((1 << DD_SS_AM) | (1 << DD_SS_GYRO) | (1 << DD_SCK) | (1  << DD_MOSI));
  DDR_SPI &= ~(1 << DD_MISO);
  GYRO_SPI_PORT |= (1 << SS_GYRO);
  AM_SPI_PORT |= (1 << SS_AM);
  SPCR = ((1 << SPE) | (1 << CPHA) | (1 << CPOL) | (1 << MSTR)); 
}

/** SPI transmit function */
unsigned char spi(unsigned char data) {
    SPDR = data;
    while(!((SPSR) & (1 << SPIF)));
    junk = SPDR; 
    return SPDR;
}

/** @} */ // end of group2
