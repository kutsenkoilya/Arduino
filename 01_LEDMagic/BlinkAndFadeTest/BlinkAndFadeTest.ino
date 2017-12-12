
void setup() {
  pinMode(0, OUTPUT);
  
}

void loop() {
  
  int totalwait = 10;

  shineup(0,totalwait);
  fade(0,totalwait);
  delay(100);
  /*
  

  for (int i=5;i<14;i++)
  {
    shineup(i,totalwait);
  }

  delay(1000);

  for (int i=13;i>4;i--)
  {
    fade(i,totalwait);
  }

  
  
  */

}


void blink(int portnum, int delayt)
{
  digitalWrite(portnum, HIGH);
  delay(delayt);                       // wait for a second
  digitalWrite(portnum, LOW);
}

void shineup(int portnum, int delayt)
{
  for (int i=0; i<255; i++)
  {
    analogWrite(portnum,i);
    delay(delayt);  
  }
}

void fade(int portnum, int delayt)
{
  for (int i=255; i>1; i--)
  {
    analogWrite(portnum,i);
    delay(delayt);  
  }  
  
  
  }




