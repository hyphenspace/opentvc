#include <avr/io.h>
#include "../driver/usart.h"



/** @defgroup group4 USART Library
 *  This library contains all the neccessary code for serial transmission.
 *  @{
 */

/** This function enables the receiver and tranmitter.*/
void usartInit(unsigned int ubrr) {
  UBRR0H = (ubrr >> 8);
  UBRR0L = ubrr;

  UCSR0B = ((1 << RXEN0) | (1 << TXEN0));
  UCSR0C = ((1 << UCSZ01) | (1 << UCSZ00));
}

/** This function transmit data on the TX pin.*/
void usartTransmit(unsigned char data) {
  while(!(UCSR0A & (1 << UDRE0)));
  UDR0 = data;
}


/** This function receives data from the RX pin.*/
unsigned char usartReceive(void) {
  while(!(UCSR0A & (1 << RXC0)));
  return UDR0;
}


int print(char c, FILE *stream) {
  while(!(UCSR0A & (1 << UDRE0)));
  UDR0 = c;
  return 0;
}

/** @} */ // end of group4
