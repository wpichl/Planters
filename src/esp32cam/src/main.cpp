#include "common_includes.h"
#include "config.h"
#include "WiFiHandler.h"

#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
<title>Planters</title>
</head><body>
<h1>test</h1>
</body></html>)rawliteral";

void setup() {
  Serial.begin(11500);
  WiFiHandler wh(config::ssid, config::password);
  wh.Dump();
  wh.Connect();

  if(wh.isConnected())
  {
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
	  {
      request->send_P(200, "text/html", index_html);
	  });
    server.begin();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}