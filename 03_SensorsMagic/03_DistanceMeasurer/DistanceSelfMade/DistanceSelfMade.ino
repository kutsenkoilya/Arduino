const int trigPin = 2;
const int echoPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //ждём волны
  while (!digitalRead(echoPin))
  {
    delayMicroseconds(1);
  }

  //мереем волну
  int count = 0;
  while (digitalRead(echoPin))
  {
    count++;
    delayMicroseconds(1);
  }
  
  //подобрать коэффициенты...
  Serial.print("count="); Serial.println(count/10);
  delay(100);
}




