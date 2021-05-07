#include "WiFiHandler.h"

/*
 * Constructor where the wifi name and passwords gets saved.
 */
WiFiHandler::WiFiHandler(std::string ssid, IPAddress IP, IPAddress gateway, IPAddress subnetmask) 
	: mSSID(ssid), mIP(IP), mGateway(gateway), mSubnetmask(subnetmask)
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
	WiFi.softAPConfig(mIP, mGateway, mSubnetmask);
	WiFi.softAP(mSSID.c_str());
	mStatus = true;
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
	Serial.print("IP: ");
	Serial.print(mIP.toString());
	Serial.println();
	Serial.print("Gateway: ");
	Serial.print(mGateway.toString());
	Serial.println();
	Serial.print("Subnetmask: ");
	Serial.print(mSubnetmask.toString());
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