# Planters
This is the repository for our school project to implement an automatic plant watering system using an ESP32-Cam as a microcontroller and a WebApp to water the plant

## Used Libraries
* [WiFi.h](https://platformio.org/lib/show/870/WiFi) - For connecting to an Access Point
* [AsyncTCP](https://github.com/me-no-dev/AsyncTCP) - Handle connections
* [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) - Send files
* [Adafruit BusIO](https://platformio.org/lib/show/6214/Adafruit%20BusIO) - Abstracting UART, I2C and SPI interfacing
* [Adafruit ADS1X15](https://platformio.org/lib/show/342/Adafruit%20ADS1X15) - Library for ADS1015/1115 ADCs
* [ArduinoJSON](https://platformio.org/lib/show/64/ArduinoJson) - Creating JSON Objects

## Tools and Plugins needed to compile
* [Visual Studio Code](https://code.visualstudio.com/) - A smart and potent Code Editor for C/C++
* [Platform IO Plugin](https://platformio.org/platformio-ide) - To compile
* [JetBrains Webstorm](https://www.jetbrains.com/webstorm/) - IDE for Web Development
* [NodeJS](https://nodejs.org/en/) - Strong and very universal package manager
* [TypeScript Module for NodeJS](https://nodejs.dev/learn/nodejs-with-typescript) - TypeScript transpiler and interpreter

## How to run
Install [Python 3](https://www.python.org/downloads/) and possibly add the binary to your PATH  
In order to have a working serial monitor and compiler, Platform IO CLI is necessary
```bash
pip install -U platformio
```
After this head over to the root of the controller project
```bash
cd src/esp32cam/
```
Finally start the serial monitor
```bash
pio device monitor
```

## Folder structure
* ```/webapp/``` - The Web Application coded in TypeScript
* ```/src/esp32cam/``` - The source code for the ESP32-Cam
* ```/doc/``` - Circuit layout, Presentations for the project
