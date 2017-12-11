
/*
Knight Rider dos
Два огонька движутся навстречу друг другу из разных концов диодной ленты
В данной реализации порты от 0 до 12 подключены к диодам
важно чтобы startPin был меньше endPin
*/
int startPin = 0;
int endPin = 12
int pointer=1;

void setup() {
  for (int i=startPin;i<=endPin;i++)
  {
    pinMode(i, OUTPUT);  
  }
}

// the loop function runs over and over again forever
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





