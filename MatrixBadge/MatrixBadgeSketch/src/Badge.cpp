
#include <Arduino.h>
#include <EEPROM.h>

#include "Badge.h"

/**
 * Default constructor
 */
Badge::Badge() { setToDefaults(); }

/**
 * Default constructor
 */
Badge::Badge(int p_ID, PillChoice p_choice) {
  m_id = (uint8_t)(p_ID & 0xFF);
  m_choice = p_choice;
  for (int i = 0; i < NUM_FREEMINDS; i++)
    m_freeMinds[i] = CHOICE_NONE;
}

/**
 * Copy constructor
 */
Badge::Badge(const Badge &copy) {
  m_id = copy.m_id;
  m_choice = copy.m_choice;
  for (int i = 0; i < NUM_FREEMINDS; i++)
    m_freeMinds[i] = copy.m_freeMinds[i];
}

/**
 * Sets this Badge's ID value
 */
void Badge::Set_ID(int p_ID) { m_id = p_ID; }
/**
 * Sets this Badge's owners selection of the PILL color, default is NONE if it
 * hasn't been selected yet.
 */
void Badge::Set_PillChoice(PillChoice p_choice) { m_choice = p_choice; }
/**
 * Sets the PILL color selection of another badge (RED/BLUE) if it has
 * been discovered, default is NONE if it hasn't been set yet.
 */
void Badge::Set_FreeMind(int p_ID, PillChoice p_choice) {
  if ((p_ID >= 0) && (p_ID < NUM_FREEMINDS)) {
    m_freeMinds[p_ID] = p_choice;
  }
}

/**
 * Returns this Badge's ID value
 */
int Badge::Get_ID() { return m_id; }
/**
 * Returns this Badge's owners selection of the PILL color, or none if it
 * hasn't been selected yet.
 */
PillChoice Badge::Get_PillChoice() { return m_choice; }
/**
 * Returns the PILL color selection of another badge (RED/BLUE) if it has
 * been discovered, or NONE if it hasn't been discovered yet.
 */
PillChoice Badge::Get_FreeMind(int p_ID) {
  if ((p_ID >= 0) && (p_ID < NUM_FREEMINDS)) {
    return m_freeMinds[p_ID];
  } else {
    return CHOICE_NONE;
  }
}

/**
 * Saves the contents of this Badge instance to EEPROM.
 */
void Badge::SaveToEeprom() {
  EEPROM.write((uint8_t)CODE_MAGIC, OFFSET_MAGIC);
  EEPROM.write((uint8_t)m_id, OFFSET_ID);
  EEPROM.write((uint8_t)m_choice, OFFSET_CHOICE);
  for (int i = 0; i < NUM_FREEMINDS; i++) {
    EEPROM.write(m_freeMinds[i], OFFSET_FREEMINDS + i);
  }
}

/**
 * Populates this Badge instance with the contents contained in the EEPROM.
 * This function returns true if something was found in the EEPROM or false
 * if the EEPROM hadn't been written yet.
 */
bool Badge::ReadFromEeprom() {
  bool result = false;
  uint8_t choice;
  // Check to see if the EEPROM has been written before
  if (EEPROM.read(OFFSET_MAGIC) == CODE_MAGIC) {
    m_id = EEPROM.read(OFFSET_ID);
    // Check this badge's choice value
    choice = EEPROM.read(OFFSET_CHOICE);
    if ((choice == (uint8_t)CHOICE_BLUE) || (choice == (uint8_t)CHOICE_RED)) {
      m_choice = (PillChoice)choice;
    } else {
      m_choice = CHOICE_NONE;
    }
    // Read the rest of the choice values
    for (int i = 0; i < NUM_FREEMINDS; i++) {
      choice = EEPROM.read(OFFSET_FREEMINDS + i);
      if ((choice == (uint8_t)CHOICE_BLUE) || (choice == (uint8_t)CHOICE_RED)) {
        m_choice = (PillChoice)choice;
      } else {
        m_choice = CHOICE_NONE;
      }
    }
    result = true;
  } else {
    setToDefaults();
  }

  return result;
}

/**
 * Protected function to reset the contents of this Badge instance to defaults
 */
void Badge::setToDefaults() {
  m_id = 'a';
  m_choice = CHOICE_NONE;
  for (int i = 0; i < NUM_FREEMINDS; i++)
    m_freeMinds[i] = CHOICE_NONE;
}
