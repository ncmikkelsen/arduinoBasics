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


