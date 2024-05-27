# ADS1232
a very simple arduino library for my personal needs. I used it for a pair of load cells

PIN CONFIG
POWER:
1. DVDD -> Digital voltage 3.3v or 5v
2. DGND -> Digital gnd
3. REFP -> Reference voltage
4. REFN-> Reference ground
5. AVDD -> Analog voltage (2.7 V to 5.3 V)
6. AGND -> Analog gnd

SIGNAL:
1. AINP1, AINN1 -> Channel 1
2. AINP2, AINN2 -> Channel 2
3. DOUT -> Data ready and data output; indicates when new data are ready by going low (MCU Digital PIN)
4. SCLK -> Serial clock input (MCU Digital PIN)
5. PDOWN -> Tied to DVDD 
6. GAIN0 -> Tied to DVDD
7. GAIN1 -> Tied to DVDD
8. SPEED -> Tied to DVDD (HIGH SPEED MODE)/ Tied to GND (LOW SPEED MODE)
9. 6. A0 -> GND for channel 1 , DVDD for channel 2

MISC:
1. CLKIN/XTAL1
2. XTAL2
3. CAP1
4. CAP2
5. TEMP -> GND


