#ifndef CONFIG_H
#define CONFIG_H

#include "common_includes.h"

namespace config 
{
    const std::string ssid = "ESP32-Cam WiFi";
    const std::string wifiname = "papst";
    const std::string password = "test12345";
    const int SDA = 14; // replace with sda gpio pin address
    const int SCL = 16; // replace with scl gpio pin address

    // leave this as it is if you don't know what you are doing
    const IPAddress IP(192, 168, 0, 2);
	const IPAddress Gateway(192, 168, 0, 1);
	const IPAddress Subnetmask(255, 255, 255, 0);

    // timezone settings
    const long gmt = 1;
}

#endif