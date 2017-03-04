/*
 * Proof of concept 
 * Add mini menu changing settings 
 * and store them into EEPROM
 */

#include "setup.h"

const int ledPin =  LED_BUILTIN;
const long interval = 1000;


// Max lenght of array is define in setup.h 
// use somewhere between 32..63 depending on memory need
char SSID_ESP[LINE_LENGTH];
char SSID_KEY[LINE_LENGTH];

int ledState = LOW;
unsigned long previousMillis = 0;

Setup stp;

void setup() {
  Serial.begin(9600);
  stp.begin(SSID_ESP,SSID_KEY);
}

void loop() {
  unsigned long currentMillis = millis();

  if (stp.getSerialChar()=='M') {
    stp.menu();
  }
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
  }
  
}



