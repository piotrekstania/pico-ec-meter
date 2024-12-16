#include "ec.h"

float ecCompensation(float temp) {

  if(temp < 0.0) temp = 0.0;
  if(temp > 35.9) temp = 35.9;

  temp = temp * 10.0;
  temp = round(temp);
  
  return f25[int(temp)];
}