#!/usr/bin/env bash

## Create firmware project folder
git clone --recursive https://github.com/espressif/esp-idf-template.git
mv esp-idf-template firmware
## Install ESP32 SDK
git clone -b v4.0 --recursive https://github.com/espressif/esp-idf.git
cd esp-idf
## Setup Build Environment
python -m pip install -r requirements.txt
./install.sh ## Set up tools
. ./export.sh ## Set up environment variables
