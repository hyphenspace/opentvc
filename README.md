![spiral icon](https://i.imgur.com/8JeVKCG.png)

[![Build Status](https://travis-ci.com/akilhylton/spiral.svg?token=Mhdf3XXByqN3Nb1swBdo&branch=master)](https://travis-ci.com/akilhylton/spiral)
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
  servoAttach(Z_SERVO);
  while(1) {
    servoWriteY(0); // Write angle 0 to servo controlling Y axis
    servoWwriteZ(0); // Write angle 0 to servo controlling Z axis
  }
  return 0;
}
```

## How to compile and build
You should only continue if you have a HELIX Flight Computer.
### Build with Makefile

Prerequisites
- AVR-GCC
- AVRDUDE

To build:
```
make
```

To flash the bootloader with AVR Programmer:
```
make flash
```
