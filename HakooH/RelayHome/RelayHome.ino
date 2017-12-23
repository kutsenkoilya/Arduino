// Тестирование домашнего реле
int Relay = 9;
int BTNPin = 8;
int LedOne = 10;
int LedTwo = 11;

bool oldState = false;
bool turnedOn = false;

void setup() 
{
  pinMode(LedOne, OUTPUT);
  pinMode(LedTwo, OUTPUT);
                  
  pinMode(Relay, OUTPUT);  
  pinMode(BTNPin, INPUT);
  Serial.begin(9600);   

  digitalWrite(LedOne,HIGH);  
  digitalWrite(LedTwo,HIGH);  
}

void loop() 
{

  
  bool curRead = digitalRead(BTNPin);
  if (curRead > oldState) 
  {
      turnedOn = !turnedOn;
      
      digitalWrite(Relay,turnedOn);
      Serial.println(turnedOn);
  }

  oldState = curRead;
  delay(100);
}

