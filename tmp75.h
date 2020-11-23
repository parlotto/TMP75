#ifndef TMP75_H
#define TMP75_H

#include <Wire.h>
#include <Arduino.h>

#define TMP75_DEFAULT_ADDR 0x48 // address with A0=A1=A2=GND

#define TMP75_DEFAULT_CONFIG 0x60 // 12 bits , 0 fault queue, ALERT low polarity, comparator mode  

// registers pointers
#define TMP75_TEMP_REG 0
#define TMP75_CONF_REG 1
#define TMP75_TLOW_REG 2
#define TMP75_THIGH_REG 3



class TMP75 {
  public :
     TMP75(uint8_t address=TMP75_DEFAULT_ADDR);
     int begin(uint8_t configReg= TMP75_DEFAULT_CONFIG);
     float readTemperature();
     void setHighLimit( float highLimit );
     void setLowLimit(  float lowLimit );
  private :
     uint8_t i2cAddress;


};

#endif
