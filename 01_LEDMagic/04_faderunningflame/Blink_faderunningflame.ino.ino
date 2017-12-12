/*
  Fade Running Flame
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
 
  int totalwait = 1;

  for (int i=4;i<14;i++)
  {
    tripleignite(i-1,i,i+1,totalwait);
  }

  for (int i=14;i>3;i--)
  {
    tripleignite(i+1,i,i-1,totalwait);
  }
  
}

void blink(int portnum, int delayt)
{
  digitalWrite(portnum, HIGH);
  delay(delayt);
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
    analogWrite(fadingport,i);
    analogWrite(shiningport,255-i);
    delay(delayt);  
  }     
}

void tripleignite(int leftport, int middleport, int rightport, int delayt)
{
  for (int i=0; i<255; i++)
  {
    analogWrite(leftport,255-i);
    analogWrite(middleport,i);
    analogWrite(rightport,255-i);
    delay(delayt);  
  }
    
}






