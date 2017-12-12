// connect motor controller pins to Arduino digital pins
// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

//second stepper motor
int mini_delay = 20;
//int big_delay = 1000;

int v_big_delay = 100;
int v_speed = 200;

//temp sensor code
int B=3975;  
int pinTemp = 0;
float resistance = 0;
float temperature = 0;
float val = 0;


void setup()
{
  Serial.begin(115200);  
  Serial.println("Getting ready"); 
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  analogWrite(enA, v_speed);
  analogWrite(enB, v_speed);
}
void demoOne()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, HIGH); //HIGH
  digitalWrite(in2, LOW);  //LOW
  // set speed to 200 out of possible range 0~255
  //analogWrite(enA, v_speed);
  // turn on motor B 
  digitalWrite(in3, HIGH); //HIGH
  digitalWrite(in4, LOW); //LOW
  // set speed to 200 out of possible range 0~255
  //analogWrite(enB, v_speed);
  delay(v_big_delay);
  // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  delay(v_big_delay);
  // now turn off motors
  //digitalWrite(in1, LOW);
  //digitalWrite(in2, LOW);  
  //digitalWrite(in3, LOW);
  //digitalWrite(in4, LOW);
}
void demoTwo()
{
  // this function will run the motors across the range of possible speeds
  // note that maximum speed is determined by the motor itself and the operating voltage
  // the PWM values sent by analogWrite() are fractions of the maximum speed possible 
  // by your hardware
  // turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  // accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(mini_delay);
  } 
  // decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(mini_delay);
  } 
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
}
void loop()
{
  demoThree_half();

 // complicatedTemp();
  //delay(big_delay);
  //demoTwo();
  //delay(big_delay);
}

void complicatedTemp() {

  val = analogRead(pinTemp);                               // get analog value 
  temperature = val*0.48828125;
  Serial.print("T=");
  Serial.print(temperature);
  Serial.println(" C"); 
}

void demoThree_full()
{
  setStep(0);
  delay(v_big_delay);
  setStep(1);
  delay(v_big_delay);
  setStep(2);
  delay(v_big_delay);
  setStep(3);
  delay(v_big_delay);
  setStep(4);
  delay(v_big_delay);
  setStep(5);
  delay(v_big_delay);
  setStep(6);
  delay(v_big_delay);
  setStep(7);
  delay(v_big_delay);
}

void demoThree_half()
{
  setStep(7);
  delay(v_big_delay);
  setStep(1);
  delay(v_big_delay);
  setStep(3);
  delay(v_big_delay);
  setStep(5);
  delay(v_big_delay);
}


void setStep(short step)
{
  switch (step % 8)
  {
    case 0:
      digitalWrite(in1, 1);
      digitalWrite(in2, 0);
      digitalWrite(in3, 0);
      digitalWrite(in4, 0);
      break;
    case 1:
      digitalWrite(in1, 1);
      digitalWrite(in2, 1);
      digitalWrite(in3, 0);
      digitalWrite(in4, 0);
      break;
    case 2:
      digitalWrite(in1, 0);
      digitalWrite(in2, 1);
      digitalWrite(in3, 0);
      digitalWrite(in4, 0);
      break;
    case 3:
      digitalWrite(in1, 0);
      digitalWrite(in2, 1);
      digitalWrite(in3, 1);
      digitalWrite(in4, 0);
      break;
    case 4:
      digitalWrite(in1, 0);
      digitalWrite(in2, 0);
      digitalWrite(in3, 1);
      digitalWrite(in4, 0);
      break;
    case 5:
      digitalWrite(in1, 0);
      digitalWrite(in2, 0);
      digitalWrite(in3, 1);
      digitalWrite(in4, 1);
      break;
    case 6:
      digitalWrite(in1, 0);
      digitalWrite(in2, 0);
      digitalWrite(in3, 0);
      digitalWrite(in4, 1);
      break;
    case 7:
      digitalWrite(in1, 1);
      digitalWrite(in2, 0);
      digitalWrite(in3, 0);
      digitalWrite(in4, 1);
      break;
  }
}
