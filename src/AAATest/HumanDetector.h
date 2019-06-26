// Asser's automatic auto: human detector
// HumanDetector.h

#ifndef HEADER_HUMANDETECTOR
  #define HEADER_HUMANDETECTOR

class HumanDetector {

  private:

     int m_pin;

     unsigned int m_maxAway;

     unsigned long m_lastSeen;

  public:

     HumanDetector(int pin, unsigned int maxAway);

     int check();

};
#endif
