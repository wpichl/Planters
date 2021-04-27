#include "config.hpp"
#include "WiFiHandler.hpp"
#include "common_includes.hpp"
void setup() {
    Serial.begin(9600);
    WiFiHandler wh(config::ssid, config::password);
    wh.Dump();
    wh.Connect();
}

void loop() {
  // put your main code here, to run repeatedly:
}