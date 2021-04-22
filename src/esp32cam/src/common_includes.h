#ifndef COMMON_INCLUDES_H
#define COMMON_INCLUDES_H

#include <Arduino.h>
#include <WiFi.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <Arduino.h>
#ifdef ESP32
  #include <WiFi.h>
  #include <AsyncTCP.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>

#endif
