// Asser's automatic auto: infrared sensors
// AnalogSpeaker.cpp

#include "Arduino.h"

#include "AnalogSpeaker.h"

AnalogSpeaker::AnalogSpeaker(int pin) {
  m_pin = pin;

  pinMode(m_pin, OUTPUT);
}

void AnalogSpeaker::beep() {
  tone(m_pin, 400, 300);
}

void AnalogSpeaker::playBye() {
  tone(m_pin, 600); delay(300);
  tone(m_pin, 400); delay(300);
  tone(m_pin, 200, 300);
}

void AnalogSpeaker::playHello() {
  tone(m_pin, 200); delay(300);
  tone(m_pin, 400); delay(300);
  tone(m_pin, 600, 300);
}
