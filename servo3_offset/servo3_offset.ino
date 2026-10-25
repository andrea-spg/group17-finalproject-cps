#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

const byte servo1_pin = A0;
const byte servo2_pin = A1;
const byte servo3_pin = A2;
const byte servo4_pin = A3;
const byte servo5_pin = A4;

// Servo 2 starts when servo 3 reaches this angle.
// Servo 1 starts when servo 3 reaches this angle.
const int start2Angle = 60;
const int start1Angle = 120;

void setup() {
  // Test servo 1 by itself.
  servo1.attach(servo1_pin);
  servo1.write(0);
  // delay(1000);
  // servo1.write(180);
  // delay(1000);
  // servo1.write(90);
  // delay(1000);
  // servo1.write(0);
  // delay(1000);

  // Test servo 2 by itself.
  servo2.attach(servo2_pin);
  servo2.write(0);
  delay(1000);
  servo2.write(180);
  delay(1000);
  servo2.write(90);
  delay(1000);
  servo2.write(0);
  delay(1000);

  // Test servo 3 by itself.
  servo3.attach(servo3_pin);
  servo3.write(0);
  // delay(1000);
  // servo3.write(180);
  // delay(1000);
  // servo3.write(90);
  // delay(1000);
  // servo3.write(0);
  // delay(1000);

  // Test servo 4 by itself.
  servo4.attach(servo4_pin);
  servo4.write(0);
  // delay(1000);
  // servo4.write(180);
  // delay(1000);
  // servo4.write(90);
  // delay(1000);
  // servo4.write(0);
  // delay(1000);

  // Test servo 5 by itself.
  servo5.attach(servo5_pin);
  servo5.write(0);
  // delay(1000);
  // servo5.write(180);
  // delay(1000);
  // servo5.write(90);
  // delay(1000);
  // servo5.write(0);
  // delay(1000);
}

void loop() {
  // Forward wave: servo 3 and servo 5 move together first.
  // Servo 2 moves next. Servo 1 and servo 4 move together last.
  for (int phase = 0; phase <= 180 + start1Angle; phase++) {
    servo3.write(constrain(phase, 0, 180));
    // Servo 5 is mounted opposite to Servo 3, so reverse its command.
    servo5.write(constrain(180 - phase, 0, 180));

    if (phase >= start2Angle) {
      int servo2Angle = constrain(phase - start2Angle, 0, 180);
      servo2.write(servo2Angle);
    }

    if (phase >= start1Angle) {
      servo1.write(constrain(phase - start1Angle, 0, 180));
      // Servo 4 is mounted opposite to Servo 1, so reverse its command.
      servo4.write(constrain(180 - (phase - start1Angle), 0, 180));
    }

    delay(25);
  }

  // All five servos are now at 180 degrees.
  delay(3000);

  // Reverse wave: servo 1 and servo 4 move together first.
  // Servo 2 moves next. Servo 3 and servo 5 move together last.
  for (int phase = 0; phase <= 180 + start1Angle; phase++) {
    servo1.write(constrain(180 - phase, 0, 180));
    // Inverted again for the reverse wave because Servo 4 is mounted opposite.
    servo4.write(constrain(phase, 0, 180));

    if (phase >= start2Angle) {
      int servo2Angle = constrain(180 - (phase - start2Angle), 0, 180);
      servo2.write(servo2Angle);
    }

    if (phase >= start1Angle) {
      servo3.write(constrain(180 - (phase - start1Angle), 0, 180));
      // Inverted again for the reverse wave because Servo 5 is mounted opposite.
      servo5.write(constrain(phase - start1Angle, 0, 180));
    }

    delay(25);
  }

  // All five servos are now at 0 degrees.
  delay(3000);
}
