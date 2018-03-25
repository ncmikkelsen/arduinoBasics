#include "Arduino.h"
#include "AnalogInput.h"

AnalogInput::AnalogInput(int pin){
	_pin = pin;
	_threshold = -1;
	_lastReading = 0;
	_thisReading = 0;
	pinMode(_pin, INPUT);
}

AnalogInput::AnalogInput(int pin, int threshold){
	_pin = pin;
	_threshold = threshold;
	_lastReading = 0;
	_thisReading = 0;
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
	return _thisReading > threshold;
}

bool isUnder(int threshold){
	return _thisReading < threshold;
}

bool movedOver(int threshold){
	return (_thisReading > threshold && _lastReading < threshold);
}

bool movedUnder(int threshold){
	return (_thisReading < threshold && _lastReading > threshold);
}

bool stayedOver(int threshold){
	return (_thisReading > threshold && _lastReading > threshold);
}

bool stayedUnder(int threshold){
	return (_thisReading < threshold && _lastReading < threshold);
}





