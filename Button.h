#ifndef Button_h
#define Button_h

#include "Input.h"

class Button : public Input
{
  public:
    Button(pin, invertedLogic = false, internalPullup = false) : Input(pin, invertedLogic, internalPullup){}
    ;
    void getStatus();

    
};
#endif