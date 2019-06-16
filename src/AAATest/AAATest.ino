/*
 This is Asser's automatic auto demo.

 by: Marko Laakso
 */

#include "Arduino.h"
#include "MotorControl.h"
#include "IRVector.h"

// Arduino pins:
// motor:
const int MOTOR_L1 = 13;
const int MOTOR_L2 = 12;
const int MOTOR_R1 = 11;
const int MOTOR_R2 = 10;
// Infra red sensors
const int IR_L  = A3;
const int IR_CL = A2;
const int IR_CR = A1;
const int IR_R  = A0;

MotorControl motors = MotorControl(MOTOR_L1, MOTOR_L2, MOTOR_R1, MOTOR_R2);
IRVector     irv = IRVector(IR_L, IR_CL, IR_CR, IR_R);

/*
 This routine is executed once for the beginning.
 */
void setup() {
  motors.rest();
}

/*
 This function is called in an infinite loop forever.
 */
void loop() {
  boolean clear_l = irv.is_left_clear();
  boolean clear_r = irv.is_right_clear();

  if (irv.is_front_clear()) {
    if (clear_l && clear_r) {
      motors.forward();
    } else
    if (clear_l && !clear_r) {
      motors.toLeft();
    } else
    if (!clear_l && clear_r) {
      motors.toRight();
    } else {
      front_obstacle();
    }
  } else {
    if (clear_l && irv.is_front_left_clear()) {
      motors.turn(false);
    } else
    if (clear_r && irv.is_front_right_clear()) {
      motors.turn(true);
    } else {
      front_obstacle();
    }
  }

  delay(50);
}

void front_obstacle() {
  motors.rest();
  delay(50);
  motors.backward();
  delay(random(100, 2000));
  motors.turn(random(0, 2) < 1);
  delay(random(300, 1000));
}
