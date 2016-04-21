#include "Arduino.h"
#include "Output.h"

Output::Output(int pin){
  pinMode(pin, OUTPUT);
  _pin = pin;
  _state = LOW;
  off();
}

bool Output::getState(){
  return _state;
}

void Output::toggle(){
  _state = ! _state;
  digitalWrite(_pin, _state);
}

void Output::on(){
  _state = HIGH;
  digitalWrite(_pin, _state);
}

void Output::off(){
  _state = LOW;
  digitalWrite(_pin, _state);
}
