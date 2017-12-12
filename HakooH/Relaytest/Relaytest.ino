// Реле модуль подключен к цифровому выводу 4
int Relay = 2;
const int BTNPin = 3;
bool oldState = false;
bool turnedOn = false;


void setup() 
{                
  pinMode(Relay, OUTPUT);  
  pinMode(BTNPin, INPUT);
  Serial.begin(9600);   
}

void loop() 
{
  bool curRead = digitalRead(BTNPin);
  
  //предыдущая версия if: oldState != curRead && curRead
  //на самом деле, если if такой (curRead == true and curRead!=oldState)
  //это значит: 1. curRean == true and oldState == false => (curRead && !oldState)
  //или       : 2. curRead > oldState
  //дополнительно, если curRead < oldState,
  // то срабатывать будет на "выключение" - переход из 1 в 0 
  if (curRead > oldState) 
  {
      turnedOn = !turnedOn;
      /*
      int val = 0;
      if (turnedOn)
      {val = 128;
        }
      
      analogWrite(Relay, val);
      */
      digitalWrite(Relay,turnedOn);
      Serial.println(turnedOn);
  }

  oldState = curRead;
  delay(100);
}
