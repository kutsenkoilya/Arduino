// SimpleTx - the master or the transmitter

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN 10

String inputString = "";         // a String to hold incoming data
boolean stringComplete = false;  // whether the string is complete

char rcvNew;
char rcvOld;

const byte slaveAddress[5] = {'R','x','A','A','A'};

RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 1000; // send once per second


void setup() {

    Serial.begin(9600);
    inputString.reserve(200);
   
    Serial.println("SimpleRxTx Starting");

    radio.begin();
    radio.setDataRate( RF24_250KBPS );
    radio.setRetries(3,5); // delay, count
    radio.openReadingPipe(1, slaveAddress);
    radio.startListening();    
}

//====================

void loop() {
    if ( radio.available() ) {
      radio.read( &rcvNew, sizeof(rcvNew) );
    }

    if (rcvNew != rcvOld)
    {
      Serial.print("Data received ");
      Serial.println(rcvNew);
    }
    rcvOld = rcvNew;
}

//====================

void send() {

    radio.stopListening();
    radio.openWritingPipe(slaveAddress);

    bool rslt;
    rslt = radio.write( &inputString, sizeof(inputString) );
        // Always use sizeof() as it gives the size as the number of bytes.
        // For example if dataToSend was an int sizeof() would correctly return 2

    if (rslt) {
        Serial.print("Data Sent ");
        Serial.print(inputString);
        Serial.println("  Acknowledge received");
    }
    
    radio.startListening();
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString = inChar;
    send();

  }
}


