#include <avr/io.h>
#include "../driver/usart.h"

void usartInit(unsigned int ubrr) {
  UBRR0H = (ubrr >> 8);
  UBRR0L = ubrr;

  UCSR0B = ((1 << RXEN0) | (1 << TXEN0));
  UCSR0C = ((1 << UCSZ01) | (1 << UCSZ00));
}

void usartTransmit(unsigned char data, FILE *stream) {
  if (data == '\n') { 
    usartTransmit('\r', stream);
  }
  while(!(UCSR0A & (1 << UDRE0)));
  UDR0 = data;
}

unsigned char usartReceive(void) {
  while(!(UCSR0A & (1 << RXC0)));
  return UDR0;
}
/*
void usartPrint(char *string) {
  while (*string != 0x00) {
    usartTransmit(*string++); 
  }
}

void usartPrintInt(int num) {
  itoa(num, buffer, 10);
  usartPrint(buffer);
  usartPrint("\n");
  _delay_ms(1000);  
}
*/
