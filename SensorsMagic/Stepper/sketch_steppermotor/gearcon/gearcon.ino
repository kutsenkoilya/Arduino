const int switchPin = 2;

void setup() {
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin,HIGH);
  Serial.begin(9600);

}

void loop() {
  int g = digitalRead(switchPin);
  Serial.println(g);
  delay(20);

}
