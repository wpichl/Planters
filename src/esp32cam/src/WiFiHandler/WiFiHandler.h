#ifndef WIFIHANDLER_H
#define WIFIHANDLER_H

#include "common_includes.h"

class WiFiHandler
{
private:
	char* _ssid;
	char* _password;
public:
	WiFiHandler(std::string ssid, std::string password);
	void Connect();
	void Dump();
};
#endif
