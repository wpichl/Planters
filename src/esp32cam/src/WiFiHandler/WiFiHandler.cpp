#include "WiFiHandler.h"

/*
 * Constructor where the wifi name and passwords gets saved.
 */
WiFiHandler::WiFiHandler(std::string ssid, std::string password)
{
	/*
	 * Convert to a char array because Serial.print and WiFi.begin
	 * cant handle std::string.
	 * Allocate memory for the char array.
	 */
    _ssid = (char*)(malloc(ssid.length()));
    _password = (char*)(malloc(password.length()));


    strcpy(_ssid, ssid.c_str());
    strcpy(_password, password.c_str());
}

/*
 * Destructor to free the dynamically allocated memory.
 * Needed when deleting the object.
 */
WiFiHandler::~WiFiHandler()
{
	free(_ssid);
	free(_password);
}

/*
 * Connect to the router/access point
 */
void WiFiHandler::Connect()
{
	Serial.print("Connecting");

	/*
	 * Why mode WIFI_STA? Meaning: WIFI Station.
	 * typedef enum {
	 * WIFI_MODE_NULL = 0 null mode
	 * WIFI_MODE_STA,     WiFi station mode
	 * WIFI_MODE_AP,      WiFi soft-AP mode
	 * WIFI_MODE_APSTA,   WiFi station + soft-AP mode
	 * WIFI_MODE_MA
	 * } wifi_mode_t;
	 * Dumped from the WiFi class.
	 */
	WiFi.mode(WIFI_STA); // Connect to an AccessPoint
	WiFi.begin(_ssid, _password);

	/*
	 * Looping till the enum status matches the enum WL_CONNECTED
	 * by the index which would be 3 = module successfully connected
	 * to the router.
	 */
	while(WiFi.status() != WL_CONNECTED)
	{
		Serial.print(".");
		delay(1000);
	}

	if(WiFi.status() != WL_CONNECTED)
	{
		_status = true;
		Serial.println();
		Serial.println("Failed");
	}
	else
	{
		_status = true;
		Serial.println();
		Serial.println("Connected");
		Serial.print("IP: ");
		Serial.println(WiFi.localIP());
	}
}

/*
 * Print the current WiFi the ESP is connecting to the console.
 * Because why not.
 */
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

/*
 * Check if the ESP is connected to the WiFi
 * Could be useful when making a REST api.
 */
bool WiFiHandler::Status()
{
	return _status;
}


