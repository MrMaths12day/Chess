# HOW TO USE SN74HC165:

1. Power and ground the breadboard, connecting power to 5v on the Arduino.
2. Use 10k resistor between power and ground (pull-up resistor).
3. Connect power to pin 16 and ground to pin 8.
4. Connect pin 2 (clock) on shift register to data pin 10 on Arduino.
5. Connect pin 1 (latch) on shift register to data pin 8 on Arduino.
6. Connect pin 9 (Qh) on shift register to data pin 12 on Arduino.
7. Now connect pins (3-6) and pins (11-14) to either power or ground. Power will output logic HIGH (1) and ground will output logic LOW (0).
NOTE: Every pin NOT IN USE (7, 10, 15) should be connected to ground or output will be unpredictable.
