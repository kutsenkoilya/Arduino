// set pin numbers:
const int a1 =  4;     
const int a2 =  3;
const int b1 =  2;
const int b2 =  1;
float delay_t = 1 ;

void setup() {
  // initialize pins
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
 
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(b2, LOW);
     
}


void loop(){

  step1();
  delay(delay_t);
  step2();
  delay(delay_t);
  step3();
  delay(delay_t);
  step4();
  delay(delay_t);
 
}

void step1 (){

  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(b2, LOW);

}

void step2 (){

  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);

}

void step3 (){

  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  digitalWrite(b1, LOW);
  digitalWrite(b2, LOW);

}

void step4 (){

  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(b2, HIGH);

}
