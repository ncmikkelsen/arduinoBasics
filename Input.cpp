#include "Arduino.h"
#include "Input.h"

Input::Input(pin, invertedLogic, internalPullup){
  if(internalPullup){
    pinMode(pin, INPUT_PULLUP);
  } else {
    pinMode(pin, INPUT);
  }

  _pin = pin;
  _invertedLogic = invertedLogic;
}

bool Input::isOn(){
  if(invertedLogic){
    return !digitalRead(_pin);
  } else{
    return digitalRead(_pin);
  }
}

bool Input::isOff(){
  if(invertedLogic){
    return digitalRead(_pin);
  } else{
    return !digitalRead(_pin);
  }
}