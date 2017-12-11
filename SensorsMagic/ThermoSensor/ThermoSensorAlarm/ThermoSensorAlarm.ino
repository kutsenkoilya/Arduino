/*
  Пожарная сигнализация, которая зажигает диод, когда температура
  становится выше нормы
*/

int sensorPin = 0;
int ledPin = 2;
float borderTemp = 30.0

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  float U2 = analogRead(sensorPin);
  U2 = U2/1023.0*5.0; //in volts
  float TT = 1.0/(1.0/298.15 + log(U2/(5.0-U2))/3950.0) - 273;
  Serial.print("TT="); Serial.println(TT);

  if (TT>borderTemp)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}
