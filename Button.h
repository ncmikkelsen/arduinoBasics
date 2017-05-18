#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button
{
  public:
    Button(int pin, bool internalPullup, bool debounce);
    void update();
    bool isUp();
    bool isDown();
    bool isPressed();
    bool isReleased();
    bool isHeld();
    bool isUnheld();

  private:
    bool _lastReading;
    bool _thisReading;
    bool _lastState;
    bool _thisState;
    bool _internalPullup;
    bool _debounce;
    int _pin;
    unsigned long _lastDebounceTime;
    unsigned long _debounceDelay;
};
#endif
