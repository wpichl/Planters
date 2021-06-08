#ifndef WIFIHANDLER_H
#define WIFIHANDLER_H

#include "common_includes.h"

class WiFiHandler
{
public:
    WiFiHandler(std::string ssid, IPAddress IP, IPAddress gateway, IPAddress subnetmask, std::string wifiname, std::string password);
	~WiFiHandler();
	void Connect();
	void Dump();
	bool isConnected();
private:
	std::string mSSID;
	IPAddress mIP;
	IPAddress mGateway;
	IPAddress mSubnetmask;
	std::string mWiFiName;
	std::string mPassword;
	bool mStatus = false;
};

#endif