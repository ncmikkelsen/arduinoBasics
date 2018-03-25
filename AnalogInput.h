#ifndef AnalogInput_h
#define AnalogInput_h

#include "Arduino.h"

class AnalogInput
{
	public:
		AnalogInput(int pin);
		AnalogInput(int pin, int threshold);
		void update();
		int getValue();
		void setThreshhold(int threshold);
		int getThreshhold();
		bool isOver();
		bool isUnder();
		bool movedOver();
		bool movedUnder();
		bool stayedOver();
		bool stayedUnder();
		bool isOver(int threshold);
		bool isUnder(int threshold);
		bool movedOver(int threshold);
		bool movedUnder(int threshold);
		bool stayedOver(int threshold);
		bool stayedUnder(int threshold);

	private:
		int _lastReading;
		int _thisReading;
		int _threshold;
		int _pin;
};
#endif
