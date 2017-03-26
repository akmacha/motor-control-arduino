#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{

private:
	int _i1;
	int _i2;
	int _sp;
	int _speed;
	int _clock_flag;

public:
	Motor(int pin1, int pin2, int speed_pin, int spd);
	void goClock(int s);
	void goClock();
	void goAClock(int s);
	void goAClock();
	void speedUp(int s);
	void slowDown(int s);
	void stopMotor();
	void writeSpeed(int s);
	void restore();
};

#endif