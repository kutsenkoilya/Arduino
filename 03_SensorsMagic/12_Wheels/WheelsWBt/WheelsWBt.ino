#define SPin 18
int drivestate = 0;

void setup() {
  pinMode(SPin, INPUT);  
  
  // put your setup code here, to run once:
  pinMode (7, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (4, OUTPUT);

  Serial.begin(9600);
  Serial1.begin(9600);  
}

void loop() {

  while (Serial1.available())
  {
    int read = (int)Serial1.read() - 48;
    drivestate = read;
    Serial.println(read);
  }

  //1 2 3
  //4 5 6
  //7 8 9
  switch (drivestate)
  {
    case 1:
      RightWheel(true);
      break;
    case 2:
      Forward();
      break;
    case 3:
      LeftWheel(true);
      break;
    case 4:
      TurnLeft();
      break;
    case 5:
      Stop();
      break;
    case 6:
      TurnRight();
      break;
    case 8:
      Backward();
      break;
  }
}

void RightWheel(bool fwd)
{
  digitalWrite(7, fwd);
  digitalWrite(6, !fwd);
}

void LeftWheel(bool fwd)
{
  digitalWrite(5, fwd);
  digitalWrite(4, !fwd);
}

void Forward()
{
  RightWheel(true);
  LeftWheel(true);
}

void Backward()
{
  RightWheel(false);
  LeftWheel(false);
}

void Stop()
{  
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
}
  
void TurnLeft()
{
  RightWheel(false);
  LeftWheel(true);
}

void TurnRight()
{
  RightWheel(true);
  LeftWheel(false);
}



