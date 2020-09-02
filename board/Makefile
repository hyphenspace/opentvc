MCU=atmega328p
PROGRAMMER=atmelice_isp
F_CPU=16000000 
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -Wl,-u,vfprintf -lprintf_flt -lm
TARGET=main
SRC=main.c 
SERVO_LIB=servo/servo.c 
USART_LIB=usart/usart.c
SPI_LIB=spi/spi.c
HARDWARE_LIB=hardware/hardware.c
TIME_LIB=time/time.c
LSM9DS1_LIB=lsm9ds1/lsm9ds1.c


all:
	${CC} ${CFLAGS} ${SRC} ${SERVO_LIB} ${LSM9DS1_LIB} ${TIME_LIB} ${USART_LIB} ${SPI_LIB} ${HARDWARE_LIB} -o firmware/${TARGET}.bin -std=c99
	${OBJCOPY} -j .text -j .data -O ihex firmware/${TARGET}.bin firmware/${TARGET}.hex

flash:
	avrdude -p ${MCU} -c ${PROGRAMMER} -U flash:w:firmware/${TARGET}.hex:i -P usb

clean:
	rm -R firmware/*.bin firmware/*.hex
