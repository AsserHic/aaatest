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

void MotorControl::backward() {
  rest();
  digitalWrite(m_l2, HIGH);
  digitalWrite(m_r2, HIGH);
}

void MotorControl::rest() {
  digitalWrite(m_l1, LOW);
  digitalWrite(m_l2, LOW);
  digitalWrite(m_r1, LOW);
  digitalWrite(m_r2, LOW);
  delay(10);
}

void MotorControl::forward() {
  rest();
  digitalWrite(m_l1, HIGH);
  digitalWrite(m_r1, HIGH);
}

void MotorControl::to_left() {
  rest();
  digitalWrite(m_r1, HIGH);
}

void MotorControl::to_right() {
  rest();
  digitalWrite(m_l1, HIGH);
}

void MotorControl::turn(boolean right) {
  rest();
  if (right) {
    digitalWrite(m_l1, HIGH);
    digitalWrite(m_r2, HIGH);
  } else {
    digitalWrite(m_r1, HIGH);
    digitalWrite(m_l2, HIGH);    
  }
}
