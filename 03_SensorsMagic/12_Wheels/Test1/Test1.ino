const int trigPin = 12;
const int echoPin = 13;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode (7, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (4, OUTPUT);

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  float dist = measureDistance();
  
  if (dist<10)
  {
    Serial.print(dist); Serial.println(";turn");
    //turn
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  }
  else
  {
    Serial.print(dist); Serial.println(";forward");
    //go forward
    digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);

    }
  
}

float measureDistance()
{
  float duration;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  return duration / 29 / 2;
}
