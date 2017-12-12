
#define pin1 1
#define pin2 2
#define pin3 3
#define pin4 4
#define delaytime 1


void setup() {
  // put your setup code here, to run once:
  pinMode(pin1,OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int numberOfSteps = 48;
  step_OFF();
  while(numberOfSteps>0){
    forward();
    numberOfSteps--;
  }
delay(2000);
step_OFF();
numberOfSteps = 48;
while(numberOfSteps>0)
{
  backward();
  numberOfSteps --;
  }
delay(2000);

}


//these functions set the pin settings for each of the four steps per rotation of the motor (keepp in mind that the motor in the kit is geared down,
//i.e. there are many steps necessary per rotation

void Step_A(){
  digitalWrite(pin1, HIGH);//turn on coil 1 
  digitalWrite(pin2, LOW); 
  digitalWrite(pin3, LOW); 
  digitalWrite(pin4, LOW); 
}
void Step_B(){
  digitalWrite(pin1, LOW); 
  digitalWrite(pin2, HIGH);//turn on coil 2
  digitalWrite(pin3, LOW); 
  digitalWrite(pin4, LOW); 
}
void Step_C(){
  digitalWrite(pin1, LOW); 
  digitalWrite(pin2, LOW); 
  digitalWrite(pin3, HIGH); //turn on coil 3
  digitalWrite(pin4, LOW); 
}
void Step_D(){
  digitalWrite(pin1, LOW); 
  digitalWrite(pin2, LOW); 
  digitalWrite(pin3, LOW); 
  digitalWrite(pin4, HIGH); //turn on coil 4
}
void step_OFF(){
  digitalWrite(pin1, LOW); //power all coils down
  digitalWrite(pin2, LOW); 
  digitalWrite(pin3, LOW); 
  digitalWrite(pin4, LOW); 
}

//these functions run the above configurations in forward and reverse order
//the direction of a stepper motor depends on the order in which the coils are turned on.
void forward(){//one tooth forward
  Step_A();
  delay(delaytime);
  Step_B();
  delay(delaytime);
  Step_C();
  delay(delaytime);
  Step_D();
  delay(delaytime);
}

void backward(){//one tooth backward
  Step_D();
  delay(delaytime);
  Step_C();
  delay(delaytime);
  Step_B();
  delay(delaytime);
  Step_A();
  delay(delaytime);
}



