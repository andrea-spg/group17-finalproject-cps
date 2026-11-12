# Hand-Controlled Wave Fabric Group 17

**Team Members:** Andrea Spagnolo, Bingxian Zhong, Zhiru Niu  
**Course:** Cyber-Physical Systems (CPS)  
**Repository:** `group17-finalproject-cps`

---

## Table of Contents
1. [Overall Concept & User Interaction](#1-overall-concept--user-interaction)
2. [Mechanical Design & Fabrication](#2-mechanical-design--fabrication)
3. [Hardware Design, Wiring & Power Consumption](#3-hardware-design-wiring--power-consumption)
4. [Repository Structure & Software Pipeline](#4-repository-structure--software-pipeline)
5. [Step-by-Step Setup & Running Instructions](#5-step-by-step-setup--running-instructions)
6. [Machine Learning: Training, Evaluation & Reflection](#6-machine-learning-training-evaluation--reflection)
7. [Troubleshooting Guide](#7-troubleshooting-guide)
8. [External Sources & Libraries Cited](#8-external-sources--libraries-cited)

---

## 1. Overall Concept & User Interaction

### Design Concept & Materiality
Inspired by the unpredictability and movement of the ocean, our **Hand-Controlled Wave Fabric** is an interactive kinetic textile installation that translates touchless human hand gestures into varying, organic wave motion across a fabric with a 3D-printed patterned surface. 
Our intention to achieve a minimalistic yet elegant design drove our design choices; a laser-cut transparent acrylic translucent structural frame with a flexible TPU 3D-printed fabric resting directly above two differently shaped cam mechanisms, which are being rotated by three stepper motors in parallel. We considered that this design would keep attention on the movement itself. 

The complete installation measures `[XX cm]` wide, `[XX cm]` long, and `[XX cm]` high (ZHIRU). Every material and structural choice was made to reinforce the core design concept:

- **Transparent Acrylic Frame:** (ZHIRU WRITE HERE) Laser-cut clear acrylic exposes the three rotating cams and stepper motors on a side, making the mechanical motion an intentional part of the visual experience.
- **3D-Printed Flexible TPU Fabric:** (BIANCA WRITE HERE) Made from two flexible layers printed in thermoplastic polyurethane (TPU), the top surface turns the upward push of the cams beneath into soft, rolling waves that catch ambient light naturally.

Interaction is designed to be immediate and intuitive without wearables or physical contact. When no user is present, the fabric moves in a slow, continuous idle ripple. Moving an open palm across the left, centre, or right set threshold areas of the camera shifts the wave intensity to the corresponding section of the fabric, raising two hands drives all three sections at full speed resembling a 'storm', and raising a single index finger pauses the system.


> **[INSERT PHOTO: Clear hero photograph of the completed physical installation showing the transparent frame, the two differently shaped cams, and the TPU 3D-printed fabric on top]**

### User Interaction Model
Users interact with the kinetic surface around 40cm away from the frame, where a webcam located in the frame records any user hand gesture. 
| Gesture Class | User Action | Physical & Visual Response on the Fabric |
| :---: | :--- | :--- |
| **1** | **No hand detected** | Neutral state. All three cams rotate slowly, producing a calm, continuous baseline ripple that signals the system is active. |
| **2** | **Open palm on far left** | Cam 1 accelerates while Cams 2 & 3 rotate slowly, causing a defined wave to be present on the left side of the fabric. |
| **3** | **Open palm in centre** | Cam 2 accelerates while Cams 1 & 3 rotate slowly, creating a central crest across the middle of the fabric. |
| **4** | **Open palm on far right** | Cam 3 accelerates while Cams 1 & 2 rotate slowly, shifting the peak wave motion to the right side. |
| **5** | **Two hands raised** | All three cams rotate at full speed simultaneously, generating rapid and multi-frequency interference waves across the entire surface. This represents a 'storm'. |
| **6** | **One index finger raised** | All three motors stop immediately and coil power is released. |

---

## 2. Mechanical Design & Fabrication

Focusing on making our project mechanically simple and elegant, we engineered a dedicated **three-cam kinetic actuation system**, where continuous rotary motion is converted into varied vertical and travelling wave profiles across a flexible TPU textile. The mechanism reaches a fluid, organic deformation by combining two asymmetric rotary cams with a flexible 3D-printed TPU fabric whose own stretch and tensioned weight pull the surface back down into place after each cam pushes it upward.

### Cam Mechanisms, Motion Transmission & Compliant Fabric

### Cam Mechanisms & Motion Transmission

- **Two Distinct Cam Profiles:** Two custom cams featuring **different shapes and off-centre profiles** are mounted directly onto the 40cm acrylic rods, and then placed into the holders of three `28BYJ-48` stepper motors. As each cam has a unique radial profile due to their angled offsets and different heights, the rotation of these cams displace the TPU textile out of phase, mirroring the organic asymmetry and natural turbulence of the ocean instead of predictable, repetitive motion.

- **Direct Rotary-to-Surface Contact:** Smooth, wood laser-cut cam perimeters press upwards the underside of the TPU printed fabric, translating continuous 360° stepper rotation into smooth vertical displacement. Friction with the fabric was reduced by sanding the cams perimiters and adding an additional layer of fabric below the first TPU printed layers.

- **Three Stepper Motors:** Using geared stepper motors with the `AccelStepper` library allows full, continuous 360° cam rotation and smooth, quiet speed changes.

-* **Motor Alignment:** The stepper motors are mounted by pieces of 3D printed translucent blue PLA, where the motors are screwed. These pieces have a clip-on attachment to attach and remove the stepper motors from the sides of the acrylic frame. 

- **Rod and bearing rotation:** Each cam row is connected by a 40cm squared rod of dimensions 5mm x 5mm. This rod is fitted into...ZHIRU


BIANCA photos of fabric
ZHIRU PHOTOS OF FRAME

###Fabrication 

- * **3D printed parts connecting frame:** (ZHIRU WRITE HERE) BEARINGS, ETC

- **Top and bottom parts for frame elevation and to add fabric frame:** ..ZHIRU

* **Flexible TPU Textile:** (BIANCA) 3D-printed in flexible TPU filament (`[specify Shore hardness if known, e.g., 95A]`) and anchored along the upper perimeter of the transparent frame so the surface flexes cleanly over each cam peak and returns smoothly under its own elasticity.

* - - **Frame to hold and tension fabric:** ..BIANCA

> **[INSERT PHOTO / CAD RENDER: Close-up photograph or CAD assembly showing the three differently shaped cams mounted inside the transparent acrylic frame]**

---

## 3. Hardware Design, Wiring & Power Consumption

### Bill of Materials (Components & Justification)

| Component | Qty | Justification |
| :--- | :---: | :--- |
| **Arduino Nano Every** | 1 | Compact footprint, native 5V logic compatibility, and 12 available I/O pins (`D2–D5`, `D8–D11`, `A0–A3`) to drive all three stepper channels simultaneously. |
| **28BYJ-48 Stepper Motor (5V)** | 3 | Internal `64:1` planetary gear reduction delivers high torque (`~34.3 mN·m`) to lift the tensioned TPU textile smoothly over the cam lobes without skipping steps, with minimal acoustic noise. |
| **ULN2003 Darlington Driver Board** | 3 | Isolates the Arduino's GPIO pins from inductive coil currents and provides onboard phase LEDs for immediate hardware verification. |
| **External 5V DC Power Supply** | 1 | Dedicated `[e.g., 5V 2A]` power source prevents voltage sags and Arduino resets when all three cams spin at full speed (Class 5). |
| **USB Webcam (1280×720)** | 1 | Wide-angle 720p sensor captures left, centre, and right interaction zones clearly without cropping out two-hand gestures. |

### Pin Wiring & Circuit Connections

* **Cam Motor 1 (Left Zone):** Arduino `D2, D3, D4, D5` $\rightarrow$ ULN2003 #1 (`IN1–IN4`)
* **Cam Motor 2 (Centre Zone):** Arduino `D8, D9, D10, D11` $\rightarrow$ ULN2003 #2 (`IN1–IN4`)
* **Cam Motor 3 (Right Zone):** Arduino `A0, A1, A2, A3` $\rightarrow$ ULN2003 #3 (`IN1–IN4`)
* **Power & Common Ground:** External `5V+` connects to the `+` power rail of all three ULN2003 boards; external `GND` connects to all three ULN2003 `-` rails **and** the Arduino `GND` pin to maintain a shared logic reference.

> **[INSERT DIAGRAM: Circuit schematic showing the Arduino Nano Every, three ULN2003 driver boards, three 28BYJ-48 stepper motors, external 5V power supply, and common ground]**

### Estimated Power Consumption & Electrical Safety
* **Per-Motor Current Draw:** Each `28BYJ-48` stepper motor draws approximately `200–240 mA` at `5V` (`~1.1–1.2 W`) under cam load.
* **Peak System Power (Class 5 — All Three Cams at Full Speed):**
  $$I_{\text{total}} \approx (3 \times 240\text{ mA}) + 50\text{ mA (Arduino + driver LEDs)} = 770\text{ mA} \quad (\approx 3.85\text{ W at } 5\text{V})$$
* **Electrical & Thermal Safeguards:**
  * Powered via a regulated `[e.g., 5V 2A]` supply, providing more than `2.5×` current headroom above peak simultaneous load.
  * In **Class 6 (All Stop)** and automatically upon closing the Processing window, `disableOutputs()` cuts holding current to all twelve motor coils so the steppers remain cool while idle.
  * All wiring harnesses are routed neatly along the frame perimeter with strain relief so rotating cams cannot snag or abrade jumper connections.

---

## 4. Repository Structure & Software Pipeline

### Repository Layout
```text
group17-finalproject-cps/
├── Arduino/
│   └── waves_final/
│       └── waves_final.ino               # Unified Arduino Nano Every firmware (AccelStepper)
├── Processing/
│   └── wave_fabric_bridge/
│       └── wave_fabric_bridge.pde        # OSC-to-Serial bridge, UI monitor & 3-frame debouncer
├── Python/
│   ├── hand_to_wekinator.py              # MediaPipe hand tracker & OSC feature sender
│   └── hand_landmarker.task              # Pre-trained Google MediaPipe hand landmark model
├── Wekinator/
│   └── WekinatorProjectfinal/
│       ├── WekinatorProjectfinal.wekproj # Trained 6-class Wekinator project configuration
│       ├── inputConfig.xml               # 3 OSC inputs (/wek/inputs, port 6448)
│       ├── outputConfig.xml              # 1 discrete classifier output (/wek/outputs, port 12000)
│       └── current/                      # Saved training dataset (currentData.arff) & model weights
└── README.md                             # Complete project documentation
