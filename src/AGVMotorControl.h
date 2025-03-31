#ifndef AGV_MOTOR_CONTROL_H
#define AGV_MOTOR_CONTROL_H

#include <Arduino.h>

// Default pin definitions
#define DEFAULT_LEFT_MOTOR_PWM_PIN  5
#define DEFAULT_LEFT_MOTOR_DIR_PIN  4
#define DEFAULT_RIGHT_MOTOR_PWM_PIN 7
#define DEFAULT_RIGHT_MOTOR_DIR_PIN 6
#define DEFAULT_LEFT_ENCODER_A_PIN  2
#define DEFAULT_LEFT_ENCODER_B_PIN  8
#define DEFAULT_RIGHT_ENCODER_A_PIN 3
#define DEFAULT_RIGHT_ENCODER_B_PIN 9
#define DEFAULT_ENCODER_PPR         1000 ///< Default pulses per rotation

/**
 * @class AGVMotorControl
 * @brief A class for controlling the motors of an AGV (Automated Guided Vehicle).
 */
class AGVMotorControl {
public:
    /**
     * @brief Constructs an AGVMotorControl object with specified motor and encoder pins or default pins.
     * 
     * @param[in] leftMotorPwmPin PWM pin for the left motor (default: 5).
     * @param[in] leftMotorDirPin Direction pin for the left motor (default: 4).
     * @param[in] rightMotorPwmPin PWM pin for the right motor (default: 7).
     * @param[in] rightMotorDirPin Direction pin for the right motor (default: 6).
     * @param[in] leftEncoderAPin Encoder A pin for the left motor (default: 2).
     * @param[in] leftEncoderBPin Encoder B pin for the left motor (default: 8).
     * @param[in] rightEncoderAPin Encoder A pin for the right motor (default: 3).
     * @param[in] rightEncoderBPin Encoder B pin for the right motor (default: 9).
     * @param[in] ppr Pulses per rotation for the encoders (default: 266).
     */
    AGVMotorControl(int leftMotorPwmPin = DEFAULT_LEFT_MOTOR_PWM_PIN, 
                    int leftMotorDirPin = DEFAULT_LEFT_MOTOR_DIR_PIN, 
                    int rightMotorPwmPin = DEFAULT_RIGHT_MOTOR_PWM_PIN, 
                    int rightMotorDirPin = DEFAULT_RIGHT_MOTOR_DIR_PIN,
                    int leftEncoderAPin = DEFAULT_LEFT_ENCODER_A_PIN,
                    int leftEncoderBPin = DEFAULT_LEFT_ENCODER_B_PIN,
                    int rightEncoderAPin = DEFAULT_RIGHT_ENCODER_A_PIN,
                    int rightEncoderBPin = DEFAULT_RIGHT_ENCODER_B_PIN,
                    int ppr = DEFAULT_ENCODER_PPR);

    /**
     * @brief Configures the motor pins as outputs and stops the motors.
     * 
     * This method must be called in the `setup()` function of the Arduino sketch.
     */
    void setup();

    /**
     * @brief Moves the motors forward with specified PWM values.
     * 
     * @param[in] leftMotorPWM PWM value for the left motor (0-255).
     * @param[in] rightMotorPWM PWM value for the right motor (0-255).
     */
    void moveForward(int leftMotorPWM, int rightMotorPWM);

    /**
     * @brief Moves the motors backward with specified PWM values.
     * 
     * @param[in] leftMotorPWM PWM value for the left motor (0-255).
     * @param[in] rightMotorPWM PWM value for the right motor (0-255).
     */
    void moveBackward(int leftMotorPWM, int rightMotorPWM);

    /**
     * @brief Stops both motors.
     */
    void stop();

    /**
     * @brief Rotates the AGV clockwise with specified PWM values.
     * 
     * @param[in] leftMotorPWM PWM value for the left motor (0-255).
     * @param[in] rightMotorPWM PWM value for the right motor (0-255).
     */
    void rotateClockwise(int leftMotorPWM, int rightMotorPWM);

    /**
     * @brief Rotates the AGV anticlockwise with specified PWM values.
     * 
     * @param[in] leftMotorPWM PWM value for the left motor (0-255).
     * @param[in] rightMotorPWM PWM value for the right motor (0-255).
     */
    void rotateAnticlockwise(int leftMotorPWM, int rightMotorPWM);

