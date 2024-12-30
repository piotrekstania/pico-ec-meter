#include "GravityTDS.h"

GravityTDS gravityTds;

#include <SerialBT.h>

float ntc(uint8_t pin) {

  pinMode(pin, INPUT);

  float average = 0.0;

  for (int i=0; i<100; i++) {
     average += analogRead(pin);
     delay(1);
  }
  
  average /= 100.0;
  average = 4095 / average - 1;
  average = 10000.0 / average;   //R to Vcc

  float steinhart;

  steinhart = average / 10000.0;      // (R/Ro)
  steinhart = log(steinhart);         // ln(R/Ro)
  steinhart /= 3950.0;                // 1/B * ln(R/Ro)
  steinhart += 1.0 / (25.0 + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;        // Invert
  steinhart -= 273.15;                // convert to C

  return steinhart;
}

void setup() {

  Serial.begin(1000000);

  analogReadResolution(12);

  gravityTds.setPin(26);
  gravityTds.setAref(3.3);  //reference voltage on ADC, default 5.0V on Arduino UNO
  gravityTds.setAdcRange(4096);  //1024 for 10bit ADC;4096 for 12bit ADC
  gravityTds.setKvalue(0.039297597);
  gravityTds.begin();  //initialization

  SerialBT.setName("fogsys");
  SerialBT.begin();
}

void loop() {


  gravityTds.setTemperature(ntc(27));
  gravityTds.update();


  SerialBT.print("EC: ");
  SerialBT.print(gravityTds.getEcValue(), 2);
  SerialBT.print(" µS/cm (");
  SerialBT.print(gravityTds.getTemperature(), 1);
  SerialBT.println(" °C)");

  Serial.print("EC: ");
  Serial.print(gravityTds.getEcValue(), 2);
  Serial.print(" µS/cm (");
  Serial.print(gravityTds.getTemperature(), 1);
  Serial.println(" °C)");
  

  delay(1000);

}
