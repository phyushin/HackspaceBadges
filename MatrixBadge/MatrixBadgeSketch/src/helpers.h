#include <Arduino.h>
#include <EEPROM.h>
#include "Badge.cpp"

Badge readBadge(){
  Badge return_badge = new Badge::Badge();
  return_badge.Set_ID(EEPROM.read(idPos));
  Serial.print("initialising Badge ID");
  return_badge.Set_MindFree(EEPROM.read(mindfreePos));
  return_badge.Set_ChoiceMade(EEPROM.read(choiceMadePos));
  return_badge.Set_Choice(EEPROM.read(choicePos));
  Serial.print("\nBadges Seen {");
  for (int i = 0;i<30;i++){
    return_badge.Set_FreeMind(i,EEPROM.read(freeMindsBasePos+i));
  }
  Serial.print("\n}");
  return return_badge;
}

void writeBadge(Badge p_badge){
  EEPROM.write(p_badge.Get_ID(),idPos);
  EEPROM.write(p_badge.Get_MindFree(),mindfreePos);
  EEPROM.write(p_badge.Get_ChoiceMade(),choiceMadePos);
  EEPROM.write(p_badge.Get_Choice(),choicePos);
  for (int i = 0;i<30;i++){
    EEPROM.write(p_badge.Get_FreeMind(i),freeMindsBasePos+i);
  }
}
