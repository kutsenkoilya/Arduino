/* 
  Basic potentiometer w button  

  Scheme contains potentiometer and LED
  1. Arduino reading from potentiometer (value from 0 to 1024)
  2. dividing by 4 (get value from 0 to 255)
  3. sending result to LED
  As the result LED brightness depends on potentiometer position

  Modification: Scheme contains button. On button press, potentiometer
  is getting reversed - if clockwise turn was adding brightness to LED,
  after button press it starts dimming LED and vise versa.

  Potentiometer - Analog 0 (A0)
  LED - Pin 2
  Button - Pin 3

*/

#define PotenPin A0
#define LedPin 2

#define ButtonPin 3

bool oldState = false;
bool turnedOn = false;

void setup() {
  pinMode(PotenPin, INPUT);
  pinMode(LedPin, OUTPUT);
  pinMode(ButtonPin, INPUT);
}

void loop() {

  int data = analogRead(PotenPin);
  
  bool curRead = digitalRead(ButtonPin);
  
  if (curRead>oldState)
  {
      turnedOn = !turnedOn;
  }
  
  if (!turnedOn)
  {
    data = 1023 - data;
  }

  analogWrite(AnalogWritePin,data/4);  

  oldState = curRead;
  delay(10);
}
