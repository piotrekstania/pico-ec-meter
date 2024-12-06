# Water Electric Conductivity Hat for Raspberry Pi Pico 
Simple water conductivity meter as hat to Raspberry Pi Pico. Works with original Pico/Pico 2 and Pico based WIZnet modules with built-in ethernet connectivity.
Hat works with popular and cheap flow meter with NTC sensor and TDS probe.

Project includes:
* KiCad project of hat (schematic and pcb)
* Arduino code examples

## Flow meter with NTC sensor and TDS probe 
Specification : 
* Function: Sensor , flow rate control
* Connect pipe: ~ OD9 MM
* Color :white
* Flow rate: 0.3~10 L/min
* Flow Pulse:  F(Hz)=21*Q + -2%  Q=LPM (L/min) (1260 p/L)
* Max. Working Current: 15mA (DC5 V)
* Min. Working Voltage: DC 4.5V
* Working Voltage:DC 3V~18V
* Load Capacity: = 10 mA (DC 5 V)
* Pressure :<0.8mPa
* Operating  Working  Temperature: 0..+80  Degree
* Accuracy :+- 2%
* Cable wire:
  * red: +5V
  * yellow: NPN signal output
  * black: GND
  * green:  NTC temperature sensor 50K
  * blue & red:  TDS ( total dissolved solide) water quality teser sensor
