#include "GravityTDS.h"

GravityTDS gravityTds;


void setup() {
  Serial.begin(1000000);
  while(!Serial);

  analogReadResolution(12);

  gravityTds.setPin(26);
  gravityTds.setAref(3.3);  //reference voltage on ADC, default 5.0V on Arduino UNO
  gravityTds.setAdcRange(4096);  //1024 for 10bit ADC;4096 for 12bit ADC
  gravityTds.setKvalue(0.039297597);
  gravityTds.begin();  //initialization

  pinMode(27, INPUT);

}

void loop() {

   
  //ntc----------------------------------------------
  float ntc = 0.0;
  
  for(int i = 0; i< 100; i++) {
    ntc += analogRead(27);
    delay(1);
  }
  
  ntc /= 100.0;         //average adc value
  ntc = ntc/4096*3.3;   //voltage

  ntc = ntc * (47000/(3.3-ntc));


  float steinhart;
  steinhart = ntc / 50000; // (R/Ro)
  steinhart = log(steinhart); // ln(R/Ro)
  steinhart /= 3950; // 1/B * ln(R/Ro)
  steinhart += 1.0 / (25.0 + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart; // Invert
  steinhart -= 273.15; // convert to C
  ntc = steinhart;


  //ntc----------------------------------------------


  gravityTds.setTemperature(ntc);
  gravityTds.update();


  Serial.print("EC: ");
  Serial.print(gravityTds.getEcValue(), 2);
  Serial.print(" µS/cm (");
  Serial.print(gravityTds.getTemperature(), 1);
  Serial.println(" °C)");
  
  

  delay(1000);

}
