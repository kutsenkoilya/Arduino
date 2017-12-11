
/*
Knight Rider dos
Два огонька движутся навстречу друг другу из разных концов диодной ленты
В данной реализации порты от 0 до 12 подключены к диодам
важно чтобы startPin был меньше endPin
*/
#define PotenPin A0
int startPin = 0;
int endPin = 10;
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





