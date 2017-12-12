/*
Knight Rider uno with potentiometer
Диодная лента, в котором положение светящегося огонька определяется потенциометром
В данной реализации порты от 0 до 12 подключены к диодам
важно чтобы startPin был меньше endPin
Потециометр воткнут в A0
*/
#define PotenPin A0
int startPin = 0;
int endPin = 10;
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
    pointer = analogRead(PotenPin) * 10 / 1023;
    //эту красоту тоже надо потестить
    for (int i=startPin;i<=endPin;i++)
    { 
      digitalWrite(i,LOW);
    }
    
    digitalWrite(pointer,HIGH);  
}





