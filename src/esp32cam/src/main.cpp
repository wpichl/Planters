#include "common_includes.h"
#include "config.h"
#include "WiFiHandler.h"
#include "ADCHandler.h"

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
  if(temp < 20500)
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
    server.on("/sensor", HTTP_GET, [](AsyncWebServerRequest *request) {
      request->send(200, "text/plain", (String)adc.getADC());
    });
    server.on("/waterable", HTTP_GET, [](AsyncWebServerRequest *request) {
      if(waterable)
      {
        request->send(200, "text/plain", "TRUE");
      }
      else
      {
        request->send(200, "text/plain", "FALSE");
      }
    });

    server.on("/water", HTTP_GET, [](AsyncWebServerRequest *request) {
      if(waterable)
      {
        digitalWrite(12, HIGH);
        request->send(200, "text/plain", "WATERED");
      }
      else
      {
        request->send(200, "text/plain", "FAILURE");
      }
    });
    server.begin();
  }
}

void loop() {
}