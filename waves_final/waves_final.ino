/*
  Group 17 - Andrea Spagnolo, Bingxian Zhong, Zhiru Niu 
  CPS - Hand-Controlled Wave Fabric
  Board: Arduino Nano Every
  Library: AccelStepper
  Motors: 3 x 28BYJ-48 steppers on ULN2003 driver boards

HOW IT WORKS
Processing sends Arduino one character over USB serial (9600 baud) each time the gesture class
changes, and this sketch turns that specific class into a speed for each of the 3 motors:

    '1' no hand (neutral):  all three motors move slowly
    '2' palm far left:      motor 1 fast, motors 2 and 3 slow
    '3' palm middle:        motor 2 fast, motors 1 and 3 slow
    '4' palm far right:     motor 3 fast, motors 1 and 2 slow
    '5' two hands:          all three motors fast
    '6' one finger:         all three motors stop and their coils are switched off

  Speeds are in steps per second. The motor shaft needs 2048 steps for one
  revolution, so RPM = steps per second x 60 / 2048:
    130 steps/s is about 3.8 RPM (slow)
    500 steps/s is about 14.6 RPM (fast)
*/

#include <AccelStepper.h>

// Exact pin order required for full torque (IN1, IN3, IN2, IN4)
AccelStepper motor1(AccelStepper::FULL4WIRE, 2, 4, 3, 5); 
AccelStepper motor2(AccelStepper::FULL4WIRE, 8, 10, 9, 11);
AccelStepper motor3(AccelStepper::FULL4WIRE, A0, A2, A1, A3);

// Speed presets in steps/second (0 = stop and disable outputs)
const float Slow_SPEED = 100.0; // used in class 1 (all slow) and for the slower motors in classes 2-4
const float Fast_SPEED    = 500.0; // used for the fast motor in classes 2-4, and for all motors in class 5

// Tracks the active gesture class (1-6). Starts at 0 so applyMode(1) always runs on startup.
int currentMode = 0;

// Sets speed for one motor and disables coil outputs when stopped to save power bank current.
void setMotorSpeed(AccelStepper & motor, float speed) {
  if (speed <= 0.0) {
    motor.setSpeed(0); // stop stepping
    motor.disableOutputs(); // switch all four coil pins off (0 mA current draw)
  } else {
    motor.enableOutputs(); // Re-energize coils before moving
    motor.setSpeed(speed); // Set target speed in steps/second
  }
}

//Function that sets the speeds of all 3 motors at once
// s1: motor 1, s2:motor 2, s3: motor 3.
void setSpeeds(float s1, float s2, float s3) {
  setMotorSpeed(motor1, s1);
  setMotorSpeed(motor2, s2);
  setMotorSpeed(motor3, s3);
}

// Updates motor speeds only when a new valid gesture class arrives.
void applyMode(int mode) {
  if (mode < 1 || mode > 6) return; // Ignores invalid characters or line endings (\n, \r)
  if (mode == currentMode) return; // Exit immediately if already in this mode to save CPU time

  switch (mode) {
    case 1: // Neutral (no hand): all move slowly
      setSpeeds(Slow_SPEED, Slow_SPEED, Slow_SPEED);
      break;

    case 2: // Palm far left: motor 1 fast, others slow
      setSpeeds(Fast_SPEED, Slow_SPEED, Slow_SPEED);
      break;

    case 3: // Palm middle: motor 2 fast, others slow
      setSpeeds(Slow_SPEED, Fast_SPEED, Slow_SPEED);
      break;

    case 4: // Palm far right: motor 3 fast, others slow
      setSpeeds(Slow_SPEED, Slow_SPEED, Fast_SPEED);
      break;

    case 5: // Two hands: all move fast
      setSpeeds(Fast_SPEED, Fast_SPEED, Fast_SPEED);
      break;

    case 6: // One finger: stop all motors and cut coil current
      setSpeeds(0, 0, 0);
      break;
  }

  currentMode = mode;
  Serial.print(F("Mode: "));
  Serial.println(currentMode);
}


void setup() {
  Serial.begin(9600);

 // Set the maximum speed limit to the highest active preset
  float speedLimit = max(Slow_SPEED, Fast_SPEED);
  motor1.setMaxSpeed(speedLimit);
  motor2.setMaxSpeed(speedLimit);
  motor3.setMaxSpeed(speedLimit);

  // Default to Mode 1 (Neutral state) on startup
  applyMode(1);
  Serial.println(F("Ready. Send 1-6."));
}


void loop() {
  // Checks for incoming serial commands from Processing
  if (Serial.available() > 0) {
    char received = Serial.read();
  // Convert ASCII character ('1'-'6') to integer (1-6)
    if (received >= '1' && received <= '6') {
      applyMode(received - '0');
    }
  }

  // Checks if each motor has a non-zero speed before sending step pulses.
  // Skipping stopped motors saves processor time so moving motors spin smoothly.
  if (motor1.speed() != 0.0) motor1.runSpeed();
  if (motor2.speed() != 0.0) motor2.runSpeed();
  if (motor3.speed() != 0.0) motor3.runSpeed();
}