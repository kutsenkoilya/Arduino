/* 
  Basic Potentiometer
  Scheme contains potentiometer and LED
  1. Arduino reading from potentiometer (value from 0 to 1024)
  2. dividing by 4 (get value from 0 to 255)
  3. sending result to LED
  As the result LED brightness depends on potentiometer position

  Potentiometer is attached to Analog 0 (A)
  LED is attached to Pin 2

*/

#define PotenPin A0
#define LedPin 2

void setup() {
  pinMode(PotenPin, INPUT);
  pinMode(LedPin, OUTPUT);
}

void loop() {
  analogWrite(LedPin,
                  analogRead(PotenPin)/4);  
  delay(10);
}
