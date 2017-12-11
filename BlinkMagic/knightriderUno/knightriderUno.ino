/*
Knight Rider uno
Огонек движется из из крайнего левого угла в праввый (и обратно)
по диодной ленте
В данной реализации порты от 0 до 12 подключены к диодам
важно чтобы startPin был меньше endPin
*/
int startPin = 0;
int endPin = 12;
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





