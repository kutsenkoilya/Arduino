/*
Knight Rider Dos
Two flames are moving back and forth in mirror way in the LED strip.
In this implementation LEDs are sequentially attached to digital pins 0 to 13
Warning: startPin value must be smaller than endPin value (startPin < endPin)

Program can be changed for any numer of LEDs, just change startPin and endPin
*/
int startPin = 0;
int endPin = 13
int pointer=1;

void setup() {
  for (int i=startPin;i<=endPin;i++)
  {
    pinMode(i, OUTPUT);  
  }
}

void loop() {
  
  digitalWrite(pointer+startPin,HIGH);  
  digitalWrite(endPin-pointer,HIGH);  
  delay(1000);
  digitalWrite(pointer+startPin,LOW);
  digitalWrite(endPin-pointer,LOW);  
  
  pointer++;
  
  if (pointer == endPin-startPin+1)
  {
    pointer = 1;
  }
  
}





