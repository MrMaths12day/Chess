# SN74HC165

### Resources
[RS Online]          https://ie.rs-online.com/web/p/counter-ics/3332978?gb=s <br/>
[Texas Instruments]  https://www.ti.com/lit/ds/symlink/sn74hc165.pdf

### Notes
- SN74HC165N - Plastic Dual Inline Package (PDIP) (16) - 6.60 mm × 18.92 mm _(that's what the N at the end signifies)_

### Pinout _(most relevant ones)_
- A-H | Parallel Input
- CLK | Clock Pin
- CLK INH | Clock inhibit _(similar to (ENABLE)')_
- Qh | Serial output
- SH/(LD)' | LOW allows inputs to be read; HIGH locks data and allows to be shifted on CLK pulse

### HOW TO USE SN74HC165:
1. Power and ground the breadboard, connecting power to 5v on the Arduino.
2. Use 10k resistor between power and ground (pull-up resistor).
3. Connect power to pin 16 and ground to pin 8.
4. Connect pin 2 (clock) on shift register to data pin 10 on Arduino.
5. Connect pin 1 (latch) on shift register to data pin 8 on Arduino.
6. Connect pin 9 (Qh) on shift register to data pin 12 on Arduino.
7. Now connect pins (3-6) and pins (11-14) to either power or ground. Power will output logic HIGH (1) and ground will output logic LOW (0).
NOTE: Every pin NOT IN USE (7, 10, 15) should be connected to ground or output will be unpredictable. <br/>
![Image of breadboard](https://github.com/jb-labs-456/RoboChess-ElecSoc/blob/main/Files/Media/20241023_185454.jpg)
