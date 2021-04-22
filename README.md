# Planters
This is the repository for our school project to implement an automatic plant watering system using an ESP32-Cam as a microcontroller and a WebApp to water the plant

## Used Libraries
* [WiFi.h](https://platformio.org/lib/show/870/WiFi) - For connecting to an Access Point
* [AsyncTCP](https://github.com/me-no-dev/AsyncTCP) - Handle connections
* [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) - Send files

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
* ```/webapp/``` - The Web Application coded in TypeScripe
* ```/src/esp32cam/``` - The source code for the ESP32-Cam
* ```/misc/``` - Circuit layout, Presentations for the project
