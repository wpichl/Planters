#ifndef WIFIHANDLER_H
#define WIFIHANDLER_H

#include "../common_includes.h"

class WiFiHandler
{
private:
	char* _ssid;
	char* _password;
	bool _status = false;
	const int TIMEOUT_TIME = 20000;
public:
	WiFiHandler(std::string ssid, std::string password);
	~WiFiHandler();
	void Connect();
	void Dump();
	bool Status();
};
#endif
