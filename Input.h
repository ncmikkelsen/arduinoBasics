#ifndef Input_h
#define Input_h

#include "Arduino.h"

class Input
{
  public:
    Input(pin, invertedLogic = false, internalPullup = false);
    bool isOn();
    bool isOff();

  protected:
    int _pin;
    bool _invertedLogic;
};
#endif