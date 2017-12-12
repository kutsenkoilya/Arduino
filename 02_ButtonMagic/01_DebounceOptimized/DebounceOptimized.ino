/*
Оптимизированный ДЕБАУНС - на первое нажатие диод включается,
 на второе - выключается и тд.

Диод подкючен в 12ый
Кнопка в 13ый
*/

#define LEDPin 12
const int BTNPin = 13;
bool oldState = false;
bool turnedOn = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(BTNPin, INPUT);
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool curRead = digitalRead(BTNPin);
  
  //предыдущая версия if: oldState != curRead && curRead
  //на самом деле, если if такой (curRead == true and curRead!=oldState)
  //это значит: 1. curRean == true and oldState == false => (curRead && !oldState)
  //или       : 2. curRead > oldState
  //дополнительно, если curRead < oldState,
  // то срабатывать будет на "выключение" - переход из 1 в 0 
  if (curRead > oldState) 
  {
      turnedOn = !turnedOn;
      digitalWrite(LEDPin,turnedOn);
  }

  oldState = curRead;
  delay(100);
}
