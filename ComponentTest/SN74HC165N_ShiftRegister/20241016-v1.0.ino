/*
  Title:        Testing SN74HC165N Parallel-in, Series-out
  Author(s):    Cian Brady
  Date:         2024-10-16
  Comments:

*/

int dataPin = 12;  // Qh (serial out) pin from 74HC165 to Arduino
int clockPin = 10; // Clock pin
int latchPin = 8;  // Latch pin (PL)

void setup() {
  // Set pin modes
  pinMode(dataPin, INPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Load the parallel data into the shift register
  digitalWrite(latchPin, LOW);  // Pull low to load data
  delayMicroseconds(5);         // Short delay to ensure loading
  digitalWrite(latchPin, HIGH); // Latch data

  // Shift out the data serially
  for (int i = 0; i < 8; i++) {
    // Clock the data out
    digitalWrite(clockPin, LOW);            // Prepare for reading
    int bitValue = digitalRead(dataPin);    // Read the bit
    Serial.print(bitValue);                 // Print the bit value
    digitalWrite(clockPin, HIGH);           // Move to the next bit
  }
  Serial.println();  // Move to the next line for clarity

  // Wait a little before reading again
  delay(500);
}
