#ifndef CFG_H
#define CFG_H

#include "common_includes.h"
class cfg
{
public:
    cfg(std::string cfgpath);
    ~cfg(); // close file
    bool openHandle();
    String loadConfig();
    bool saveConfig(String cfg);
    bool closeHandle();
    bool isHandleOpen();

private:
    std::string mConfigPath;
    bool mIsOpen;
};

#endif
