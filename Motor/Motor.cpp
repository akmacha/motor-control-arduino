// Motor_Control.cpp : Defines the entry point for the console application.
//

#include "Motor.h"
#include "Arduino.h"

Motor::Motor(int pin1, int pin2, int speed_pin, int spd) {
	_i1 = pin1;
	_i2 = pin2;
	_speed = spd;
	_sp = speed_pin;
}

void Motor::goClock(int s) { // To run the motor in the clockwise direction at a speed 's'
	_speed = s;
	_clock_flag = 0;
	analogWrite(_sp, _speed); 
	digitalWrite(_i1, HIGH);
	digitalWrite(_i2, LOW);
}

void Motor::goClock() { // To run the motor in the clockwise direction at the same speed
	_clock_flag = 0;
	analogWrite(_sp, _speed); 
	digitalWrite(_i1, HIGH);
	digitalWrite(_i2, LOW);
}

void Motor::goAClock(int s) { // To run the motor in the anti-clockwise direction at a speed 's'
	_speed = s;
	_clock_flag = 1;
	analogWrite(_sp, _speed); 	
	digitalWrite(_i2, HIGH);
	digitalWrite(_i1, LOW);
}

void Motor::goAClock() { // To run the motor in the anti-clockwise direction at the same speed
	_clock_flag = 1;
	analogWrite(_sp, _speed); 	
	digitalWrite(_i2, HIGH);
	digitalWrite(_i1, LOW);
}

void Motor::speedUp(int s) {
	_speed += s;
	analogWrite(_sp, _speed);
}

void Motor::slowDown(int s) {
	_speed -= s;
	analogWrite(_sp, _speed);
}

void Motor::stopMotor() {
	digitalWrite(_i1, LOW);
	digitalWrite(_i2, LOW);
}

void Motor::writeSpeed(int s) {
	_speed = s;
	analogWrite(_sp, s);
}

void Motor::restore() {
	if (_clock_flag == 0) {
		goClock();
	}
	else {
		goAClock();
	}
}