#ifndef CFG_H
#define CFG_H

#include "common_includes.h"
#include <SPIFFS.h>

class cfg
{
public:
    cfg(std::string cfgpath);
    ~cfg();
    void openHandle();
    String loadConfig();
    bool saveConfig(String cfg);
    bool fileExists();
    void closeHandle();
    bool isHandleOpen();

private:
    std::string mConfigPath;
    bool mIsOpen;
};

#endif
