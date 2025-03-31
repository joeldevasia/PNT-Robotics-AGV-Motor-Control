#include <AGVMotorControl.h>

// Default pins are configured for Arduino Mega 2560:
// Left Motor PWM Pin: 5, Left Motor Direction Pin: 4
// Right Motor PWM Pin: 7, Right Motor Direction Pin: 6
// Left Encoder A Pin: 2, Left Encoder B Pin: 8
// Right Encoder A Pin: 3, Right Encoder B Pin: 9

// Note: Default pins in this library are configured for Arduino Mega 2560.
// Use custom initialization if using a different board or pin configuration.

// Initialize motor control
AGVMotorControl motorControl(DEFAULT_LEFT_MOTOR_PWM_PIN, DEFAULT_LEFT_MOTOR_DIR_PIN, DEFAULT_RIGHT_MOTOR_PWM_PIN, DEFAULT_RIGHT_MOTOR_DIR_PIN,
                             DEFAULT_LEFT_ENCODER_A_PIN, DEFAULT_LEFT_ENCODER_B_PIN, DEFAULT_RIGHT_ENCODER_A_PIN, DEFAULT_RIGHT_ENCODER_B_PIN, DEFAULT_ENCODER_PPR);
void setup() {
  Serial.begin(115200);
  motorControl.setup();
  motorControl.resetEncoders();
  motorControl.moveForward(20, 20);
}

void loop() {

  Serial.print("Left Encoder Count: ");
  Serial.print(motorControl.getLeftEncoderCount());
  Serial.print("    Right Encoder Count: ");
  Serial.println(motorControl.getRightEncoderCount());

  if (motorControl.getLeftEncoderCount() % 3000 == 0) {
    motorControl.resetEncoders();
  }
}
