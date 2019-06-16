// Asser's automatic auto: infrared sensors
// IRVector.cpp

#include "Arduino.h"
#include "IRVector.h"

IRVector::IRVector(int l, int cl, int cr, int r) {
  m_l = l;
  m_cl = cl;
  m_cr = cr;
  m_r = r;

  pinMode(m_l,  INPUT);
  pinMode(m_cl, INPUT);
  pinMode(m_cr, INPUT);
  pinMode(m_r,  INPUT);
}

boolean IRVector::is_left_clear() {
  return digitalRead(m_l);
}

boolean IRVector::is_right_clear() {
  return digitalRead(m_r);
}

boolean IRVector::is_front_clear() {
  return digitalRead(m_cl) &&
         digitalRead(m_cr);
}
