//Выводы шагового двигателя
#define OUTA 9
#define OUTB 8
#define OUTC 7
#define OUTD 6
//Количество шагов на оборот
#define halfStepsPerRound 360
#define holdLengthMicroseconds 100
boolean hold = false; // удерживать положение двигателя при помощи включения обмоток
short currentStep = 0; // Текущий шаг
short DelayB2Steps = 0; //Задержка между шагами

//Выводы двигателей
#define motor1 1
#define enA 10
#define in1 9
#define in2 8
#define motor2 2
#define enB 5
#define in3 7
#define in4 6
#define FWD 0
#define REV 1

void stop(int noOfMotor)
{
  analogWrite((noOfMotor == motor1) ? (enA) : (enB), 0);

}

void setDirection(int noOfMotor, int forward)
{
  digitalWrite((noOfMotor == motor1) ? (in1) : (in3), (forward == FWD));
  digitalWrite((noOfMotor == motor1) ? (in2) : (in4), (forward == REV));
}

void setSpeed(int noOfMotor, int speed)
{
  analogWrite((noOfMotor == motor1) ? (enA) : (enB), speed);
}

void setup() {

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  stop(motor1);
  stop(motor2);

  Serial.begin(9600);
}

void loop() {
  stop(motor1);
  stop(motor2);
  Serial.println("Stop");
  delay(500);
  setDirection(motor1, FWD);
  Serial.println("motor1 forward");
  for (int i = 0; i <= 511; i++)
  {
    if (i <= 255)
      setSpeed(motor1, i);
    else
      setSpeed(motor1, 511 - i);
    delay(100);
    if (i % 5 == 0) {
      Serial.print("motor1 speed:");
      if (i <= 255)
        Serial.println(i);
      else
        Serial.println(511 - i);

    }
  }

  stop(motor1);
  delay(500);
  setDirection(motor1, REV);
  Serial.println("motor1 backward");
  for (int i = 0; i <= 511; i++)
  {
    if (i <= 255)
      setSpeed(motor1, i);
    else
      setSpeed(motor1, 511 - i);
    delay(100);
    if (i % 5 == 0) {
      Serial.print("motor1 speed:");
      if (i <= 255)
        Serial.println(i);
      else
        Serial.println(511 - i);

    }
  }

  stop(motor1);
  delay(500);
  setDirection(motor2, FWD);
  Serial.println("motor2 forward");
  for (int i = 0; i <= 511; i++)
  {
    if (i <= 255)
      setSpeed(motor2, i);
    else
      setSpeed(motor2, 511 - i);
    delay(100);
    if (i % 5 == 0) {
      Serial.print("motor2 speed:");
      if (i <= 255)
        Serial.println(i);
      else
        Serial.println(511 - i);
    }
  }

  stop(motor2);
  delay(500);
  setDirection(motor2, REV);
  Serial.println("motor2 backward");
  for (int i = 0; i <= 511; i++)
  {
    if (i <= 255)
      setSpeed(motor2, i);
    else
      setSpeed(motor2, 511 - i);
    delay(100);
    if (i % 5 == 0) {
      Serial.print("motor2 speed:");
      if (i <= 255)
        Serial.println(i);
      else
        Serial.println(511 - i);
    }
  }
  stop(motor2);
  delay(500);
}

void initStepper()
{
  //Настраиваем выводы
  pinMode(OUTA, OUTPUT);
  pinMode(OUTB, OUTPUT);
  pinMode(OUTC, OUTPUT);
  pinMode(OUTD, OUTPUT);
  off();
}

void setStep(short step)
{
  switch (step % 8)
  {
    case 0:
      digitalWrite(OUTA, 1);
      digitalWrite(OUTB, 0);
      digitalWrite(OUTC, 0);
      digitalWrite(OUTD, 0);
      break;
    case 1:
      digitalWrite(OUTA, 1);
      digitalWrite(OUTB, 1);
      digitalWrite(OUTC, 0);
      digitalWrite(OUTD, 0);
      break;
    case 2:
      digitalWrite(OUTA, 0);
      digitalWrite(OUTB, 1);
      digitalWrite(OUTC, 0);
      digitalWrite(OUTD, 0);
      break;
    case 3:
      digitalWrite(OUTA, 0);
      digitalWrite(OUTB, 1);
      digitalWrite(OUTC, 1);
      digitalWrite(OUTD, 0);
      break;
    case 4:
      digitalWrite(OUTA, 0);
      digitalWrite(OUTB, 0);
      digitalWrite(OUTC, 1);
      digitalWrite(OUTD, 0);
      break;
    case 5:
      digitalWrite(OUTA, 0);
      digitalWrite(OUTB, 0);
      digitalWrite(OUTC, 1);
      digitalWrite(OUTD, 1);
      break;
    case 6:
      digitalWrite(OUTA, 0);
      digitalWrite(OUTB, 0);
      digitalWrite(OUTC, 0);
      digitalWrite(OUTD, 1);
      break;
    case 7:
      digitalWrite(OUTA, 1);
      digitalWrite(OUTB, 0);
      digitalWrite(OUTC, 0);
      digitalWrite(OUTD, 1);
      break;
  }
}

void off()
{
  //Выключаем все контакты
  digitalWrite(OUTA, 0);
  digitalWrite(OUTB, 0);
  digitalWrite(OUTC, 0);
  digitalWrite(OUTD, 0);
}

void go()
{
  setStep(currentStep);
  delayMicroseconds(holdLengthMicroseconds);
  if (DelayB2Steps > 0)
  {
    delay(DelayB2Steps);
  }
  if (!hold)
  {
    off();
  }


}
void fwdStep()
{
  currentStep = (2 + currentStep) % 8;
  go();
}

void rewStep()
{
  currentStep = (6 + currentStep) % 8;
  go();
}

void fwdHalfStep()
{
  currentStep = ( ++currentStep) % 8;
  go();
}

void rewHalfStep()
{
  currentStep = (7 + currentStep) % 8;
  go();
}

void stepUp(long steps, long halfSteps, boolean halfStepping)
{
  long hs = steps * 2 + halfSteps;
  while (abs(hs) > 0)
  {
    if ( hs > 0)
    {
      if (halfStepping)
      {
        fwdHalfStep();
      } else {
        fwdStep();
      }
    } else {

      if (halfStepping)
      {
        rewHalfStep();
      } else {
        rewStep();
      }
    }

  }

}

void setSpeed(int speed)
{
  DelayB2Steps = 255 - speed;
}

//Поворот на определенный угол
long getAngle(float angle)
{
  return (long) halfStepsPerRound * (angle / 360);
}


