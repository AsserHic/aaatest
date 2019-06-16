// Asser's automatic auto: wheel control
// MotorControl.h

#ifndef HEADER_MOTORCONTROL
  #define HEADER_MOTORCONTROL

class MotorControl {

  private:
  
     int m_l1; // Left motors pin #1
     int m_l2; // Left motors pin #2
     int m_r1; // Right motors pin #1
     int m_r2; // Right motors pin #2

     boolean m_state[4] = { false, false, false, false };

     void setState(boolean l1, boolean l2, boolean r1, boolean r2);

  public:

     MotorControl(int l1, int l2, int r1, int r2);

     void backward();

     void rest();
     
     void forward();

     void toLeft();
     
     void toRight();

     void turn(boolean right);

};
#endif
