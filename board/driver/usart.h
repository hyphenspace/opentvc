#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#define FOSC 4000000 // Clock speed
#define BAUD 9600
#define MYUBRR ((FOSC/16/BAUD) - 1)
#define BUFFER_LEN 100

char buffer[BUFFER_LEN];
void usartInit(unsigned int ubrr);
void usartTransmit(unsigned char data);
//void usartTransmit(unsigned char data, FILE *stream);
//void usartPrint(char *string);
//void usartPrintInt(int num);
int print(char c, FILE *stream);
unsigned char usartReceive(void);
