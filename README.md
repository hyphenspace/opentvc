![spiral icon](https://i.imgur.com/8JeVKCG.png)


## What is spiral?
spiral is a model rocket flight firmware that is built to runs on the HELIX Flight Computer. The firmware features libaries that supports control for servos, USART, SPI and the on-board hardware. 

Directory Structure
------
    .
    ├── servo # Library used for servo control
    ├── usart # Library used for USART communication
    ├── spi # Library used for SPI communication
    ├── hardware # Library used to control on-board hardware 


## Servo library usage example
```
#include "servo/servo.h"

int main(void) {
  servoInit(); // Configures 16 bit registers for 50Hz PWM signal.
  servoAttach(Y_SERVO);
  while(1) {
    servoWriteY(0);
  }
  return 0;
}
```
