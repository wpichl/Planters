#include "ADCHandler.h"

ADCHandler::ADCHandler(int SDA, int SCL)
    : mSDA(SDA), mSCL(SCL)
{

}

ADCHandler::~ADCHandler()
{
    
}

void ADCHandler::Init()
{
    I2C.begin(mSDA, mSCL, 100000);
    ads.begin(0x48, &I2C);
}

int16_t ADCHandler::getADC()
{
    return ads.readADC_SingleEnded(0);
}