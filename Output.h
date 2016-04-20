#ifndef Output_h
#define Output_h

#include "Arduino.h"

class Output
{
  public:
    Output(int pin);
    void toggle();
    bool getState();
    void on();
    void off();

  private:
    int _pin;
    bool _state; 
};
#endif