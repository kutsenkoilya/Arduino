/*
  Implmentation is using interrupt
  
  Button fast-released - LED is turning ON, always
  Button slow-released - LED is turning OFF, always
  
*/

#define LEDPin 12
const int BTNPin = 2;
const int InterNum = 0;
bool turnedOn = false;
int glowLen = 0;
int glowTime = 500;

void setup() {
  pinMode(LEDPin, OUTPUT);
  attachInterrupt(InterNum,setupState,RISING);
  Serial.begin(9600);
}

void setupState() {
  delay(50);
  glowLen = 50;

  if (digitalRead(BTNPin))
  {
    while(digitalRead(BTNPin))
    {
      glowLen++;
      delay(1);
    }
  }
  else {
    glowLen = 0;
  }
  
  if (glowLen>glowTime)
  {
    turnedOn = 0;
    }
  else
  {
    turnedOn = 1;
    }
  
  Serial.print("glowLen="); Serial.println(glowLen); 
  Serial.print("turnedOn="); Serial.println(turnedOn); 
}

void loop() {
    digitalWrite(LEDPin,turnedOn);
}
