// Asser's automatic auto: sound effects
// AnalogSpeaker.h

#ifndef HEADER_ANALOGSPEAKER
  #define HEADER_ANALOGSPEAKER

class AnalogSpeaker {

  private:

     int m_pin;

  public:

     AnalogSpeaker(int pin);

     void beep();

     void playBye();

     void playHello();

};
#endif
