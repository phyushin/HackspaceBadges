#include <Arduino.h>
#include <EEPROM.h>
#include "Badge.h"

badge_struct readStruct(){
  badge_struct badge;
  badge.id = EEPROM.read(idPos);
  Serial.print("initialising\n[badge id]:\n" + badge.id ) ;
  badge.mindFree = EEPROM.read(mindfreePos);
  Serial.print("\n[mindfree]:\n" + badge.mindFree );
  badge.choiceMade = EEPROM.read(choiceMadePos);
  Serial.print("\n[choice made]:\n" + badge.choiceMade );
  Serial.print("\nBadges Seen {");
  for (int i = 0;i<30;i++){
    badge.freeMinds[i] = EEPROM.read(freeMindsBasePos+i);
  }
  Serial.print("\n}");
  return badge;
}

void writeStruct(badge_struct p_badge){
  EEPROM.write(p_badge.id,idPos);
  EEPROM.write(p_badge.mindFree,mindfreePos);
  EEPROM.write(p_badge.choiceMade,choiceMadePos);
  for (int i = 0;i<30;i++){
    EEPROM.write(p_badge.freeMinds[i],freeMindsBasePos+i);
  }
}
