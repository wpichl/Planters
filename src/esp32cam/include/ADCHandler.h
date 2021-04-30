#ifndef ADCHANDLER_H
#define ADCHANDLER_H

#include "common_includes.h"

class ADCHandler {
public:
    ADCHandler(int SDA, int SCL);
    ~ADCHandler();
    void Init();
    int16_t getADC();

private:
    TwoWire I2C = TwoWire(0);
    Adafruit_ADS1115 ads;
    int mSDA;
    int mSCL;
};
#endif