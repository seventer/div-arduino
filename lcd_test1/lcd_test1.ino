/*
 Proof of concept LCD + some I/O + interrupt
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

const float VOLTAGE = 4.8;
const int LM337_PIN = 6;

int val = 0; 
float temp=0;

int intCounter=0;

const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;



void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("Starting.....");
  Serial.begin(9600);  
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), intWorker, CHANGE);
}

void loop() {
  digitalWrite(ledPin, state);
  lcd.clear();  
  val = analogRead(LM337_PIN);
  lcd.print("RAW: ");
  lcd.print(val);
  lcd.setCursor(0, 1);
//  temp = (VOLTAGE * val) / 1024.0 * 100.0 - 273.15;
//  lcd.print("Temp: ");
//  lcd.print(temp);
  lcd.print("intCnt: ");
  lcd.print(intCounter);
  Serial.println(val);
  delay(1000); 
}

void intWorker() {
  intCounter++;
  state = !state;
}

