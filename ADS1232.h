#ifndef ADS1232_H
#define ADS1232_H

#include <Arduino.h>

class ADS1232 {
public:
    ADS1232();
    void begin(int doutPin, int sclkPin, int a0);
    long readRaw(int channel);
    long readMedian(int channel, int numSamples);

private:
    int _doutPin;
    int _sclkPin;
    int _a0;
};

#endif
