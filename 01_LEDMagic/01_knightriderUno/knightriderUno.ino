/*
Knight Rider Uno
Flame is 'running' from leftmost LED to rightmost, back and forth in LED strip
In this implementation LEDs are sequentially attached to digital pins 0 to 13
Warning: startPin value must be smaller than endPin value (startPin < endPin)

Program can be changed for any numer of LEDs, just change startPin and endPin
*/

int startPin = 0;
int endPin = 13;
bool isReversed = false;
int pointer = 0;

void setup() {
  for (int i=startPin;i<=endPin;i++)
  {
    pinMode(i, OUTPUT);  
  }
  
  pointer = startPin;
}

void loop() {
  
    digitalWrite(pointer,HIGH);  
    delay(100);
    digitalWrite(pointer,LOW);
      
    if (isReversed)
    {
      pointer--;
    }
    else
    {
      pointer++;
    }
     
    if (pointer==endPin || pointer==startPin)
    {
      isReversed = !isReversed;
    }
}





