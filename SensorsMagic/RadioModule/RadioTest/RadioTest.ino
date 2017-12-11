//nRF24L01+
//передать значние с потенциометра
//с одного ардуино на другое

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

void setup() {
  RF24 radio(CE, CSN);
}

void loop() {
  //приемопередатчик
  radio.begin();
  radio.setChannel(n);
  radio.setDataRate(RF24_1MBPS);
  radio.setPALevel(RF24_RA_HIGH);

  //открытие трубы на запись
  radio.openWritingPipe(0x1234567890LL);

  //труба на чтение
  radio.openReadingPipe(0x1234567890LL);
  
  //включение/отключение прослушки
  radio.startListening();
  radio.stopListening();

  //письмо
  radio.write(&data,size);
  availbytes = radio.available();
  radio.read(&data,size);


  
}






