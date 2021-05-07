#ifndef WIFIHANDLER_H
#define WIFIHANDLER_H

#include "common_includes.h"

class WiFiHandler
{
public:
    WiFiHandler(std::string ssid, IPAddress IP, IPAddress gateway, IPAddress subnetmask);
	~WiFiHandler();
	void Connect();
	void Dump();
	bool isConnected();
private:
	std::string mSSID;
	IPAddress mIP;
	IPAddress mGateway;
	IPAddress mSubnetmask;
	bool mStatus = false;
	const int TIMEOUT_TIME = 20000;
};

#endif