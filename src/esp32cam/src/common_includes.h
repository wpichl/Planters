#ifndef COMMON_INCLUDES_H
#define COMMON_INCLUDES_H

/*
 * Common includes because we are to lazy to type this everytime.
 */
#include <Arduino.h>
#include <WiFi.h>
#include <iostream>
#include <cstdlib>
#include <cstring>

#ifdef ESP32
  #include <WiFi.h>
  #include <AsyncTCP.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>

#endif
