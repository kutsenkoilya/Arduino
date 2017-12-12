/*
  Простой тест сервопривода - поворот на +10 градусов каждую секунду
*/

#include <Servo.h>

Servo servo;
int s =10;
int b =0;
void setup()
{
 servo.attach(10); //привязываем привод к порту 10
}

void loop()
{
  servo.write(b);
  if (b<=180)
  {
    b+=s;
  }
  else
  {
    b=0;
    }
  
  delay(1000); 
}

