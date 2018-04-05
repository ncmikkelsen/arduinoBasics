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

void AnalogInput::update() {
	_lastReading = _thisReading;
	_thisReading = analogRead(_pin);
}

int AnalogInput::getValue(){
	return _thisReading;
}

void AnalogInput::setThreshhold(int threshold){
	_threshold = threshold;
}

int AnalogInput::getThreshhold(){
	return _threshold;
}

bool AnalogInput::isOver(){
	return _thisReading > _threshold;
}

bool AnalogInput::isUnder(){
	return _thisReading < _threshold;
}

bool AnalogInput::movedOver(){
	return (_thisReading > _threshold && _lastReading < _threshold);
}

bool AnalogInput::movedUnder(){
	return (_thisReading < _threshold && _lastReading > _threshold);
}

bool AnalogInput::stayedOver(){
	return (_thisReading > _threshold && _lastReading > _threshold);
}

bool AnalogInput::stayedUnder(){
	return (_thisReading < _threshold && _lastReading < _threshold);
}

bool AnalogInput::isOver(int threshold){
	return _thisReading > threshold;
}

bool AnalogInput::isUnder(int threshold){
	return _thisReading < threshold;
}

bool AnalogInput::movedOver(int threshold){
	return (_thisReading > threshold && _lastReading < threshold);
}

bool AnalogInput::movedUnder(int threshold){
	return (_thisReading < threshold && _lastReading > threshold);
}

bool AnalogInput::stayedOver(int threshold){
	return (_thisReading > threshold && _lastReading > threshold);
}

bool AnalogInput::stayedUnder(int threshold){
	return (_thisReading < threshold && _lastReading < threshold);
}

