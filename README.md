# Hand-Controlled Wave Fabric — Group 17

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
**Hand-Controlled Wave Fabric** is an interactive kinetic textile installation that translates touchless human hand gestures into varying, organic wave motion across a fabric with a 3D-printed patterned surface. The installation consists of an acrylic translucent structural frame with a flexible TPU 3D-printed fabric resting directly above three differently shaped cam mechanisms, which are being rotated by three stepper motors in parallel. 

* **TPU 3D-Printed Textile:** BIANCA WRITE ON TOP OF THIS Printed in flexible thermoplastic polyurethane (TPU), the top surface combines elastic compliance with structural memory, enabling it to deform smoothly over the rotating cams beneath without tearing, snagging, or losing tension. 
* **Frame Enclosure:** ZHIRU WRITE HERE Constructed from laser-cut clear acrylic, the frame showcases the internal cam-and-stepper assembly as an integral visual element while rigidly aligning the three stepper motors beneath the textile.
* **3D printed parts and details:** ZHIRU WRITE HERE

> **[INSERT PHOTO: Clear hero photograph of the completed physical installation showing the transparent frame, the three differently shaped cams, and the TPU 3D-printed fabric on top]**

### User Interaction Model
Users interact with the kinetic surface around 40cm away from the frame, where a webcam located in the frame records any user hand gesture. 
| Gesture Class | User Action | Physical & Visual Response on the Fabric |
| :---: | :--- | :--- |
| **1** | **No hand detected** | Neutral state. All three cams rotate slowly, producing a calm, continuous baseline ripple that signals the system is active. |
| **2** | **Open palm on far left** | Cam 1 accelerates while Cams 2 & 3 rotate slowly, causing a defined wave to be present concentrating wave energy on the left side of the textile. |
| **3** | **Open palm in centre** | Cam 2 accelerates (`600` steps/s) while Cams 1 & 3 rotate slowly, creating a central crest across the middle of the fabric. |
| **4** | **Open palm on far right** | Cam 3 accelerates (`600` steps/s) while Cams 1 & 2 rotate slowly, shifting the peak wave motion to the right side. |
| **5** | **Two hands raised** | All three cams rotate at full speed (`600` steps/s) simultaneously, generating rapid, multi-frequency interference waves across the entire surface. |
| **6** | **One index finger raised** | All three motors stop immediately and coil power is released, freezing the textile in place. |

---

## 2. Mechanical Design & Fabrication

Rather than modifying a standard multi-axis robot arm, we engineered a dedicated **three-cam kinetic actuation system** tailored specifically to convert continuous rotary motion into varied vertical and travelling wave profiles across a flexible TPU textile.

### Cam Mechanisms & Motion Transmission
* **Three Distinct Cam Profiles:** Three custom cams featuring **different lobe geometries and eccentric radii** are mounted directly onto the output shafts of three `28BYJ-48` stepper motors. Because each cam possesses a unique radial profile (varying lift height and lobe count per revolution), even when all three motors rotate at the same speed, they displace the TPU textile out of phase—creating complex, organic wave interference rather than uniform mechanical oscillation.
* **Direct Rotary-to-Surface Contact:** Smooth, low-friction cam perimeters press upward against the underside of the TPU printed fabric, translating continuous 360° stepper rotation into smooth vertical displacement without linkage backlash.
* **Why Stepper Motors Over Servo Motors:** Standard hobby servos are limited to 180° oscillatory sweeps and suffer from audible gear jitter at low speeds. Geared stepper motors controlled via the `AccelStepper` library enable uninterrupted 360° cam rotation and smooth, quiet velocity transitions.

### Materials & Fabrication Process
* **Transparent Frame:** Laser-cut clear acrylic panels (`[specify thickness, e.g., 5 mm / 6 mm]`) interlocked with precision mounting slots to hold the three stepper motors rigidly beneath the textile while maintaining complete visual transparency.
* **Custom Cams & Shaft Couplers:** 3D-printed in rigid PLA with keyed press-fit hubs matched to the flattened `5 mm` double-D shaft of the `28BYJ-48` stepper motors, preventing rotational slip under textile tension.
* **Flexible TPU Textile:** 3D-printed in flexible TPU filament (`[specify Shore hardness if known, e.g., 95A]`) and anchored along the upper perimeter of the transparent frame so the surface flexes cleanly over each cam peak and returns smoothly under its own elasticity.

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
