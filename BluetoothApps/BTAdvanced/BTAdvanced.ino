#define SPin 18

char c;

void setup() {
  pinMode(SPin, INPUT);  
  Serial.begin(9600);
  Serial1.begin(38400);
  delay(500);
}

void loop() {

  while (Serial1.available())
  {
    Serial.write(Serial1.read());
  }
  while (Serial.available())
  {
    Serial1.write(Serial.read());  
  }
  
}
