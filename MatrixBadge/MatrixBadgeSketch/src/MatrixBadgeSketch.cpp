#include <Arduino.h>
#include "helpers.h"
/*
  Hackspace Matrix Badge
*/
const int bluePill = 11;
const int redPill = 12;

const int RedLED =  2;
const int BlueLED = 3;
const int matrixLED = 10;

Badge badge;
int choiceMade;

int redPillState = 0;
int bluePillState = 0;

void setup() {
  Serial.begin(9600);
  badge = readBadge();
  pinMode(matrixLED, OUTPUT);
  pinMode(RedLED,OUTPUT);
  pinMode(BlueLED,OUTPUT);

  pinMode(bluePill, INPUT);
  pinMode(redPill, INPUT);
}

void loop(){

  redPillState = digitalRead(redPill);
  bluePillState = digitalRead(bluePill);
  if (badge.Get_ChoiceMade()!=1){
    digitalWrite(RedLED,HIGH);
    digitalWrite(BlueLED,HIGH);
    digitalWrite(matrixLED,LOW);
    badge.Set_Choice(1);
  }else{
    digitalWrite(matrixLED,HIGH);
    digitalWrite(RedLED,LOW);
    digitalWrite(BlueLED,LOW);
  }
  /*if (badge.choiceMade==1){
    if ((redPillState == HIGH) || (bluePillState==HIGH)){

      digitalWrite(pillsLED, HIGH);
      digitalWrite(matrixLED,LOW);
    }else {
      digitalWrite(pillsLED, LOW);
      digitalWrite(matrixLED, HIGH);
    }
  }*/
}
