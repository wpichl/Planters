#include "WiFiHandler.h"

WiFiHandler::WiFiHandler(std::string ssid, std::string password)
{
    _ssid = (char*)(malloc(ssid.length()));
    _password = (char*)(malloc(password.length()));

    strcpy(_ssid, ssid.c_str());
    strcpy(_password, password.c_str());
}

void WiFiHandler::Connect()
{
	Serial.print("Connecting");
	WiFi.mode(WIFI_STA); // Connect to an AccessPoint
	WiFi.begin(_ssid, _password);

	while(WiFi.status() != WL_CONNECTED)
	{
		Serial.print(".");
		delay(1000);
	}

	if(WiFi.status() != WL_CONNECTED)
	{
		Serial.println();
		Serial.println("Failed");
	}
	else
	{
		Serial.println();
		Serial.println("Connected");
		Serial.print("IP: ");
		Serial.println(WiFi.localIP());
	}
}

void WiFiHandler::Dump()
{
	Serial.println();
	Serial.println("--- WiFi Connection Dump ---");
	Serial.print("SSID: ");
	Serial.print(_ssid);
	Serial.println();
	Serial.print("Password: ");
	Serial.print(_password);
	Serial.println();
	Serial.println("----------------------------");
}


