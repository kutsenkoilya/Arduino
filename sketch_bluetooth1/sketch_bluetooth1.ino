int val;
int LED = 13;
void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
}
void loop()
{
  if (Serial.available())
  {
    val = Serial.read();
    // При символе "1" включаем светодиод
    if (val == 'q')
    {
      digitalWrite(LED, HIGH);
    }
    if (val=='w')
    // При символе "0" выключаем светодиод
    {
      digitalWrite(LED, LOW);
    }
  }
}
