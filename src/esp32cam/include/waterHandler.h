#ifndef WATERHANDLER_H
#define WATERHANDLER_H

#include "common_includes.h"
#include "cfg.h"
#include "config.h"
#include <ArduinoJson.h>

class water : public cfg
{
public:
    water(std::string cfgpath);
    ~water();
    void waterPlant();
    String currentConfig;
private:
    String currentDate();
};
#endif