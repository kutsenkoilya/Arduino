int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider
int LEDpin = 1;          // connect Red LED to pin 11 (PWM pin)
int LEDbrightness;        // 
void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);   
}
 
void loop(void) {

  for (int i=0; i<255;i++)
  {
      Serial.println(i);
     analogWrite(1, i);
     delay(50);
  }
  


  /*
  photocellReading = analogRead(photocellPin);  
 
  // LED gets brighter the darker it is at the sensor
  // that means we have to -invert- the reading from 0-1023 back to 1023-0
  int reversedPhotocellReading = 1023 - photocellReading;
  //now we have to map 0-1023 to 0-255 since thats the range analogWrite uses
  LEDbrightness = map(reversedPhotocellReading, 0, 1023, 0, 255);
  analogWrite(LEDpin, LEDbrightness);

  Serial.print("Analog reading = ");
  Serial.print(photocellReading);     // the raw analog reading
  Serial.print(";LED Brightness = ");
  Serial.println(LEDbrightness);
  delay(100);*/
}
