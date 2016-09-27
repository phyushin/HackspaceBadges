#include <Arduino.h>
#include <EEPROM.h>
#include "Badge.cpp"
Badge readBadge(){
Badge return_badge = new Badge();
/*
  badge.Set_ID('a');
  badge.Set_MindFree(false);
  badge.Set_ChoiceMade(false);
  badge.choice=1;
  badge.freeMinds[30];
*/
  if (EEPROM.read(idPos)is NULL){
    badge.Set_ID(EEPROM.read(idPos));
    Serial.print("initialising Badge ID");
  }
  //Serial.print("initialising\n[badge id]:\n" + badge.id ) ;
  badge.Set_MindFree(EEPROM.read(mindfreePos));
  //Serial.print("\n[mindfree]:\n" + badge.mindFree );
  badge.choiceMade = EEPROM.read(choiceMadePos);
  badge.choice = EEPROM.read(choicePos);
  //Serial.print("\n[choice made]:\n" + badge.choiceMade );
  Serial.print("\nBadges Seen {");
  for (int i = 0;i<30;i++){
    badge.freeMinds[i] = EEPROM.read(freeMindsBasePos+i);
  }
  Serial.print("\n}");
  return return_badge;
}

void writeBadge(Badge p_badge){
  EEPROM.write(p_badge.Get_ID,idPos);
  EEPROM.write(p_badge.Get_MindFree,mindfreePos);
  EEPROM.write(p_badge.Get_ChoiceMade,choiceMadePos);
  EEPROM.write(p_badge.Get_Choice,choicePos);
  for (int i = 0;i<30;i++){
    EEPROM.write(p_badge.Get_FreeMind[i],freeMindsBasePos+i);
  }
}
