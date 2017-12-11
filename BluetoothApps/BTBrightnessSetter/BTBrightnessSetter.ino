// Ардуина ловит через блютус значение от 0 до 255 и выставляет его в качестве
//  яркости LED диода

#define SPin 18
#define LPin 2

char a[3];
int oldVal;
int newVal;

void setup() {
  pinMode(SPin, INPUT);  
  pinMode(LPin, OUTPUT);  
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {

  int i = 0;
  while (Serial1.available())
  { 
    int read = (int)Serial1.read();
    if (read!=255 && read !=10&& read !=0&& read !=13)
    {
      if (i==3)
      {
        break;
      }
      a[i] = (char)read;
      i++;
    }
  }

  int brt = (int(a[0]) - 48)*100 + ((int)(a[1])-48)*10 + ((int)(a[2])-48);
  Serial.println(brt);
  analogWrite(LPin,brt);
}