    /**
     * @brief Sets the minimum and maximum PWM limits for the motors.
     * 
     * @param[in] minPWM Minimum PWM value (0-255).
     * @param[in] maxPWM Maximum PWM value (0-255).
     */
    void setPWMLimits(int minPWM, int maxPWM);

    /**
     * @brief Inverts the direction of the left motor.
     * 
     * @param[in] inverted True to invert the direction, false otherwise.
     */
    void setLeftMotorInverted(bool inverted);

    /**
     * @brief Inverts the direction of the right motor.
     * 
     * @param[in] inverted True to invert the direction, false otherwise.
     */
    void setRightMotorInverted(bool inverted);

    /**
     * @brief Checks if the left motor direction is inverted.
     * 
     * @return True if the left motor direction is inverted, false otherwise.
     */
    bool isLeftMotorInverted() const;

    /**
     * @brief Checks if the right motor direction is inverted.
     * 
     * @return True if the right motor direction is inverted, false otherwise.
     */
    bool isRightMotorInverted() const;

    /**
     * @brief Sets whether the left encoder counting should be inverted.
     * 
     * @param[in] inverted True to invert the left encoder counting, false otherwise.
     */
    void setLeftEncoderInverted(bool inverted);

    /**
     * @brief Sets whether the right encoder counting should be inverted.
     * 
     * @param[in] inverted True to invert the right encoder counting, false otherwise.
     */
    void setRightEncoderInverted(bool inverted);

    /**
     * @brief Checks if the left encoder counting is inverted.
     * 
     * @return True if the left encoder counting is inverted, false otherwise.
     */
    bool isLeftEncoderInverted() const;

    /**
     * @brief Checks if the right encoder counting is inverted.
     * 
     * @return True if the right encoder counting is inverted, false otherwise.
     */
    bool isRightEncoderInverted() const;

    /**
     * @brief Resets the encoder counts to zero.
     */
    void resetEncoders();

    /**
     * @brief Gets the current count of the left encoder.
     * 
     * @return The count of the left encoder.
     */
    long getLeftEncoderCount() const;

    /**
     * @brief Gets the current count of the right encoder.
     * 
     * @return The count of the right encoder.
     */
    long getRightEncoderCount() const;

    /**
     * @brief Sets the pulses per rotation (PPR) for the encoders.
     * 
     * @param[in] ppr The number of pulses per rotation.
     */
    void setEncoderPPR(int ppr);

    /**
     * @brief Gets the pulses per rotation (PPR) for the encoders.
     * 
     * @return The number of pulses per rotation.
     */
    int getEncoderPPR() const;

    /**
     * @brief Gets the current PWM value of the left motor.
     * 
     * @return The current PWM value of the left motor.
     */
    int getLeftMotorPWM() const;

    /**
     * @brief Gets the current PWM value of the right motor.
     * 
     * @return The current PWM value of the right motor.
     */
    int getRightMotorPWM() const;

private:
    int leftMotorPwmPin; ///< PWM pin for the left motor.
    int leftMotorDirPin; ///< Direction pin for the left motor.
    int rightMotorPwmPin; ///< PWM pin for the right motor.
    int rightMotorDirPin; ///< Direction pin for the right motor.
    int leftEncoderAPin; ///< Encoder A pin for the left motor.
    int leftEncoderBPin; ///< Encoder B pin for the left motor.
    int rightEncoderAPin; ///< Encoder A pin for the right motor.
    int rightEncoderBPin; ///< Encoder B pin for the right motor.
    int minPwmValue; ///< Minimum PWM value.
    int maxPwmValue; ///< Maximum PWM value.
    bool leftMotorInverted; ///< Flag to indicate if the left motor direction is inverted.
    bool rightMotorInverted; ///< Flag to indicate if the right motor direction is inverted.
    bool leftEncoderInverted; ///< Flag to indicate if the left encoder counting is inverted.
    bool rightEncoderInverted; ///< Flag to indicate if the right encoder counting is inverted.

    int encoderPPR; ///< Pulses per rotation for the encoders.

    int currentLeftMotorPWM; ///< Current PWM value for the left motor.
    int currentRightMotorPWM; ///< Current PWM value for the right motor.

    // Encoder counts
    static volatile long leftEncoderCount;
    static volatile long rightEncoderCount;

    // Static instance pointer
    static AGVMotorControl* instance;

    // Encoder interrupt handlers
    static void handleLeftEncoderInterrupt();
    static void handleRightEncoderInterrupt();
};

#endif