/*
  Read temperature 4 times, then calc average
 */
int sensorPin = 0;
int arraysize = 5; //отдельная переменная для длины массива, 
                   //так как .length() и sizeof() выдают ерунду 
float a[5] = {0.,0.,0.,0.,0.};

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  //напряжение
  float U2 = analogRead(sensorPin);
  U2 = U2/1023.0*5.0; //вольты
  Serial.print("U2="); Serial.println(U2);
  
  float TT = 1.0/(1.0/298.15 + log(U2/(5.0-U2))/3950.0) - 273;//град цельсия
  Serial.print("TT="); Serial.println(TT);

  //очередь в котором хранятся последние 5 измерений
  for (int i=0; i<arraysize-1;i++)
  {
    a[i] = a[i+1];
  }
  a[arraysize-1]=TT;

  //сумма последних пяти измерений
  float sum = 0;
  for (int i =0; i<arraysize;i++)
  {
    sum+=a[i]; 
  }

  //среднее
  float avg = sum/arraysize;
  Serial.print("avg="); Serial.println(avg);

  //сумма квадратов
  float sqrsum = 0;
  for (int i =0; i<arraysize;i++)
  {
    sqrsum+=pow(avg-a[i],2); 
  }
  
  //дисперсия
  float disp = sqrsum/(float)arraysize;
  Serial.print("disp="); Serial.println(disp);

  //среднеквадр отклонение
  float s = sqrt(disp);
  Serial.print("s="); Serial.println(s);

  delay(1000);
}
