// SimpleTx - the master or the transmitter

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN 10

#define PotenPin A0

const byte slaveAddress[5] = {'R','x','A','A','A'};

bool newData = false;

RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

int sendNewVal;
int sendOldVal;
int rcvdVal;
char txNum = '0';

unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 1000; // send once per second


void setup() {

    Serial.begin(9600);

    Serial.println("SimpleRxTx Starting");

    radio.begin();
    radio.setDataRate( RF24_250KBPS );
    radio.setRetries(3,5); // delay, count
    radio.openReadingPipe(1, slaveAddress);
    radio.startListening();    
    pinMode(PotenPin, INPUT);

}

//====================

void loop() {
    sendNewVal = analogRead(PotenPin);
    
    getData();
    showData();

    if (sendOldVal != sendNewVal)
    {
      send();
      
      }

    sendOldVal = sendNewVal;
}

void getData() {
  if ( radio.available() ) {
    radio.read( &rcvdVal, sizeof(rcvdVal) );
    newData = true;
   }
}

void showData() {
  if (newData == true) {
    Serial.print("Data received ");
    Serial.println(rcvdVal);
    newData = false;
   }
}

//====================

void send() {

    radio.stopListening();
    radio.openWritingPipe(slaveAddress);

    bool rslt;
    rslt = radio.write( &sendNewVal, sizeof(sendNewVal) );
        // Always use sizeof() as it gives the size as the number of bytes.
        // For example if dataToSend was an int sizeof() would correctly return 2

    if (rslt) {
        Serial.print("Data Sent ");
        Serial.print(sendNewVal);
        Serial.println("  Acknowledge received");
    }
    
    radio.startListening();
}


