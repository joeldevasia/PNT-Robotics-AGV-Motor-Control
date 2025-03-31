#include <AGVMotorControl.h>

// Default pins are configured for Arduino Mega 2560:
// Left Motor PWM Pin: 5, Left Motor Direction Pin: 4
// Right Motor PWM Pin: 7, Right Motor Direction Pin: 6
// Left Encoder A Pin: 2, Left Encoder B Pin: 8
// Right Encoder A Pin: 3, Right Encoder B Pin: 9

// Note: Default pins in this library are configured for Arduino Mega 2560.
// Use custom initialization if using a different board or pin configuration.

// Define motor and encoder pins
const int leftMotorPwmPin = 3;
const int leftMotorDirPin = 4;
const int rightMotorPwmPin = 5;
const int rightMotorDirPin = 6;
const int leftEncoderAPin = 2;
const int leftEncoderBPin = 7;
const int rightEncoderAPin = 8;
const int rightEncoderBPin = 9;

// Initialize motor control
AGVMotorControl motorControl(leftMotorPwmPin, leftMotorDirPin, rightMotorPwmPin, rightMotorDirPin,
                              leftEncoderAPin, leftEncoderBPin, rightEncoderAPin, rightEncoderBPin, 360);

void setup() {
    Serial.begin(115200);
    motorControl.setup();
    motorControl.resetEncoders();
}

void loop() {
    motorControl.moveForward(150, 150);
    delay(2000);

    motorControl.stop();
    delay(1000);

    Serial.print("Left Encoder Count: ");
    Serial.println(motorControl.getLeftEncoderCount());
    Serial.print("Right Encoder Count: ");
    Serial.println(motorControl.getRightEncoderCount());

    motorControl.resetEncoders();
    delay(1000);
}
