#include "common_includes.h"
#include "WiFiHandler/WiFiHandler.h"
#include "config.h"

AsyncWebServer server(80);

/*
 * Data to send to the client
 * Ghetto fixed it. Don't use it for serious purpose.
 */
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
<title>Planters</title>
</head><body>
<h1>test</h1>
</body></html>)rawliteral";


void setup()
{
    Serial.begin(9600);
    WiFiHandler wh = WiFiHandler(config::ssid, config::password);
    wh.Dump();
    wh.Connect();
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
    {
        request->send_P(200, "text/html", index_html);
    });

    server.begin();
}

void loop()
{
}
