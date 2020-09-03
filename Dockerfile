FROM ubuntu:latest

WORKDIR usr/opentvc/
COPY board/ . 

RUN apt-get update && apt-get install -y \
    make \
    gcc-avr \
    binutils-avr \
    avr-libc \
    avrdude
 
RUN make
