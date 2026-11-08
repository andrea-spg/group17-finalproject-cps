/*
  Group 17 - Cyber Physical Systems - Andrea Spagnolo, Bingxian Zhong, Zhiru Niu
  Project name: Hand-Controlled Wave Fabric
  Board:   Arduino Nano Every
  Library: AccelStepper
  Motors:  3 x 28BYJ-48 steppers on ULN2003 driver boards (see README pin table)

  HOW IT WORKS
  Processing sends Arduino one character over USB serial (9600 baud) whenever the
  gesture class changes, and this sketch turns that class into different motor speeds:

    '1' neutral state(no hand):  all motors move equally, at a slow speed
    '2' palm placed in far left: motor 1 fastest, motors 2 and 3 slower
    '3' palm placed in the middle: motor 2 fastest, motors 1 and 3 slower
    '4' palm placed in the far right: motor 3 fastest, motors 1 and 2 slower
    '5' two hands up: all motors fast
    '6' one finger: all motors stop

  Speeds are in steps per second (2048 steps = 1 revolution of the output shaft,
  so 250 steps/s is about 7.3 RPM and 70 steps/s is about 2.1 RPM).
*/

#include <AccelStepper.h>

// DEBUG switch: set to true ONLY when testing with the Serial Monitor, so the
// Arduino prints the class it received. Turned to true when testing, but keeping it false 
// during the demo, because Processing is using the serial port.
const bool DEBUG = false;

// The four pins are listed in the order the motor's coils must be energised.
AccelStepper motor1(AccelStepper::FULL4WIRE, 8, 10, 9, 11);
AccelStepper motor2(AccelStepper::FULL4WIRE, A0, A1, A2, A3);
AccelStepper motor3(AccelStepper::FULL4WIRE, 2, 3, 4, 5);

// currentClass remembers the last class received (1 to 6). Processing only sends
// a character when the class changes.
int currentClass = 1; //Current class when initiated is 1 - neutral state, motors move slowly after power-up

void setup() {
  Serial.begin(9600);    // start serial communication

  // Allows the sketch switch switch the LED on and off. It is used below as a "message received" light.
  //Used for debugging and visually noting a change of state. 
  pinMode(LED_BUILTIN, OUTPUT);

  // The fastest each motor is allowed to go (steps per second). 
  // Tested maximum speed for all 3 motors to rotate together reliably on the power bank.
  motor1.setMaxSpeed(250);
  motor2.setMaxSpeed(250);
  motor3.setMaxSpeed(250);
}


void loop() {

  // 1. LISTEN: Check if Processing has sent a new class over serial
  // Serial.available() is true when at least one character is waiting to be read.
  if (Serial.available()) {
    char received = Serial.read();    // read one character, e.g. '3'
    int newClass = currentClass;      // keep the old class unless a new and valid one is recieved

    // The data arrives as a text CHARACTER, so we compare with '1'.
    if (received == '1') newClass = 1;
    if (received == '2') newClass = 2;
    if (received == '3') newClass = 3;
    if (received == '4') newClass = 4;
    if (received == '5') newClass = 5;
    if (received == '6') newClass = 6;

    // Only react when the class has actually changed.
    if (newClass != currentClass) {
      currentClass = newClass;

    // Allows the sketch switch switch the LED on and off. It is used below as a "message received" light.
    //Used for debugging and visually noting a change of state by flipping the on-board LED every new class.  
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

      // Only in debug mode: print the class to the Serial Monitor.
      if (DEBUG) {
        Serial.print("class ");
        Serial.println(currentClass);
      }
    }
  }

  // 2. DECIDE: 6 cases in switch function to set each motor's speed depending on the class.
  switch (currentClass) {

    case 1:   // no hand (neutral): all move slowly
      motor1.setSpeed(70);
      motor2.setSpeed(70);
      motor3.setSpeed(70);
      break;

    case 2:   // palm far left: motor 1 fastest, the others slower
      motor1.setSpeed(250);
      motor2.setSpeed(90);
      motor3.setSpeed(90);
      break;

    case 3:   // palm middle: motor 2 fastest, the others slower
      motor1.setSpeed(90);
      motor2.setSpeed(250);
      motor3.setSpeed(90);
      break;

    case 4:   // palm far right: motor 3 fastest, the others slower
      motor1.setSpeed(90);
      motor2.setSpeed(90);
      motor3.setSpeed(250);
      break;

    case 5:   // two hands: all three at full speed
      motor1.setSpeed(250);
      motor2.setSpeed(250);
      motor3.setSpeed(250);
      break;

    case 6:   // one finger: all stop
      motor1.setSpeed(0);
      motor2.setSpeed(0);
      motor3.setSpeed(0);
      break;
  }

  // 3. MOVE: runSpeed() takes one step IF the time for the next step has come, at the
  // speed set above. 
  motor1.runSpeed();
  motor2.runSpeed();
  motor3.runSpeed();
}
