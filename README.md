# AGVMotorControl Library

An Arduino library for controlling motors and reading encoder data in PNT AGV.

## Features

- PWM-based motor control
- Direction inversion for motors
- Encoder feedback for precise movement
- Configurable pins and parameters

## Installation

1. Download this repository as a ZIP file.
2. In Arduino IDE: Sketch -> Include Library -> Add .ZIP Library...
3. Select the downloaded ZIP file.

## Usage

### Default Pins and Parameters

The default pins and parameters used in this library are configured for the Arduino Mega 2560. If you are using a different board, you may need to use custom initialization to specify the correct pins.

| Function                          | Default Pin | Default Parameter |
|-----------------------------------|-------------|-------------------|
| Left Motor PWM                    | 5           |                   |
| Left Motor Direction              | 4           |                   |
| Right Motor PWM                   | 7           |                   |
| Right Motor Direction             | 6           |                   |
| Left Encoder A                    | 2           |                   |
| Left Encoder B                    | 8           |                   |
| Right Encoder A                   | 3           |                   |
| Right Encoder B                   | 9           |                   |
| Encoder Pulses Per Rotation (PPR) |             | 266               |

### Basic Example

```cpp
#include <AGVMotorControl.h>

// Default pins are used if no custom pins are specified during initialization:
// Left Motor PWM Pin: 5, Left Motor Direction Pin: 4
// Right Motor PWM Pin: 7, Right Motor Direction Pin: 6

// Initialize motor control with default pins
AGVMotorControl motorControl;

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
```

## Documentation

See the header file and example sketches for detailed documentation.

## Author

- **Joel Devasia**  
  GitHub: [joeldevasia](https://github.com/joeldevasia)
