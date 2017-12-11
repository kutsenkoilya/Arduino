/////////////////////////////
//MIT App Inventor
//http://ai2.appinventor.mit.edu/?locale=en#4559427044376576
//////////////////////////////
#define SPin 0
#define LPin 2

char c;

void setup() {
  pinMode(SPin, INPUT);  
  pinMode(LPin, OUTPUT);  
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial1.available())
  {
    c = Serial1.read();
    delay(3);
    }

  Serial.println(c);
  switch(c)
  {
    case '+': digitalWrite(LPin,HIGH);
      break;
    case '-': digitalWrite(LPin, LOW);
      break;
    }
  
}
