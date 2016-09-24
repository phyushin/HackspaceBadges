#include <Arduino.h>
#include "helpers.h"
/*
  Hackspace Matrix Badge
*/
const int bluePill = 11;
const int redPill = 12;

const int pillsLED =  2;
const int matrixLED = 10;

badge_struct badgeData;
int choiceMade;
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  badgeData = readStruct();
  pinMode(matrixLED, OUTPUT);
  pinMode(pillsLED,OUTPUT);
  pinMode(bluePill, INPUT);
  pinMode(redPill, INPUT);
}

void loop(){

  buttonState = digitalRead(redPill);


  if (buttonState == HIGH){
    digitalWrite(pillsLED, HIGH);
    digitalWrite(matrixLED,LOW);
  }
  else {
    digitalWrite(pillsLED, LOW);
    digitalWrite(matrixLED, HIGH);
  }
}
