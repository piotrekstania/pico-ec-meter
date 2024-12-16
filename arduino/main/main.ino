#include "ec.h"

void setup() {
Serial.begin(1000000);
while(!Serial);


Serial.println(ecCompensation(5.65), 3);

}

void loop() {



}
