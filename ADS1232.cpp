#include "ADS1232.h"

ADS1232::ADS1232() {
}

void ADS1232::begin(int doutPin, int sclkPin, int a0) {
    _doutPin = doutPin;
    _sclkPin = sclkPin;
    _a0 = a0;
    pinMode(_doutPin, INPUT);
    pinMode(_sclkPin, OUTPUT);
    pinMode(_a0, OUTPUT);

    digitalWrite(_sclkPin, LOW);  // Ensure SCLK is initially low
}

long ADS1232::readRaw(int channel) {

    // 1. PREPARING ADS
    // Choose ads channel (1 OR 2)
    switch (channel)
    {
    case 1: // If channel 2 is chosen, then A0 needs to be LOW
        digitalWrite(_a0, LOW);
        break;
    case 2: // If channel 2 is chosen, then A0 needs to be HIGH
        digitalWrite(_a0, HIGH);
        break;
    }

    // 2. READING ADS
    while (digitalRead(_doutPin) == HIGH);  // Wait for DRDY to go low

    long rawData = 0;

    // Read 24-bit data from ADS1232
    for (int i = 0; i < 24; i++) {
        digitalWrite(_sclkPin, HIGH);  // Set clock high
        rawData = (rawData << 1) | digitalRead(_doutPin);  // Read data bit
        digitalWrite(_sclkPin, LOW);  // Set clock low
    }

    // Convert to signed 24-bit integer
    if (rawData & 0x800000) {
        rawData |= 0xFF000000;
    }

    return rawData;
}

long ADS1232::readMedian(int channel, int numSamples) {
    long readings[numSamples];
    for (int i = 0; i < numSamples; i++) {
        readings[i] = readRaw(channel);
        delay(60);
    }

    // Sort readings array
    for (int i = 0; i < numSamples - 1; i++) {
        for (int j = i + 1; j < numSamples; j++) {
            if (readings[i] > readings[j]) {
                long temp = readings[i];
                readings[i] = readings[j];
                readings[j] = temp;
            }
        }
    }

    // Return median value
    if (numSamples % 2 == 0) {
        return (readings[numSamples / 2 - 1] + readings[numSamples / 2]) / 2;
    } else {
        return readings[numSamples / 2];
    }
}
