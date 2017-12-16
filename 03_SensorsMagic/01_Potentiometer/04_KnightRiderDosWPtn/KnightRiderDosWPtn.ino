
/*
Knight Rider dos with potentiometer
LED strip where two opposide LEDs are shining, their location depends on potentiometer value.
In this implementation LEDs are attached to pins 0 to 13
Warning: startPin < endPin
Potentiometer is attached to A0

*/
#define PotenPin A0
int startPin = 0;
int endPin = 13;
int pointer=1;

void setup() {
  pinMode(PotenPin, INPUT);
  for (int i=startPin;i<=endPin;i++)
  {
    pinMode(i, OUTPUT);  
  }
}

// the loop function runs over and over again forever
void loop() {

  pointer = analogRead(PotenPin) * (endPin-startPin) / 1023;

  for (int i=startPin;i<=endPin;i++)
  { 
    digitalWrite(i,LOW);
  }
    
  digitalWrite(pointer+startPin,HIGH);  
  digitalWrite(endPin-pointer,HIGH);  
  
}





