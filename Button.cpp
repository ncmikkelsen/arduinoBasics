#include "Arduino.h"
#include "Button.h"

Button::Button(int pin, bool internalPullup, bool debounce){
  _pin = pin;
  _internalPullup = internalPullup;
  if(_internalPullup){
    pinMode(_pin, INPUT_PULLUP);
  } else{
    pinMode(_pin, INPUT);
  }

  _lastState = false;
  _thisState = false;
  _lastReading = false;
  _thisReading = false;
  _debounce = debounce;
  _lastDebounceTime = 0;
  _debounceDelay = 50;
  update();
}

void Button::update(){
  _lastState = _thisState;
  _lastReading = _thisReading;

  if(_internalPullup){
    _thisReading = !digitalRead(_pin);
  } else{
    _thisReading = digitalRead(_pin);
  }

  // with debounce
  if(_debounce){
    if (_thisReading != _lastState && _thisReading != _lastReading) {
      // reset the debouncing timer
      _lastDebounceTime = millis();
    }
    if ((millis() - _lastDebounceTime) > _debounceDelay) {
      if (_thisReading != _lastState) {
        _thisState = _thisReading;
      }
    }

  }
  // without debounce
  else {
    _thisState = _thisReading;
  }

}

bool Button::isUp(){
  return !_thisState;
}

bool Button::isDown(){
  return _thisState;
}

bool Button::isPressed(){
  return _thisState && !_lastState;
}

bool Button::isReleased(){
  return !_thisState && _lastState;
}

bool Button::isHeld(){
  return _thisState && _lastState;
}

bool Button::isUnheld(){
  return !_thisState && !_lastState;
}

String Button::getStatus(){
  if(_thisState && !_lastState){
    return "PRESSED";
  } else if(!_thisState && _lastState){
    return "RELEASED";
  } else if(_thisState && _lastState){
    return "HELD";
  } else if(!_thisState && !_lastState){
    return "UNHELD";
  }
}
