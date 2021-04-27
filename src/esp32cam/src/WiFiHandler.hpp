#ifndef WIFIHANDLER_HPP
#define WIFIHANDLER_HPP

#include "common_includes.hpp"

class WiFiHandler
{
public:
    WiFiHandler(std::string ssid, std::string password);
	~WiFiHandler();
	void Connect();
	void Dump();
	bool Status();
private:
	std::string mSSID;
	std::string mPassword;
	bool mStatus = false;
	const int TIMEOUT_TIME = 20000;
};

#endif