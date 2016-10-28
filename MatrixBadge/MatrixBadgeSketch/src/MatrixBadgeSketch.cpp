#include "Badge.h"
#include "helpers.h"
#include <Arduino.h>

/*
  Hackspace Matrix Badge
*/
#define LED_OFF LOW
#define LED_ON HIGH

#define BTN_PRESSED HIGH
#define BTN_RELEASED LOW

const int bluePill = 11;
const int redPill = 12;

const int RedLED = 2;
const int BlueLED = 3;
const int MatrixLED = 10;

Badge badge;

void setup() {
  // Initialize the serial port
  Serial.begin(9600);

  // Read the info from the EEPROM - if it hasn't been written yet,
  // then save the defaults
  if (!badge.ReadFromEeprom()) {
    Serial.println("SETUP: Badge not initialized - Saving EEPROM");
    badge.SaveToEeprom();
  } else {
    Serial.println("SETUP: Badge initialized from EEPROM");
  }

  // Initialize all the outputs before setting them up as outputs
  digitalWrite(MatrixLED, LED_OFF);
  pinMode(MatrixLED, OUTPUT);
  digitalWrite(RedLED, LED_OFF);
  pinMode(RedLED, OUTPUT);
  digitalWrite(BlueLED, LED_OFF);
  pinMode(BlueLED, OUTPUT);

  // Initialize the inputs
  pinMode(bluePill, INPUT);
  pinMode(redPill, INPUT);

  // Turn on the Red and Blue LEDs
  digitalWrite(RedLED, LED_ON);
  digitalWrite(BlueLED, LED_ON);
}

void loop() {
  bool changed = false;

  // Read the inputs
  int redPillState = digitalRead(redPill);
  int bluePillState = digitalRead(bluePill);

  // Skip the case where both buttons are pressed or none are pressed
  if (redPillState != bluePillState) {
    if (redPillState == BTN_PRESSED) {
      badge.Set_PillChoice(CHOICE_RED);
      Serial.println("LOOP: Choice made: RED");
      changed = true;
    } else if (bluePillState == BTN_PRESSED) {
      badge.Set_PillChoice(CHOICE_BLUE);
      Serial.println("LOOP: Choice made: BLUE");
      changed = true;
    }
  }

  // If our state has been changed, then save to EEPROM and turn off the Blue
  // and Red LEDs and turn on the Green one
  if (changed) {
    Serial.println("LOOP: Changes made - updating EEPROM");
    badge.SaveToEeprom();

    digitalWrite(RedLED, LED_OFF);
    digitalWrite(BlueLED, LED_OFF);
    digitalWrite(MatrixLED, LED_ON);

  }
}
