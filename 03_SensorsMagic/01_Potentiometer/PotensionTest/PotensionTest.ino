#define AnalogReadPin A0
#define AnalogWritePin 2

#define Button 3

bool oldState = false;
bool turnedOn = false;

void setup() {
  pinMode(AnalogReadPin, INPUT);
  pinMode(AnalogWritePin, OUTPUT);
  pinMode(Button, INPUT);
}

void loop() {

  int data = analogRead(AnalogReadPin);
  
  bool curRead = digitalRead(Button);
  
  if (oldState != curRead && curRead)
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
