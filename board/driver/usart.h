
#ifndef USART_H
#define USART_H

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#define FOSC 16000000 // Clock speed
#define BAUD 9600
#define MYUBRR ((FOSC/16/BAUD) - 1)
#define BUFFER_LEN 100

char buffer[BUFFER_LEN];
void usartInit(unsigned int ubrr);
void usartTransmit(unsigned char data);
int print(char c, FILE *stream);
unsigned char usartReceive(void);

#endif // USART_H
