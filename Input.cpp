#include "Arduino.h"
#include "Input.h"


Input::Input(int pin, bool invertedLogic, bool internalPullup){
  if(internalPullup){
    pinMode(pin, INPUT_PULLUP);
  } else {
    pinMode(pin, INPUT);
  }

  _pin = pin;
  _invertedLogic = invertedLogic;
}

bool Input::isOn(){
  if(_invertedLogic){
    return !digitalRead(_pin);
  } else{
    return digitalRead(_pin);
  }
}

bool Input::isOff(){
  if(_invertedLogic){
    return digitalRead(_pin);
  } else{
    return !digitalRead(_pin);
  }
}