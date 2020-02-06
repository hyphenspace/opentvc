/* 
 spiral's AVR firmware 
 Created by Akil Hylton El
*/
#include "servo/servo.h"
#include "usart/usart.h"
#include "spi/spi.h"
#include "hardware/hardware.h"

static FILE mystdout = FDEV_SETUP_STREAM(usartTransmit, NULL, _FDEV_SETUP_WRITE); // ONLY HERE FOR DEBUGGING. 
unsigned char junk, morejunk;
unsigned char xHighByte, xLowByte, yHighByte, yLowByte, zHighByte, zLowByte, who_am_i, ctrl_g;
unsigned char tempHigh, tempLow;
signed int pos = 0;
char c;
volatile short xGyroData = 0;
volatile short yGyroData = 0;    
volatile short zGyroData = 0;
volatile int tempData = 0;

int main (void) {
  initBuzzer();
  initStatusLED();
  //servoInit();
  //servoAttach(PB1);
  //servoAttach(PB2);
  DDRB |= (1 << DDB1);
  PORTB |= (1 << PB1); // Must set back low for pyro channel to stay off during inactivity 
  spiInit();
  _delay_ms(500);
  usartInit(MYUBRR);
  sei();
  stdout = &mystdout;

  SLAVE_SELECT;
  spi(CTRL_REG1_G);
  spi(0b01000001); // 
  SLAVE_DESELECT;

  _delay_ms(200);

  // Set Gyro bandwith
  SLAVE_SELECT;
  spi(0b10010000);
  ctrl_g = spiRead();
  SLAVE_DESELECT;
  
  //printf("%d\n", ctrl_g); // Should read 65.
  
  _delay_ms(200);

  SLAVE_SELECT;
  spi(WHO_AM_I);
  who_am_i = spiRead();
  SLAVE_DESELECT;
  
 if (who_am_i == 104) {
    printf("Gyro is working!!!!!!\n");
 } 
 else {
  printf("Gyro is not working :(\n");
 }
 

  while(1) {
  // Get X axis gyro data
  SLAVE_SELECT;
  _delay_us(30);
  spi(OUT_X_H_G);
  xHighByte = spiRead();
  spi(OUT_X_L_G);
  xLowByte = spiRead();
  SLAVE_DESELECT;
  
  xGyroData = (xHighByte << 8) | xLowByte;
  _delay_ms(200); 
  // YESSS WE GOT GYRO DATA BACK !!! :)))))
  //printf("Gyro X: %d\n", (short)(xGyroData));
  
  // Get Y axis gyro data
  SLAVE_SELECT;
  _delay_us(30);
  spi(OUT_Y_H_G);
  yHighByte = spiRead();
  spi(OUT_Y_L_G);
  yLowByte = spiRead();
  SLAVE_DESELECT;
  
  yGyroData = (yHighByte << 8) | yLowByte;
  _delay_ms(200); 
  // YESSS WE GOT GYRO DATA BACK !!! :)))))
  //printf("Gyro Y: %d\n", (short)(yGyroData));
  
  // Get Z axis gyro data
  SLAVE_SELECT;
  _delay_us(30);
  spi(OUT_Z_H_G);
  zHighByte = spiRead();
  spi(OUT_Z_L_G);
  zLowByte = spiRead();
  SLAVE_DESELECT;
  
  zGyroData = (zHighByte << 8) | zLowByte;
  _delay_ms(200); 
  // YESSS WE GOT GYRO DATA BACK !!! :)))))
  printf("Gyro X: %f  Gyro Y: %f Gyro Z: %f\n",xGyroData, yGyroData, zGyroData);
  /*
  SLAVE_SELECT;
  _delay_us(30);
  spi(OUT_TEMP_H);
  tempHigh = spiRead();
  spi(OUT_TEMP_L);
  tempLow = spiRead();
  SLAVE_DESELECT;
  tempData = ((tempHigh << 8) | tempLow);
  printf("Tempature: %d\n", tempData * 16);
 */
  /* 
  c  = usartReceive();
  if (c == 'p') {
    usartPrint("Pyro test fire shall begin...\n");
    initBuzzer();
    _delay_ms(1000);
    PORTB |= (1 << PB1);
    _delay_ms(3000);
    PORTB &= ~(1 << PB1);
  }
  */
  /*
  if (c == 'o') {
    PORTC |= (1 << PC0);
  }
  if (c == 'f') {
    PORTC &= ~(1 << PC0);
  }
  if (c == 'b') {
    for (int i = 0; i <= 4; i++) {
    blueStatusLED();
    }
  }
  // Servo TVC test 
  if (c == 's') {
    for (pos = 0; pos <= 25; pos++) {
      servoWriteY(pos);
      servoWriteZ(pos);
    }  
    for (signed int i = -25; pos >= i; pos--) {
      servoWriteY(pos);
      servoWriteZ(pos);
    }
    servoWriteY(0);
    servoWriteZ(0);
  }
  
  if (c == 'B') {
    for (int i = 0; i < 3; i++) {
      initBuzzer();
      _delay_ms(250);
    }   
  }
  */
  }
  return 0;
}
