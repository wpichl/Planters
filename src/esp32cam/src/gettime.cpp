#include "common_includes.h"
#include "config.h"
#include "WiFiHandler.h"
#include "ADCHandler.h"

#include <ArduinoJson.h>
#include "time.h"

String currentdate()
{
    const char* ntpServer = "pool.ntp.org";
    const long gmtOffset_sec = 0;
    const int daylightOffset_sec = 3600;
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    struct tm timeinfo;
    if(!getLocalTime(&timeinfo))
    {
        return "Failed to obtain time";
    }
    char year[5];
    strftime(year, 5, "%Y", &timeinfo);
    int day = *(&timeinfo.tm_mday);
    int month = *(&timeinfo.tm_mon);

    return String(year) + "-" + String(month) + "-" + String(day);
}