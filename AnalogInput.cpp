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
	_threshold = threshold;
}

int getThreshhold(){
	return _threshold;
}

bool isOver(){
	return _thisReading > _threshold;
}

bool isUnder(){
	return _thisReading < _threshold;
}

bool movedOver(){
	return (_thisReading > _threshold && _lastReading < _threshold);
}

bool movedUnder(){
	return (_thisReading < _threshold && _lastReading > _threshold);
}

bool stayedOver(){
	return (_thisReading > _threshold && _lastReading > _threshold);
}

bool stayedUnder(){
		return (_thisReading < _threshold && _lastReading < _threshold);
}

bool isOver(int threshold){

}

bool isUnder(int threshold){

}

bool movedOver(int threshold){

}

bool movedUnder(int threshold){

}

bool stayedOver(int threshold){

}

bool stayedUnder(int threshold){

}





