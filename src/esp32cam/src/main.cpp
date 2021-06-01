#include "common_includes.h"
#include "config.h"
#include "WiFiHandler.h"
#include "ADCHandler.h"


#include <ArduinoJson.h>

int16_t value = 0;

AsyncWebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
<title>Planters</title>
</head><body>
<h1>test</h1>
</body></html>)rawliteral";

ADCHandler adc(config::SDA, config::SCL);
static bool waterable()
{
  bool isWaterable = false;
  int16_t temp = adc.getADC();
  if(temp < 2100)
  {
    isWaterable = true;
  }
  return isWaterable;
}
void setup() {
  Serial.begin(11500);
  pinMode(12, OUTPUT);
  WiFiHandler wh(config::ssid, config::IP, config::Gateway, config::Subnetmask);
  wh.Dump();
  wh.Connect();
  adc.Init();
  
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
      data["sensor"] = adc.getADC();
      data["waterable"] = waterable();
      serializeJson(data, response);
      request->send(200, "application/json", response);
    });
    server.begin();
  }
}

void loop()
{
  if(waterable())
  {
    digitalWrite(12, HIGH);
  }
  else
  {
    digitalWrite(12, LOW);
  }
  sleep(3);
}