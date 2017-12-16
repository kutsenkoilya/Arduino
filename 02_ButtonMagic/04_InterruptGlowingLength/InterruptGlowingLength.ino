/*
  Implmentation is using interrupt

  When button is pressed,
  code is counting how many seconds button was pressed
  after button release - LED is blinking with same time period

  Example:
  1. button was pressed for 1 sec
  2. LED is ON for 1 sec
  3. LED is OFF for 1 sec
  4. пункт 2back to item 2

*/

#define LEDPin 12
const int BTNPin = 2;
const int InterNum = 0;
bool turnedOn = false;
int glowLen = 0;

void setup() {
  pinMode(LEDPin, OUTPUT);
  attachInterrupt(InterNum,setupLength,RISING);
  Serial.begin(9600);
}

void setupLength() {
  delay(20);
  glowLen = 20;
  
  while(digitalRead(BTNPin))
  {
    glowLen++;
    delay(1);
  }
  Serial.print("glowLen="); Serial.println(glowLen); 
}

void loop() {
    digitalWrite(LEDPin,HIGH);
    delay(glowLen);
    digitalWrite(LEDPin,LOW);
    delay(glowLen);
}
