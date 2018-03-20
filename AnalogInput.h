#ifndef AnalogInput_h
#define AnalogInput_h

#include "Arduino.h"

class AnalogInput
{
public:
	AnalogInput(int pin);
	AnalogInput(int pin, int threshhold);
	void update();
	int getValue();
	void setThreshhold(int threshhold);
	int getThreshhold();
	bool isOver();
	bool isUnder();
	bool movedOver();
	bool movedUnder();
	bool stayedOver();
	bool stayedUnder();
	bool isOver(int threshhold);
	bool isUnder(int threshhold);
	bool movedOver(int threshhold);
	bool movedUnder(int threshhold);
	bool stayedOver(int threshhold);
	bool stayedUnder(int threshhold);

private:
	int _lastReading;
	int _thisReading;
	int _threshold;
	int _pin;


};
#endif
