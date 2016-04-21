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

float Button::getStatus(){
  if(_lastState && isDown()){
    return 1;
  } else if(_lastState && isUp()){
    return 0.75;
  } else if(!_lastState && isDown()){
    return 0.25;
  } else if(!_lastState && isUp()){
    return 0;
  }
}

void Button::update(){
  _lastState = isDown();
}

bool Button::isUp(){
  bool state = digitalRead(_pin);
  if(_invertedLogic){
    return state;
  } else{
    return !state;
  }
}

bool Button::isDown(){
  bool state = digitalRead(_pin);
  if(_invertedLogic){
    return !state;
  } else{
    return state;
  }
}