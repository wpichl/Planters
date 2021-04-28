#include "common_includes.h"
#include "config.h"
#include "WiFiHandler.h"

void setup() {
  Serial.begin(11500);
  WiFiHandler wh(config::ssid, config::password);
  wh.Dump();
  wh.Connect();

}

void loop() {
  // put your main code here, to run repeatedly:
}