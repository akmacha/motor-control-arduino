# Arduino Motor Control 101
This is a library that can be used to control a simple DC motor hooked up to an Arduino board. The library has a bunch of simple functions that beginners and experts alike can play around with.
# Under the Hood
The library has the following functions: (for all the functions listed below, 's' lies between 0 and 255)
## 1. goClock(int s) and goClock():
This function runs the motor in the clockwise direction at a speed 's'. If no argument is specified, the motor is run at the same speed as it was.
## 2. goAClock(int s) and goAClock():
The same as goClock(), except this runs the motor anti-clockwise
## 3. speedUp(int s):
Speeds up the motor by 's' units.
## 4. slowDown(int s):
Slows down the motor by 's' units.
## 5. writeSpeed(int s):
Sets the speed of the motor to 's' units.
## 6. restore():
In the event of the motor stopping unexpectedly or accidentally, this function restores the motor to its last known speed and direction.
## 7. stopMotor():
Stops the motor. ¯\_(ツ)_/¯
# Usage
First, copy the **Motor** folder into **My Documents/Arduino/libraries/**

The motor constructor takes in 4 arguments: the two pins of the motor, the speed pin, and the initial speed. So, first, create an object of the **Motor** class like so:
```
#include <Motor.h>

int pin1 = 4;
int pin2 = 6;
int speed_pin = 11;
int spd = 255;

Motor m(pin1, pin2, speed_pin, spd);
```
All the pins used above are **OUTPUT** pins. So, set them as output pins in the **void setup()** function.
```
void setup() {

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(speed_pin, OUTPUT);

}
```
Next, we go to the **void loop()** function, where we call all the fucntions. This is a sample that calls all of the functions defined in the library.
```
void loop() {
  
  m.goClock(200);
  delay(5000);
  m.stopMotor();
  delay(3000);
  m.goAClock(200);
  delay(5000);
  m.stopMotor();
  delay(3000);
  m.restore();
  delay(4000);
  m.goClock(200);
  delay(3000);
  m.slowDown(100);
  delay(5000);
  m.speedUp(50);
  delay(5000);
  m.writeSpeed(250);
  delay(5000);
  
}
```
