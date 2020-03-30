FROM ubuntu:latest

WORKDIR usr/spiral/
COPY board/ . 

RUN apt-get update && apt-get install -y \
    make \
    gcc-avr \
    binutils-avr \
    avr-libc \
    avrdude
 
RUN make
