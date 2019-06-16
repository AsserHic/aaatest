// Asser's automatic auto: wheel control
// MotorControl.cpp

#include "Arduino.h"

#include "MotorControl.h"

MotorControl::MotorControl(int l1, int l2, int r1, int r2) {
  m_l1 = l1;
  m_l2 = l2;
  m_r1 = r1;
  m_r2 = r2;

  pinMode(m_l1, OUTPUT);
  pinMode(m_l2, OUTPUT);
  pinMode(m_r1, OUTPUT);
  pinMode(m_r2, OUTPUT);
}

void MotorControl::setState(boolean l1, boolean l2, boolean r1, boolean r2) {
  boolean wait = false;
  if (l1 && m_state[1]) { digitalWrite(m_l2, LOW); wait = true; }
  if (l2 && m_state[0]) { digitalWrite(m_l1, LOW); wait = true; }
  if (r1 && m_state[3]) { digitalWrite(m_r2, LOW); wait = true; }
  if (r2 && m_state[2]) { digitalWrite(m_r1, LOW); wait = true; }
  if (wait) {
    delay(10); // Let the high pins cool down.
  }
  digitalWrite(m_l1, l1); m_state[0] = l1;
  digitalWrite(m_l2, l2); m_state[1] = l2;
  digitalWrite(m_r1, r1); m_state[2] = r1;
  digitalWrite(m_r2, r2); m_state[3] = r2;
}

void MotorControl::backward() {
  setState(false, true, false, true);
}

void MotorControl::rest() {
  setState(false, false, false, false);
}

void MotorControl::forward() {
  setState(true, false, true, false);
}

void MotorControl::toLeft() {
  setState(false, false, true, false);
}

void MotorControl::toRight() {
  setState(true, false, false, false);
}

void MotorControl::turn(boolean right) {
  if (right) {
    setState(true, false, false, true);
  } else {
    setState(false, true, true, false);
  }
}
