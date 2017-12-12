
// the setup function runs once when you press reset or power the board
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

// the loop function runs over and over again forever
void loop() {

  int delayt=5;
  
  for (int i=0; i<255; i++)
  {
    for (int j=4;j<14;j++)
    {
      if (j%2==0)
      {
        analogWrite(j,i);
      }
    }
    delay(delayt);  
  }

    for (int j=4;j<14;j++)
    {
    analogWrite(j,0);
    }
  
  for (int i=0; i<255; i++)
  {
    for (int j=4;j<14;j++)
    {
      if (j%2!=0)
      {
        analogWrite(j,i);
      }
    }
    delay(delayt);  
  }
  
    for (int j=4;j<14;j++)
    {
    analogWrite(j,0);
    }
}


