/*
  Fade Running Dot
*/

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {

  int totalwait = 2;

  for (int i=4;i<14;i++)
  {
    ignite(i,i+1,totalwait);
  }

  delay(1000);

  for (int i=13;i>3;i--)
  {
    ignite(i,i-1,totalwait);
  }

  delay(1000);
  
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

void ignite(int fadingport, int shiningport, int delayt)
{
  for (int i=255; i>1; i--)
  {
    analogWrite(fadingport,255-i);
    analogWrite(shiningport,i);
    delay(delayt);  
  }     
}





