#include "AGVMotorControl.h"

// Initialize static variables
volatile long AGVMotorControl::leftEncoderCount = 0;
volatile long AGVMotorControl::rightEncoderCount = 0;
AGVMotorControl* AGVMotorControl::instance = nullptr;

AGVMotorControl::AGVMotorControl(int leftMotorPwmPin, int leftMotorDirPin, int rightMotorPwmPin, int rightMotorDirPin,
                                 int leftEncoderAPin, int leftEncoderBPin, int rightEncoderAPin, int rightEncoderBPin,
                                 int ppr)
    : leftMotorPwmPin(leftMotorPwmPin), leftMotorDirPin(leftMotorDirPin),
      rightMotorPwmPin(rightMotorPwmPin), rightMotorDirPin(rightMotorDirPin),
      leftEncoderAPin(leftEncoderAPin), leftEncoderBPin(leftEncoderBPin),
      rightEncoderAPin(rightEncoderAPin), rightEncoderBPin(rightEncoderBPin),
      minPwmValue(0), maxPwmValue(255), 
      leftMotorInverted(false), rightMotorInverted(false),
      encoderPPR(ppr),
      leftEncoderInverted(false), // Encoders are not inverted by default
      rightEncoderInverted(false) // Encoders are not inverted by default
{
    instance = this; // Set the static instance pointer to this instance
}

void AGVMotorControl::setup() {
    pinMode(leftMotorPwmPin, OUTPUT);
    pinMode(leftMotorDirPin, OUTPUT);
    pinMode(rightMotorPwmPin, OUTPUT);
    pinMode(rightMotorDirPin, OUTPUT);

    pinMode(leftEncoderAPin, INPUT_PULLUP);
    pinMode(leftEncoderBPin, INPUT_PULLUP);
    pinMode(rightEncoderAPin, INPUT_PULLUP);
    pinMode(rightEncoderBPin, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(leftEncoderAPin), handleLeftEncoderInterrupt, CHANGE);
    attachInterrupt(digitalPinToInterrupt(rightEncoderAPin), handleRightEncoderInterrupt, CHANGE);

    stop();
}

void AGVMotorControl::moveForward(int leftMotorPWM, int rightMotorPWM) {
    leftMotorPWM = constrain(leftMotorPWM, minPwmValue, maxPwmValue);
    rightMotorPWM = constrain(rightMotorPWM, minPwmValue, maxPwmValue);
    analogWrite(leftMotorPwmPin, leftMotorPWM);
    analogWrite(rightMotorPwmPin, rightMotorPWM);
    digitalWrite(leftMotorDirPin, leftMotorInverted ? LOW : HIGH);
    digitalWrite(rightMotorDirPin, rightMotorInverted ? LOW : HIGH);
}

void AGVMotorControl::moveBackward(int leftMotorPWM, int rightMotorPWM) {
    leftMotorPWM = constrain(leftMotorPWM, minPwmValue, maxPwmValue);
    rightMotorPWM = constrain(rightMotorPWM, minPwmValue, maxPwmValue);
    analogWrite(leftMotorPwmPin, leftMotorPWM);
    analogWrite(rightMotorPwmPin, rightMotorPWM);
    digitalWrite(leftMotorDirPin, leftMotorInverted ? HIGH : LOW);
    digitalWrite(rightMotorDirPin, rightMotorInverted ? HIGH : LOW);
}

void AGVMotorControl::stop() {
    analogWrite(leftMotorPwmPin, 0);
    analogWrite(rightMotorPwmPin, 0);
}

void AGVMotorControl::rotateClockwise(int leftMotorPWM, int rightMotorPWM) {
    leftMotorPWM = constrain(leftMotorPWM, minPwmValue, maxPwmValue);
    rightMotorPWM = constrain(rightMotorPWM, minPwmValue, maxPwmValue);
    analogWrite(leftMotorPwmPin, leftMotorPWM);
    analogWrite(rightMotorPwmPin, rightMotorPWM);
    digitalWrite(leftMotorDirPin, leftMotorInverted ? LOW : HIGH);
    digitalWrite(rightMotorDirPin, rightMotorInverted ? HIGH : LOW);
}

void AGVMotorControl::rotateAnticlockwise(int leftMotorPWM, int rightMotorPWM) {
    leftMotorPWM = constrain(leftMotorPWM, minPwmValue, maxPwmValue);
    rightMotorPWM = constrain(rightMotorPWM, minPwmValue, maxPwmValue);
    analogWrite(leftMotorPwmPin, leftMotorPWM);
    analogWrite(rightMotorPwmPin, rightMotorPWM);
    digitalWrite(leftMotorDirPin, leftMotorInverted ? HIGH : LOW);
    digitalWrite(rightMotorDirPin, rightMotorInverted ? LOW : HIGH);
}

void AGVMotorControl::setPWMLimits(int minPWM, int maxPWM) {
    if (minPWM >= 0 && maxPWM <= 255 && minPWM < maxPWM) {
        minPwmValue = minPWM;
        maxPwmValue = maxPWM;
    }
}

void AGVMotorControl::setLeftMotorInverted(bool inverted) {
    leftMotorInverted = inverted;
}

void AGVMotorControl::setRightMotorInverted(bool inverted) {
    rightMotorInverted = inverted;
}

bool AGVMotorControl::isLeftMotorInverted() const {
    return leftMotorInverted;
}

bool AGVMotorControl::isRightMotorInverted() const {
    return rightMotorInverted;
}

void AGVMotorControl::resetEncoders() {
    leftEncoderCount = 0;
    rightEncoderCount = 0;
}

long AGVMotorControl::getLeftEncoderCount() const {
    return leftEncoderCount;
}

long AGVMotorControl::getRightEncoderCount() const {
    return rightEncoderCount;
}

void AGVMotorControl::handleLeftEncoderInterrupt() {
    if (instance) { // Ensure the instance pointer is valid
        int stateA = digitalRead(instance->leftEncoderAPin);
        int stateB = digitalRead(instance->leftEncoderBPin);
        if (stateA == stateB) {
            leftEncoderCount += instance->leftEncoderInverted ? -1 : 1;
        } else {
            leftEncoderCount += instance->leftEncoderInverted ? 1 : -1;
        }
    }
}

void AGVMotorControl::handleRightEncoderInterrupt() {
    if (instance) { // Ensure the instance pointer is valid
        int stateA = digitalRead(instance->rightEncoderAPin);
        int stateB = digitalRead(instance->rightEncoderBPin);
        if (stateA == stateB) {
            rightEncoderCount += instance->rightEncoderInverted ? 1 : -1;
        } else {
            rightEncoderCount += instance->rightEncoderInverted ? -1 : 1;
        }
    }
}

void AGVMotorControl::setLeftEncoderInverted(bool inverted) {
    leftEncoderInverted = inverted;
}

void AGVMotorControl::setRightEncoderInverted(bool inverted) {
    rightEncoderInverted = inverted;
}

bool AGVMotorControl::isLeftEncoderInverted() const {
    return leftEncoderInverted;
}

bool AGVMotorControl::isRightEncoderInverted() const {
    return rightEncoderInverted;
}

void AGVMotorControl::setEncoderPPR(int ppr) {
    if (ppr > 0) {
        encoderPPR = ppr;
    }
}

int AGVMotorControl::getEncoderPPR() const {
    return encoderPPR;
}