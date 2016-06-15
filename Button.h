#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button 
{   
  public:     
    Button(int pin, bool invertedLogic, bool internalPullup);     
    void update();
    bool isUp();     
    bool isDown();
    bool isClicked();
    bool isHeld();
    bool isPressed();

  private:
    bool _lastState;
    bool _thisState;
    int _pin;
    bool _invertedLogic;
};
#endif