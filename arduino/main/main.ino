#include "GravityTDS.h"

GravityTDS gravityTds;
float temp, ec;

void setup() {
  Serial.begin(1000000);
  while(!Serial);

  analogReadResolution(12);

  gravityTds.setPin(26);
  gravityTds.setAref(3.3);  //reference voltage on ADC, default 5.0V on Arduino UNO
  gravityTds.setAdcRange(4096);  //1024 for 10bit ADC;4096 for 12bit ADC
  gravityTds.setKvalue(0.039297597);
  gravityTds.begin();  //initialization


}

void loop() {

  temp = 13.5;

  gravityTds.setTemperature(temp);  // set the temperature and execute temperature compensation
  gravityTds.update();  //sample and calculate
  ec = gravityTds.getEcValue();  // then get the value

  Serial.print("EC: ");
  Serial.print(ec, 2);
  Serial.print(" µS/cm (");
  Serial.print(temp, 1);
  Serial.println(" °C)");

  delay(1000);

}
