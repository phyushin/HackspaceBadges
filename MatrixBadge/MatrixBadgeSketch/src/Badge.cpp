#include "Badge.h"
#include <EEPROM.h>

Badge::Badge(){
  m_mindFree=false;
  m_choiceMade=false;
  m_id='a';
  m_choice=1;
}

Badge::Badge(char p_ID, bool p_choiceMade, bool p_mindFree, int p_choice){}

void Badge::Set_ChoiceMade(bool p_choiceMade){
  this->m_choiceMade = p_choiceMade;
}

void Badge::Set_MindFree(bool p_mindFree){
this->m_mindFree = p_mindFree;
}

void Badge::Set_ID(char p_id){
  this->m_id = p_id;
}

void Badge::Set_Choice(int p_choice){
  this->m_choice = p_choice;
}

void Badge::Set_FreeMind(int p_index,char val){
    this->m_freeMinds[p_index]=val;
}

bool Badge::Get_ChoiceMade(){
  return this->m_choiceMade;
}

bool Badge::Get_MindFree(){
  return this->m_mindFree;
}

char Badge::Get_ID(){
  return this->m_id;
}

int Badge::Get_Choice(){
  return this->m_choice;
}

char Badge::Get_FreeMind(int index){
  return this->m_freeMinds[index];
}

void Badge::InitBadge(){
  this->Set_ID(EEPROM.read(idPos));
  this->Set_MindFree(EEPROM.read(mindfreePos));
  this->Set_ChoiceMade(EEPROM.read(choiceMadePos));
  this->Set_Choice(EEPROM.read(choicePos));
  for (int i = 0;i<30;i++){
    this->Set_FreeMind(i,EEPROM.read(freeMindsBasePos+i));
  }
}
  void Badge::SaveBadge(){
    EEPROM.write(this->Get_ID(),idPos);
    EEPROM.write(this->Get_MindFree(),mindfreePos);
    EEPROM.write(this->Get_ChoiceMade(),choiceMadePos);
    EEPROM.write(this->Get_Choice(),choicePos);
    for (int i = 0;i<30;i++){
      EEPROM.write(this->Get_FreeMind(i),freeMindsBasePos+i);
    }
  }
