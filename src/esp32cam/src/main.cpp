#include "common_includes.h"
#include "config.h"
#include "WiFiHandler.h"
#include "ADCHandler.h"
#include "cfg.h"
#include "waterHandler.h"

#include <soc/soc.h>
#include <soc/rtc_cntl_reg.h>

#include <ArduinoJson.h>
#include <SPIFFS.h>

#include "Arduino.h"
#include "esp_camera.h"
#include "ESPAsyncWebServer.h"

#include "math_t.h"
int16_t value = 0;

AsyncWebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
<title>Planters</title>
</head><body>
<h1>test</h1>
</body></html>)rawliteral";

bool automatic = false;

ADCHandler adc(config::SDA, config::SCL);
water water_t("/stats.txt");
bool watering = false;
static bool waterable()
{
  bool isWaterable = false;
  int16_t temp = adc.getADC();
  if(temp < 2100)
  {
    isWaterable = false;
  }
  else
  {
    isWaterable = true;
  }
  return isWaterable;
}

void setup() {
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); //disable brownout detector
  Serial.begin(11500);
  pinMode(config::PUMP, OUTPUT);
  WiFiHandler wh(config::ssid, config::IP, config::Gateway, config::Subnetmask, config::wifiname, config::password);
  wh.Dump();
  wh.Connect();
  adc.Init();
  water_t.openHandle();
  if(wh.isConnected())
  {
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
      request->send_P(200, "text/html", index_html);
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