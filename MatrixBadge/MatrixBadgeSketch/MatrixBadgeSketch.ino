/*
Matrix Hackspace Badge
*/
#include <EEPROM.h>

const int redPill = 8; //redPill
const int bluePill = 9; //bluePil


const int redLED = 12;     // the number of the pushbutton pin
const int blueLED =  11;      // the number of the LED pin
const int matrixLED = 10;

const int IRLED =3;
const int IRTran = 2;

boolean isMindFree;
boolean isEEPROMSet;

int topOfArray;
char freeMinds[30];

//EEPROM STORAGE
const int mindFree = 0;
const int badgeNumber = 1;
const int arrayTop = 2;
const int freeMinds =3;

void message()
{

  if (isMindFree) {
    Serial.print("There is no spoon!\n");
  }else{
    Serial.print("Wake up!\nThe Matrix has you!\n");
  }
}

void readEEPROM(){
  isMindFree = EEPROM.read(mindFree);
  arrayTop = EEPROM.read();
  freeMinds = readFreeMinds(arrayTop);
}

void setup() {
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(blueLED,OUTPUT);
  pinMode(matrixLED,OUTPUT);
  pinMode(IRLED,OUTPUT);
  
  pinMode(redPill, INPUT);     
  pinMode(bluePill, INPUT);
  pinMode(IRTran,INPUT);
  
  isEEPROMSet = false;
  
}

void insertIntoFreeMinds(char mind)
{
  for (int i=0;i<30;i++;){
    
  }
}

char[] readFreeMinds(){
  
}

void loop(){
 // digitalWrite(IRLED,HIGH);
  
  if((digitalRead(redPill)==HIGH) && (isEEPROMSet ==false)){
    EEPROM.write(mindFree,1);
    isMindFree = true;
    isEEPROMSet = true;
  }
  if(digitalRead(IRTran)==HIGH){
    digitalWrite(redLED,HIGH);
  }else  {
    digitalWrite(redLED,LOW);
  }
  
  if (isMindFree){
    digitalWrite(matrixLED,HIGH);
  }else{
    digitalWrite(blueLED,HIGH);
  }
  
}
