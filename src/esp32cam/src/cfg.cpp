#include "cfg.h"

cfg::cfg(std::string cfgpath)
{

}
cfg::~cfg()
{
    
}

bool cfg::openHandle()
{
    return false;
}

String cfg::loadConfig()
{
    return "";
}

bool cfg::saveConfig(String cfg)
{
    return false;
}

bool cfg::closeHandle()
{
    return false;
}

bool cfg::isHandleOpen()
{
    return mIsOpen;
}