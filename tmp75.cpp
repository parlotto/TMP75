#include "tmp75.h"

TMP75::TMP75(uint8_t address) {

  i2cAddress = address;

}

int TMP75::begin(uint8_t configReg) {

  Wire.beginTransmission(i2cAddress);
  Wire.write(TMP75_CONF_REG);
  Wire.write(configReg);
  return Wire.endTransmission();
}





float TMP75::readTemperature() {

  uint8_t msb, lsb ;

  // Setup Pointer Register to TEMP register
  Wire.beginTransmission(i2cAddress);
  Wire.write(TMP75_TEMP_REG);
  Wire.endTransmission();

  // Read temperature value
  Wire.requestFrom(i2cAddress, 2);
  while (Wire.available())         // Check for data from slave
  {
    msb  = Wire.read();       // Read temperature high byte
    lsb = Wire.read();       // Read temperature low byte
  }
  //Serial.println(msb, HEX);
  //Serial.println(lsb, HEX);

  return msb + lsb / 256.0 ;

}


 void TMP75::setHighLimit( float highLimit ){
    
  
    int msb = highLimit ;
    int lsb = (highLimit - msb) * 256;
    Wire.beginTransmission(i2cAddress);
    Wire.write(TMP75_THIGH_REG);
    Wire.write(msb);
    Wire.write(lsb & 0xF0);
    Wire.endTransmission();
   
 }
 
 void TMP75::setLowLimit( float lowLimit ){
    
  
    int msb = lowLimit ;
    int lsb = (lowLimit - msb) * 256;
    Wire.beginTransmission(i2cAddress);
    Wire.write(TMP75_TLOW_REG);
    Wire.write(msb);
    Wire.write(lsb & 0xF0);
    Wire.endTransmission();
   
 }
 
