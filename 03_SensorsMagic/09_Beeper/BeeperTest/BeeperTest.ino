int tn = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
}

void loop() {
  tn = tn+10;
  
  tone(4,tn);
  delay(100);
  noTone(4);
  delay(100);

  if (tn>520)
  {
    tn = 0;
  }
}
