#ifndef Input_h
#define Input_h

#include "Arduino.h"

class Input
{
  public:
    Input(int pin, bool invertedLogic = false, bool internalPullup = false);
    bool isOn();
    bool isOff();

  protected:
    int _pin;
    bool _invertedLogic;
};
#endif