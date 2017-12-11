/*
  Реализация дебаунса через Interrupt
*/

#define LEDPin 12
const int BTNPin = 0;
bool turnedOn = false;

void setup() {
  pinMode(LEDPin, OUTPUT);
  attachInterrupt(BTNPin,changestate,RISING);
  Serial.begin(9600);
}

void changestate()
{
  turnedOn = !turnedOn;
  delay(20);
  }

void loop() {
  digitalWrite(LEDPin,turnedOn);
}
