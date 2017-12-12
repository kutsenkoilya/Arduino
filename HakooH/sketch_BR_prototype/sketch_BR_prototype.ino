#include <math.h> 

//temperature Pins
int temppin_LM35 = 0; //LM35 pin 
float temp_LM35; 

//Bluetooth Pins
int bt_input_val;
int bt_test_LED = 13;

//Servo Pins
const int ENA = 10;
const int IN1 = 9;
const int IN2 = 8;
const int ENB = 5;
const int IN4 = 7;
const int IN3 = 6;

//GearconPINS
const int gear1_pin = 11;
const int gear2_pin = 12;

void setup()
{
  //bt setup
  Serial.begin(9600);
  pinMode(bt_test_LED, OUTPUT);
  digitalWrite(bt_test_LED, HIGH);
  //servo setup
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  //gearcon setup
  pinMode(gear1_pin, INPUT);
  digitalWrite(gear1_pin,HIGH);
  pinMode(gear2_pin, INPUT);
  digitalWrite(gear2_pin,HIGH);
}

void loop()
{
  BtRead();
  TempReadAndSend();
  GearconReadAndSend();
  //delay(5000);
}

void BtRead()
{
  if (Serial.available())
  {
    bt_input_val = Serial.read();
    // При символе "1" включаем светодиод
    if (bt_input_val == 'q')
    {
      digitalWrite(bt_test_LED, HIGH);
    }
    if (bt_input_val=='w')
    // При символе "0" выключаем светодиод
    {
      digitalWrite(bt_test_LED, LOW);
    }
    if (bt_input_val=='u')
    {
      forward(360,20); //вверх
      }
    if (bt_input_val == 'd')
    {
      reverse(360,20); //вниз
      }
  }  
}

void TempReadAndSend()
{
  temp_LM35 = analogRead(temppin_LM35); 
  temp_LM35 = temp_LM35*0.48828125;
  if (Serial.available())
  {
    Serial.print("LM35_T="); 
    Serial.print(temp_LM35); 
    Serial.println(" C");
  }  
}

void GearconReadAndSend()
{
  int gear1 = digitalRead(gear1_pin);
  int gear2 = digitalRead(gear2_pin);
  if (gear1 == 1)
  {
    Serial.println("Cap is too high");
    }
  if (gear2 == 1)
  {
    Serial.println("Cap is to low");
    }
  Serial.print("g1=");
  Serial.print(gear1);
  Serial.print(";g2=");
  Serial.println(gear2);
}


void reverse(int i, int j) {

  // set both motors ON
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  while (1)   {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
    delay(j);
    i--;
    if (i < 1) break; 

    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
    delay(j);  
    i--;
    if (i < 1) break;

    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
    delay(j);
    i--;
    if (i < 1) break;

    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
    delay(j);  
    i--;
    if (i < 1) break;
  }

  // set both motors OFF
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  
}  // end reverse()

void forward(int i, int j) {

  // Set both motors ON
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  while (1)   {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
    delay(j);  
    i--;
    if (i < 1) break;

    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
    delay(j);
    i--;
    if (i < 1) break;

    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
    delay(j);  
    i--;
    if (i < 1) break;

    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
    delay(j);
    i--;
    if (i < 1) break;
  }

  // set both motors OFF
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);

}  // end forward()

