// Asser's automatic auto: infrared sensors
// IRVector.h

#ifndef HEADER_IRVECTOR
  #define HEADER_IRVECTOR

class IRVector {

  private:
  
     int m_l;  // Left most sensor
     int m_cl; // Left front sensor
     int m_cr; // Right front sensor
     int m_r;  // Right most sensor
  
  public:

     IRVector(int l, int cl, int cr, int r);

     boolean is_left_clear();

     boolean is_right_clear();

     boolean is_front_left_clear();

     boolean is_front_right_clear();

     boolean is_front_clear();

};
#endif
