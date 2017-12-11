
//Светофор
//4 Пин - Красный Диод
//5 Пин - Жёлтый
//6 Пин - Зеленый

//Последовательность загораний
//1. Красный(4) горит 5 сек
//2. Зеленый(6) горит 3 сек
//3. Зеленый(6) моргает 3 раза
//4. Жёлтый (5) горит 1 сек

void setup() {
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {

  blink(4,5000);
  blink(6,3000);
  delay(200);
  blink(6,1000);
  delay(200);
  blink(6,1000);
  delay(200);
  blink(6,1000);
  blink(5,1000);

}

void blink(int portnum, int delayt)
{
  digitalWrite(portnum, HIGH);
  delay(delayt);
  digitalWrite(portnum, LOW);
}




