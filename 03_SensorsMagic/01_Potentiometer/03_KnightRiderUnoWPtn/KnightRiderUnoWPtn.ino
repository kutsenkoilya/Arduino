/*
Knight Rider uno with potentiometer
LED strip where one LED is shining, its location depends on potentiometer value.
In this implementation LEDs are attached to pins 0 to 13
Warning: startPin < endPin
Potentiometer is attached to A0

*/
#define PotenPin A0
int startPin = 0;
int endPin = 13;
bool isReversed = false;
int pointer;

void setup() {
  pinMode(PotenPin, INPUT);
  for (int i=startPin;i<=endPin;i++)
  {
    pinMode(i, OUTPUT);  
    digitalWrite(i,LOW);
  }  
}

void loop() {
    pointer = analogRead(PotenPin) * 14 / 1023;
    //эту красоту тоже надо потестить
    for (int i=startPin;i<=endPin;i++)
    { 
      digitalWrite(i,LOW);
    }
    
    digitalWrite(pointer,HIGH);  
}





