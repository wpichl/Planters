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

## Drivers needed to detect the MCU
The Linux Kernel and macOS can automatically detect the micro processor without the need of installing third-party libraries. However Windows doesnt and needs a specific driver which can be found [here](https://ftdichip.com/wp-content/uploads/2021/02/CDM21228_Setup.zip).

## SerialMonitor and Output
### Option 1: Platform IO Serial Monitor
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

### Option 2: PuTTY's Serial Monitor
A good alternative is the built in Serial Monitor in the PuTTY program which is normally used for SSH, Telnet and more.
Download PuTTY from [here](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html) and start it up.
* Change the connection type to "Serial"
* Change the speed to 11500
* Specify the port on which the ESP is connected to

The port can be checked via Visual Studio Code in the Platform IO Home under Devices.

## Folder structure
* ```/webapp/``` - The Web Application coded in TypeScript
* ```/src/esp32cam/``` - The source code for the ESP32-Cam
* ```/doc/``` - Circuit layout, Presentations for the project

## Troubleshooting
If Platform IO cannot find the upload port nor the CLI or PuTTY, the installation of the FTDI Driver either hasn't been done or was faulty.