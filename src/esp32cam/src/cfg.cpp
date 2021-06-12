#include "cfg.h"

cfg::cfg(std::string cfgpath)
    : mConfigPath(cfgpath)
{

}

cfg::~cfg()
{
    
}

void cfg::openHandle()
{
    if (!SPIFFS.begin(true))
    {
        Serial.println("An Error has occurred while mounting SPIFFS");
    }
    mIsOpen = true;
}

String cfg::loadConfig()
{
    File filetoread = SPIFFS.open(mConfigPath.c_str(), FILE_READ);
    String str;
    if(!filetoread){
        Serial.println("Failed to open file for reading");
        return "";
    }
    str = filetoread.readString();
    filetoread.close();
    return str;
}

bool cfg::saveConfig(String cfg)
{
    File file = SPIFFS.open(mConfigPath.c_str(), FILE_WRITE);
    if(!file)
    {
        Serial.println("There was an error opening the file for writing");
        return false;
    }
    if(file.print(cfg))
    {
        file.close();
        return true;
    }
    return false;
}

bool cfg::fileExists()
{
    return SPIFFS.exists(mConfigPath.c_str());
}

void cfg::closeHandle()
{
    SPIFFS.end();
    mIsOpen = false;
}

bool cfg::isHandleOpen()
{
    return mIsOpen;
}