#include "WiFiHandler.hpp"

/*
 * Constructor where the wifi name and passwords gets saved.
 */
WiFiHandler::WiFiHandler(std::string ssid, std::string password) 
	: mSSID(ssid), mPassword(password)
{
}

/*
 * Destructor to free the dynamically allocated memory.
 * Needed when deleting the object.
 */
WiFiHandler::~WiFiHandler()
{
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
	WiFi.begin(mSSID.c_str(), mPassword.c_str());

	/*
	 * Looping till the enum status matches the enum WL_CONNECTED
	 * by the index which would be 3 = module successfully connected
	 * to the router.
	 * After 20 seconds if not getting a connecting the ESP will stop and
	 * print 'failed'
	 */
	unsigned long startTime = millis();
	while(WiFi.status() != WL_CONNECTED && millis() - startTime < TIMEOUT_TIME)
	{
		Serial.print(".");
		delay(1000);
	}

	if(WiFi.status() != WL_CONNECTED)
	{
		mStatus = false;
		Serial.println();
		Serial.println("Failed");
	}
	else
	{
		mStatus = true;
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
	Serial.print(mSSID.c_str());
	Serial.println();
	Serial.print("Password: ");
	Serial.print(mPassword.c_str());
	Serial.println();
	Serial.println("----------------------------");
}

/*
 * Check if the ESP is connected to the WiFi
 * Could be useful when making a REST api.
 *
 * Returns 'false' if the connection failed or no connection has ever been tried
 * to establish
 *
 * Returns 'true' if the connection works and is established
 */
bool WiFiHandler::isConnected()
{
	return mStatus;

}