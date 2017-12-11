/* 
  Кнопочный потенциометр с дебаунсом
  В схеме воткнут потеницометр и диод
  1. Ардуино считывает показания с потенциометра (целое число от 0 до 1024)
  2. делит число на 4 (получает число от 0 до 255)
  3. Подает это значение на диод
  В итоге, яркость диода зависит от того, как повернута ручка потенциометра

  ДОПОЛНИТЕЛЬНО: в схеме есть кнопка, по нажатии на которую, потенциометр
  начинает работать в противоположную сторону, то есть
  если поворот по часовой стрелке зажигал диод, то теперь он гасит...

  Потенциометр воткнут в аналоговый пин 0 (analog in 0) (Потециометр питается от 5V)
  Диод в цифровой пин 2
  Кнопка воткнута в цифровой пин 3 (так же частично питается от 5 вольт)

*/

#define PotenPin A0
#define LedPin 2

#define ButtonPin 3

bool oldState = false;
bool turnedOn = false;

void setup() {
  pinMode(PotenPin, INPUT);
  pinMode(LedPin, OUTPUT);
  pinMode(ButtonPin, INPUT);
}

void loop() {

  int data = analogRead(PotenPin);
  
  bool curRead = digitalRead(ButtonPin);
  
  if (curRead>oldState)
  {
      turnedOn = !turnedOn;
  }
  
  if (!turnedOn)
  {
    data = 1023 - data;
  }

  analogWrite(AnalogWritePin,data/4);  

  oldState = curRead;
  delay(10);
}
