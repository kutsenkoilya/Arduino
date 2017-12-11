const int trigPin = 2;
const int echoPin = 3;

int arraysize = 5;
float a[5] = {0.,0.,0.,0.,0.};

float oldavg;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  oldavg = 0;
}

void loop()
{
  float cm = measureDistance();

  //Статистическая рутина
  for (int i=0; i<arraysize-1;i++)
  {
    a[i] = a[i+1];
  }
  a[arraysize-1]=cm;

  //сумма последних измерений
  float sum = 0;
  for (int i =0; i<arraysize;i++)
  {
    sum+=a[i]; 
  }

  //среднее, чтобы много не флудить
  float avg = sum/arraysize;

  if (oldavg != avg)
  {
    oldavg = avg;
    Serial.print("avg dist="); Serial.println(avg);
  }

  delay(100);
}

//Магическая кастомная функция отправки сигнала,
//его приёма и измерения расстояния в сантиметрах
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



