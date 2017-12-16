/*
If button is pressed - LED is blinking
*/

#define LEDPin 12
const int BTNPin = 2;
const int InterNum = 0;

void setup() {
  pinMode(LEDPin, OUTPUT);
  attachInterrupt(InterNum,blinkingState,RISING);
  Serial.begin(9600);
}

void blinkingState() {
  delay(50);
  
  while(digitalRead(BTNPin))
  {
    digitalWrite(LEDPin,HIGH);
    delay(50000);
    digitalWrite(LEDPin,LOW);
    delay(50000);
  }
}

void loop() {
    digitalWrite(LEDPin,LOW);
}
