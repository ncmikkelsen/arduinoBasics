#ifndef Button_h
#define Button_h

#include "Input.h"

class Button : public Input
{
  public:
    Button(int pin, bool invertedLogic = false, bool internalPullup = false) : Input(pin, invertedLogic, internalPullup){}
    ;
    void getStatus();

    
};
#endif