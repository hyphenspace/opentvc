![spiral tests](https://github.com/hyphenspace/spiral/workflows/spiral%20tests/badge.svg)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
## What is opentvc?
Open thrust vector control (opentvc) is a model rocket flight firmware that is built to runs on the spiral flight computer. \
The firmware features libaries that supports control for servos, USART, SPI and the on-board hardware. 
## spiral hardware uses Bluetooth Low Energy
Data is sent from an AVR microcontroller via UART and received by Nordic nRF5832 BLE module. \
This exchage is biodirectional so data can also be sent out from the BLE module to AVR microcontroller.

# Installation

## Running in Docker
1. Build docker environment
```
docker build -t spiral:1.0 .
```
2. Run docker environment 
```
docker run -it spiral:1.0
```
3. Change directory to where source file sits
```
cd board 
```
4. Build firmware
```
make 
```
# Servo library usage example
```
#include "drivers/servo.h"

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

# Directory Structure
* board -- Code that runs on the ATmega328P
------
    board
        ├── servo # Library used for servo control
        ├── usart # Library used for USART communication
        ├── spi # Library used for SPI communication
        ├── hardware # Library used to control on-board hardware 
        ├── firmware # Folder that holds compiled firmware
