/***
 * Title:        Reading row1 of Chess board
 * Author(s):    Joe Biju; Cian Brady
 * Date:         2024-11-15
 * Comments:
 * - 3.75μs Response Time Delay of AH3562Q Hall Effect Sensor
 * - SNx4HC165 Shift Register triggered on rising edge  of Clock

***/
/*Definitions of Pin*/
#define dataPin   12    // Serial Out (Qh)
#define clockPin  10    // Clock pin (CLK)
#define latchPin  8     // Latch pin (SH/(LD)')

/*Toggles latchPin to load data parallel in*/
void loadData(void) {
  digitalWrite(latchPin, LOW);  // Pull LOW to load data
  delayMicroseconds(5);         // Short delay to ensure loading (3.75μs Response Time Delay of AH3562Q)
  digitalWrite(latchPin, HIGH); // Pull HIGH to latch data
  
  return;
}

/*Toggles clock to shift in byte to store in rowArray[]*/
void readByte(int rowArray[]) {
  int bit = 0;                              // Value
  for (int i = 0; i < 8; i++) {             // 8 Parallel-in Pins on Shift-register
    digitalWrite(clockPin, LOW);            // Clock Falling Edge (data not shifted)
    rowArray[8-1-i] = digitalRead(dataPin); // Store value at A column of rowArray
    // Serial.print(digitalRead(dataPin));  
    digitalWrite(clockPin, HIGH);           // Clock Rising Edge (SNx4HC165 triggered on rising edge)
    delayMicroseconds(1);                   // Shift register has max delay of ~50ns when operating at 5V
  }
  // Serial.println("");
  
  return;
}

/*Prints our data in an array of specified size*/
void printArray(int array[], int array_size) {
  for (int i = 0; i < array_size; i++) {
    Serial.print(array[i]);
  }
  Serial.println();
  
  return;
}

void setup() {
  /*Set pin modes*/
  pinMode(dataPin, INPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  
  /*Initialize serial communication for debugging*/
  Serial.begin(115200);
}

void loop() {
  /*Intialise*/
  int board_row1[8];

  /*Read data from Shift Registers*/
  loadData();
  readByte(board_row1);

  /*Output read data*/
  printArray(board_row1, 8);

  delay(1);

}
