/*
  Group 17 - Andrea Spagnolo, Bingxian Zhong, Zhiru Niu
  CPS - Hand-Controlled Wave Fabric
  Software: Processing (Bridge between Wekinator OSC and Arduino Serial)

  HOW IT WORKS:
  1. Listens on UDP port 12000 for classification outputs ("/wek/outputs") from Wekinator.
  2. Filters out single-frame prediction flickers by requiring the same class 3 times
     in a row (NEEDED = 3) before accepting a state change.
  3. Sends the confirmed gesture class ('1' to '6') over USB Serial (9600 baud) to the
     Arduino Nano Every and highlights the active mode in the UI window.
*/

import oscP5.*;
import netP5.*;
import processing.serial.*;

OscP5 wekOsc;
Serial arduino;

int activeClass = 0;       // the stable class that is sent to the Arduino
int candidate = 0;         // The latest raw class prediction arriving from Wekinator
int candidateCount = 0;    // how many times in a row it reported this class

int NEEDED = 3;       // Consecutive matching reports required before switching class

// Labels matching the 6 gesture cases in the Arduino sketch for UI
String[] names = {
  "No hand: all move slowly",
  "Palm far left: motor 1 faster",
  "Palm middle: motor 2 faster",
  "Palm far right: motor 3 faster",
  "2 hands: all full speed",
  "1 finger: all stop"
};

void setup() {
  size(720, 470);
  wekOsc = new OscP5(this, 12000); // Listen for Wekinator OSC messages on port 12000

  arduino = new Serial(this, "COM4", 9600);
  delay(2000);   // Wait 2s for Arduino Nano Every auto-reset on serial connect
}

// Updates the active state and transmits the new class character ('1'-'6') to Arduino
void sendClass(int c) {
  activeClass = c;
  println("class " + c);
  arduino.write(str(c));
}

// Triggered automatically whenever Wekinator sends an OSC message
void oscEvent(OscMessage m) {
  if (!m.checkAddrPattern("/wek/outputs")) return; // Ignores any unrelated OSC messages
  int c = round(m.get(0).floatValue()); // Extract predicted class number
  if (c < 1 || c > 6) return; // Ignores out-of-range values

  // Wait for Wekinator to report the same gesture 3 times in a row before trusting it.
  // This ignores brief 1-frame camera glitches so the motors don't twitch randomly.
  if (c == candidate) {
    candidateCount++; // Same gesture as the previous message: add 1 to the count
  } else {
    candidate = c; // Different gesture detected: start tracking this one instead
    candidateCount = 1; // Reset the count back to 1
  } // Only send to Arduino once the prediction is stable AND different from the current mode
  if (candidateCount >= NEEDED && c != activeClass) sendClass(c);
}

void draw() {
  background(24);
  // Draw 6 status cards; highlight the currently active class in green
  for (int i = 0; i < 6; i++) {
    fill(activeClass == i + 1 ? color(40, 170, 90) : color(48));
    noStroke();
    rect(30, 30 + i * 70, 660, 58, 8);
    fill(255);
    textSize(20);
    text((i + 1) + "   " + names[i], 50, 66 + i * 70);
  }
}

// Safely stops all motors and cut coil power ('6') when closing the Processing window
void exit() {
  arduino.write("6");   // all motors stop
  super.exit(); // Finish Processing's normal shutdown and close the window
}
