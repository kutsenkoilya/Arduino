/*
  Использует Interrupt

  Зажимаешь кнопку, 
  оценивает сколько кнопка была нажата и
  потом диод мигает с такой же частотой

  Пример:
  1. зажали на 1 секунде
  2. диод горит 1 секунду
  3. диод не горит 1 сек
  4. пункт 2

*/

#define LEDPin 12
const int BTNPin = 2;
const int InterNum = 0;
bool turnedOn = false;
int glowLen = 0;

void setup() {
  pinMode(LEDPin, OUTPUT);
  attachInterrupt(InterNum,setupLength,RISING);
  Serial.begin(9600);
}

void setupLength() {
  delay(20);
  glowLen = 20;
  
  while(digitalRead(BTNPin))
  {
    glowLen++;
    delay(1);
  }
  Serial.print("glowLen="); Serial.println(glowLen); 
}

void loop() {
    digitalWrite(LEDPin,HIGH);
    delay(glowLen);
    digitalWrite(LEDPin,LOW);
    delay(glowLen);
}
