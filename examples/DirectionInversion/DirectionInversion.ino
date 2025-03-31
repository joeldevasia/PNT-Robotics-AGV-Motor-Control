#include <AGVMotorControl.h>

// Default pins are configured for Arduino Mega 2560:
// Left Motor PWM Pin: 5, Left Motor Direction Pin: 4
// Right Motor PWM Pin: 7, Right Motor Direction Pin: 6

// Initialize motor control with default pins
AGVMotorControl motorControl;

void setup() {
    Serial.begin(115200);
    motorControl.setup();

    // Invert motor directions
    motorControl.setLeftMotorInverted(true);
    motorControl.setRightMotorInverted(true);
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
}
