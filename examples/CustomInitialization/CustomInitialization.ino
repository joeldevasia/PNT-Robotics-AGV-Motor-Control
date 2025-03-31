#include <AGVMotorControl.h>

// Custom pin definitions
const int leftMotorPwmPin = 10;
const int leftMotorDirPin = 11;
const int rightMotorPwmPin = 12;
const int rightMotorDirPin = 13;

// Note: Default pins in this library are configured for Arduino Mega 2560.
// Use custom initialization if using a different board or pin configuration.

// Initialize motor control with custom pins
AGVMotorControl motorControl(leftMotorPwmPin, leftMotorDirPin, rightMotorPwmPin, rightMotorDirPin);

void setup() {
    Serial.begin(115200);
    motorControl.setup();
}

void loop() {
    motorControl.moveForward(150, 150);
    delay(2000);

    motorControl.stop();
    delay(1000);

    motorControl.moveBackward(150, 150);
    delay(2000);

    motorControl.stop();
    delay(1000);

    motorControl.rotateClockwise(150, 150);
    delay(2000);

    motorControl.stop();
    delay(1000);

    motorControl.rotateAnticlockwise(150, 150);
    delay(2000);

    motorControl.stop();
    delay(1000);
}
