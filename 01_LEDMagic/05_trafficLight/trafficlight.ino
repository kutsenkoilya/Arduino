
//Traffic light
//Pin 4 - Red LED
//Pin 5 - Yellow LED 
//Pin 6 - Green LED

//Work sequence
//1. Red(4)     works for 5 sec
//2. Green(6)   works for 3 sec
//3. Green(6)   blinking 3 times
//4. Yellow (5) works for 1 sec

void setup() {
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {

  blink(4,5000);
  blink(6,3000);
  delay(200);
  blink(6,1000);
  delay(200);
  blink(6,1000);
  delay(200);
  blink(6,1000);
  blink(5,1000);

}

void blink(int portnum, int delayt)
{
  digitalWrite(portnum, HIGH);
  delay(delayt);
  digitalWrite(portnum, LOW);
}




