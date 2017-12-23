#include <math.h> 

void setup() { 
   Serial.begin(9600); 
} 
void loop() { 
  
  float temp_LM35 = analogRead(5)*0.48828125; 

  Serial.print(temp_LM35);
  Serial.print(";");
 
  Serial.println(); 
  delay(1000); 
} 




