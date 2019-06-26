// Asser's automatic auto: human detector
// HumanDetector.cpp

#include "Arduino.h"

#include "HumanDetector.h"

HumanDetector::HumanDetector(int pin, unsigned int maxAway) {
  m_pin      = pin;
  m_maxAway  = maxAway;
  m_lastSeen = 0;

  pinMode(m_pin, INPUT);
}

int HumanDetector::check() {
  boolean isPresent   = digitalRead(m_pin);
  int     result      = 0;

  if (isPresent) {
    if (m_lastSeen < 1) {
       result = 1;
    }
    m_lastSeen = millis() + m_maxAway;
  } else {    
    if ((m_lastSeen > 0) &&
        (m_lastSeen < millis())) {
       m_lastSeen = 0;
       result     = -1;
    }
  }
  return result;
}
