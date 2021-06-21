#include "common_includes.h"
#include "config.h"
#include "WiFiHandler.h"
#include "ADCHandler.h"
#include "cfg.h"
#include "waterHandler.h"
#include "math_t.h"

int16_t value = 0;
AsyncWebServer server(80);
ADCHandler adc(config::SDA, config::SCL);
WiFiHandler wh(config::ssid, config::IP, config::Gateway, config::Subnetmask, config::wifiname, config::password);
water water_t("/stats.txt");

bool watering = false;
bool automatic = false;

void setup() {
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
  Serial.begin(11500);
  pinMode(config::PUMP, OUTPUT);
  wh.Dump();
  wh.Connect();
  adc.Init();
  water_t.openHandle();
  if(wh.isConnected())
  {
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
      request->send_P(200, "text/plain", "Planters");
    });
    server.onNotFound([](AsyncWebServerRequest *request)
    {
      request->send(404, "text/plain", "404 Not found");
    });
    server.on("/sensor", HTTP_GET, [](AsyncWebServerRequest *request)
    {
      StaticJsonDocument<200> data;
      String response;
      int value = math::convert<int>(adc.getADC(), 19500, 21500, 0, 100);
      data["dryness"] = value;
      if (value > 20)
      {
        data["waterable"] = true;
      }
      else
      {
        data["waterable"] = false;
      }
      serializeJson(data, response);
      request->send(200, "application/json", response);
    });
    server.on("/stats", HTTP_GET, [](AsyncWebServerRequest *request)
    {
      request->send(200, "application/json", water_t.loadConfig());
    });
    server.on("/water", HTTP_GET, [](AsyncWebServerRequest *request)
    {
      int value = math::convert<int>(adc.getADC(), 19500, 21500, 0, 100);
      if(value > 20)
      {
        request->send(200, "text/plain", "Watering successful");
        water_t.waterPlant();
        watering = true;
      }
      else
      {
        request->send(200, "text/plain", "Plant doesn't need water");
      }
    });
    server.begin();
  }
}

void loop()
{
  if(watering)
  {
    digitalWrite(config::PUMP, HIGH);
    delay(20000);
    digitalWrite(config::PUMP, LOW);
    watering = false;
  }
}