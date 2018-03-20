#include "Arduino.h"
#include "AnalogInput_h"

AnalogInput::AnalogInput(int pin){
	_pin = pin;
	_threshold = -1;
	pinMode(_pin, INPUT);
}

AnalogInput::AnalogInput(int pin, int threshold){
	_pin = pin;
	_threshold = threshold;
	pinMode(_pin, INPUT);
}

void update() {
	_lastReading = _thisReading;
	_thisReading = analogRead(_pin);
}

int getValue(){
	return _thisReading;
}

void setThreshhold(int threshold){

}

int getThreshhold(){

}

bool isOver(){

}

bool isUnder(){

}

bool movedOver(){

}

bool movedUnder(){

}

bool stayedOver(){

}

bool stayedUnder(){

}






