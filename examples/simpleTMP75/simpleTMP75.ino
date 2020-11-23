#include <tmp75.h>

#define T_LOW 24.8
#define T_HIGH 25.0125

TMP75 mySensor; // mySensor at default i2c address

void setup(){
  Serial.begin(9600);
  int error=mySensor.begin();
  if (error) {
    Serial.println("TMP75 not responding...");
    while(1);
  }
 // ALERT pin should be low if temperature is above T_HIGH
 // and should return to high when temperature is below T_LOW
 mySensor.setHighLimit(T_HIGH);
 mySensor.setLowLimit(T_LOW);
  
}

void loop(){
  float temp = mySensor.readTemperature();
  Serial.print("Temp = ");
  Serial.print(temp,4); // 4 decimals to see full 12 bits resolution
  Serial.println(" Celsius");
  delay(500);
  
}
