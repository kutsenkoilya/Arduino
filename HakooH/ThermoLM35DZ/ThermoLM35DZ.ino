//Тоже не работает как надо

float tempC; // определяем переменную для показаний температуры
int reading; // определяем переменную для считывания "сырых" данных с датчика
int tempPin = 0; // определяем контакт подключения датчика
 
void setup()
{
  Serial.begin(9600);
  analogReference(INTERNAL);
}
 
void loop()
{
  reading = analogRead(tempPin);
  tempC = reading / 9.31;
  Serial.print("Deg C = "); 
  Serial.println(tempC);
  delay(1000);
}
