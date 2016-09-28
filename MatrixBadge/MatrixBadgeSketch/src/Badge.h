
#ifndef __BADGE_H__
#define __BADGE_H__

// Include Files
#include <Arduino.h>

// Definitions
#define OFFSET_MAGIC 0
#define OFFSET_ID 0
#define OFFSET_MINDFREE 1
#define OFFSET_CHOICEMADE 2
#define OFFSET_CHOICE 3
#define OFFSET_FREEMINDS 4

#define NUM_FREEMINDS 30

#define CODE_MAGIC 0xCB

typedef enum PILL_CHOICE {
  CHOICE_NONE = 0,
  CHOICE_RED = 1,
  CHOICE_BLUE = 2
} PillChoice;

// Badge class - for reprsenting and storing this badge

class Badge {

private:
  uint8_t m_id;
  PillChoice m_choice;
  PillChoice m_freeMinds[NUM_FREEMINDS];

public:
  Badge();
  Badge(int, PillChoice);
  Badge(const Badge &);

  void Set_ID(int);
  void Set_PillChoice(PillChoice);
  void Set_FreeMind(int, PillChoice);

  int Get_ID();
  PillChoice Get_PillChoice();
  PillChoice Get_FreeMind(int);

  void SaveToEeprom();
  bool ReadFromEeprom();

protected:
  void setToDefaults();
};

#endif //__BADGE_H__
