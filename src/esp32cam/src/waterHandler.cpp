#include "waterHandler.h"

water::water(std::string cfgpath) : cfg(cfgpath)
{

}

water::~water()
{

}

void water::waterPlant()
{
    digitalWrite(config::PUMP, HIGH);
    sleep(5);
    digitalWrite(config::PUMP, LOW);
    openHandle();
    if(fileExists())
    {
        StaticJsonDocument<1024> doc; // insecure asfuck but who cares as long it works
        deserializeJson(doc, loadConfig());
        if(doc.containsKey(currentDate()))
        {
            int count = doc.getMember(currentDate());
            count++;
            doc[currentDate()] = count;
        }
        else
        {
            doc[currentDate()] = 1;
        }
        String save;
        serializeJson(doc, save);
        saveConfig(save);
        currentConfig = save;
    }
    else
    {
        StaticJsonDocument<32> doc;
        doc[currentDate()] = 1;
        String save;
        serializeJson(doc, save);
        saveConfig(save);
        currentConfig = save;
    }
}

String water::currentDate()
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
    int month = *(&timeinfo.tm_mon) + 1;

    return String(year) + "-" + String(month) + "-" + String(day);
}