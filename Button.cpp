#include "Arduino.h"
#include "Button.h"

Button::Button(int pin, bool invertedLogic, bool internalPullup){
  if(internalPullup){
    pinMode(pin, INPUT_PULLUP);
  } else{
    pinMode(pin, INPUT);
  }
  _pin = pin;
  _invertedLogic = invertedLogic;
  _lastState = false;
  _thisState = isDown();
}

void Button::update(){
  _lastState = _thisState;
  _thisState = isDown();

}

bool Button::isUp(){
  return !_thisState;
}

bool Button::isDown(){
  return _thisState;

}

bool Button::isClicked(){
  return !_thisState && _lastState; 
}


bool Button::isHeld(){
  return _thisState && _lastState;
}

bool Button::isPressed(){
  return _thisState && _lastState;
}