#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button 
{   
  public:     
    Button(int pin, bool invertedLogic, bool internalPullup);     
    float getStatus();     
    void update();     
    bool isDown();
    bool isUp();
    

  private:
    bool _lastState;
    bool _thisState;
    int _pin;
    bool _invertedLogic;
};
#endif