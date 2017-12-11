#include <math.h> 

int temppin_LM35 = 0; //LM35 pin 
int temppin_KTY81 = 1;
float temp_LM35; 

int B=3975;                  //B value of the thermistor 
void setup() { 
   Serial.begin(115200); 
} 
void loop() { 
  temp_LM35 = analogRead(temppin_LM35); 
 float val = temp_LM35;
  temp_LM35 = temp_LM35*0.48828125; 

  float resistance=(float)(1023-val)*10000/val;                      // get resistance 
  float temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;     // calc temperature in celsius 

  
 float read_temp = kty(1);
 
 
  //temp_LM358 = (float)(1023-temp_LM358)*10000/temp_LM358; //get the resistance of the sensor; 
  //temp_LM358=1/(log(temp_LM358/10000)/B+1/298.15)-273.15; //convert to temperature via datasheet&nbsp; 
  Serial.print("LM35_T="); 
  Serial.print(temp_LM35); 
  Serial.println(" C"); 
  Serial.print("KTY1_T="); 
  Serial.print(read_temp); 
  Serial.println(" C"); 
  delay(1000); 
} 


float kty(unsigned int port) {
         float temp              = 82;
         ADCSRA = 0x00;
         ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
         ADMUX = 0x00;
         ADMUX = (1<<REFS0);
         ADMUX |= port;   

         for (int i=0;i<=64;i++)
         {
                 ADCSRA|=(1<<ADSC);
                 while (ADCSRA & (1<<ADSC));
                 temp += (ADCL + ADCH*256);
         }

         temp /= 101;
         temp -= 156;
       return (temp);
 }


