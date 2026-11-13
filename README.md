# Hand-Controlled Wave Fabric Group 17

**Team Members:** Andrea Spagnolo, Bingxian Zhong, Zhiru Niu  
**Course:** Cyber-Physical Systems (CPS)  
**Repository:** `group17-finalproject-cps`



## Table of Contents
1. [Overall Concept & User Interaction](#1-overall-concept--user-interaction)
2. [Mechanical Design & Fabrication](#2-mechanical-design--fabrication)
3. [Hardware Design, Wiring & Power Consumption](#3-hardware-design-wiring--power-consumption)
4. [Repository Structure & Software Pipeline](#4-repository-structure--software-pipeline)
5. [Step-by-Step Setup & Running Instructions](#5-step-by-step-setup--running-instructions)
6. [Machine Learning: Training, Evaluation & Reflection](#6-machine-learning-training-evaluation--reflection)
7. [Troubleshooting Guide](#7-troubleshooting-guide)
8. [External Sources & Libraries Cited](#8-external-sources--libraries-cited)



## 1. Overall Concept & User Interaction

### Design Concept & Materiality
Inspired by the unpredictability and movement of the ocean, our **Hand-Controlled Wave Fabric** is an interactive kinetic textile installation that translates touchless human hand gestures into varying, organic wave motion across a fabric with a 3D-printed patterned surface. 
Our intention to achieve a minimalistic yet elegant design drove our design choices; a laser-cut transparent acrylic translucent structural frame with a flexible TPU 3D-printed fabric resting directly above three groups of cams using two different shapes, each driven by its own stepper motor. We considered that this design would keep attention on the movement itself. 

The main structure measures approximately **60.2 cm wide × 43.9 cm long × 16.5 cm high** in CAD, excluding the webcam body and boat. Every material and structural choice was made to reinforce the core design concept:

- **Transparent Acrylic Frame:** Four laser-cut 5 mm clear acrylic walls sit in printed feet and are joined by inner corner brackets and M3 screws. The clear walls leave the three cam groups and their motors visible.
- **3D-Printed Flexible TPU Fabric:** Flexible TPU units are printed onto organza layered over stretch fabric. The cams lift the textile from below, creating gentle waves and shifting patterns of light and shadow.

Interaction is designed to be immediate and intuitive without wearables or physical contact. When no user is present, the fabric moves in a slow, continuous idle ripple. Moving an open palm across the left, centre, or right set threshold areas of the camera shifts the wave intensity to the corresponding section of the fabric, raising two hands drives all three sections at full speed resembling a 'storm', and raising a single index finger pauses the system.



<p align="center">
  <img src="Image/interaction_gif-ezgif.com-optimize.gif" alt="interaction_gif-ezgif.com-optimize" width="100%">
  <img src="Image/closer_gif-ezgif.com-optimize.gif" alt="closer_gif-ezgif.com-optimize" width="100%">
</p>

<img src="Image/closerviewtop2.png" alt="closerviewtop2" width="100%">

<p align="left">
  <img src="Image/closerview3.png" alt="closerview3" width="33%">
  <img src="Image/closerview2.png" alt="closerview2" width="33%">
  <img src="Image/closerview7.png" alt="closerview7" width="33%">
</p>




### User Interaction Model
Users interact with the kinetic surface around 40cm away from the frame, where a webcam located in the frame records any user hand gesture. 
![interaction_table_hd](Image/interaction_table_hd.png)


## 2. Mechanical Design & Fabrication

Three motor-driven shafts lift the textile from below. Each shaft carries 14 cams, with two cam profiles used across the three shafts. As the cams turn, the textile rises and falls under its own weight and elasticity.

For part named codes, see the [Parts Index](Image/Parts_Index.png). Down Below ⬇️

### Cam Mechanisms & Motion Transmission

- **Cam layout:** The two outer shafts, C and A, use E1 cams. The centre shaft, B, uses E2 cams. Each group has 14 cams, giving 42 in total. Their orientation changes along each shaft to stagger the lift across the textile.
- **Surface contact:** The cams are laser-cut from 4 mm birch plywood. Sanded edges and an additional fabric layer beneath the printed textile reduce rubbing.
- **Motor mounts:** Each `28BYJ-48` motor bolts to a translucent blue PLA hanger B1. The hanger clips over the motor-side wall, with coupling B2 pointing into the frame. `AccelStepper` controls continuous rotation and changes in speed.
- **Shafts and bearings:** Each shaft is a 40 cm acrylic rod with a nominal 5 × 5 mm square section. One end fits into coupling B2; the other fits into adaptor C3 inside a 687ZZ bearing C5. Collar C4 retains the bearing's inner race. C1 and C2 hold the bearing on the opposite wall.

![Frame, three cam groups and textile frame - CAD assembly](Image/Assembly_Overview.png)

### Fabrication

- **Frame and printed fittings:** Laser-cut walls A3-A6 from 5 mm clear acrylic. Feet A1 locate the walls, and inner brackets A2 join the corners. Print the motor hangers B1, couplings B2 and bearing parts C1-C4; assemble them as shown below.
- **Textile frame supports:** The four A1 feet support the enclosure. Upper corners D1-D4 raise the textile frame. The textile is sewn to D6, with D7 above it and a 2 mm spacer at each corner. Bridge D5 carries the webcam above the centre motor.
- **Flexible TPU Textile:** 
Designed in Grasshopper, the pattern varies the height and diameter of printed units to create a more natural wave-like appearance. Flexible TPU 90A units are printed onto organza layered over stretch fabric. Secured around the frame with enough slack to move, the textile rises and falls with the rotating cams.

1\. Parametric Generation

<p align="center">
  <img src="Image/grasshopper.png" alt="grasshopper" width="50%">
  <br>
  <img src="Image/grasshopper_3vies.png" alt="grasshopper_3vies" width="50%">
</p>




2\. 3D print Settings

a. Select the printer model and TPU filament, add a pause after layer 2, and slice the plate (The model files are available via the links in the attachment and on MakerWorld, as they are too large to upload directly).
<p align="center">
  <img src="Image/print_setting1.png" alt="print_setting1" width="48%">
</p>

b. Once layer 2 is complete, secure the fabric with magnets, then resume printing.
<p align="left">
  <img src="Image/printing1.png" alt="printing1" width="33%">
  <img src="Image/printing2.png" alt="printing2" width="33%">
  <img src="Image/printing3.png" alt="printing3" width="33%">
</p>


- **Frame to hold and tension fabric:** Holes around the frame allow the fabric to be stitched in place, with enough slack for the cams to lift and lower it freely. A top frame is then secured over the stitched frame with four screws to hold the assembly together.

<p align="center">
  <img src="Image/cam_perspective.jpg" alt="cam_perspective" width="33%">
  <img src="Image/sewing.jpg" alt="sewing" width="33%">
  <img src="Image/with_top_frame.jpg" alt="with_top_frame" width="33%">
</p>

   
#### Magnetic Boat

The boat F8 is printed in orange PETG. Glue Ø6 × 3 mm magnets into the pockets underneath, then place matching magnets below the textile with attracting poles facing each other. The boat moves with the fabric.

Hull adapted from [3DBenchy](https://www.3dbenchy.com/) by Daniel Norée / Creative Tools, with magnet pockets added underneath.

#### Mechanical Assembly

![Parts index](Image/Parts_Index.png)

##### 01-02 · Feet and acrylic walls

![Feet and acrylic walls](Image/Assembly_01_Feet_Walls.png)

##### 03-04 · Motors and bearings

![Motor and bearing assemblies](Image/Assembly_02_Drive_Bearing.png)

##### 05 · Cam order and orientation

![Cam order from motor to bearing](Image/Assembly_03_Cam_Sequence.png)

##### 05-06 · Shafts

![Thread the cams and mount the three shafts](Image/Assembly_04_Shafts.png)

##### 07-08 · Textile frame

![Fit the raised corners, sewn textile frame and cover](Image/Assembly_05_Textile_Frames.png)

##### 09-10 · Webcam and assembled view

![Install the webcam bridge and webcam](Image/Assembly_06_Webcam_Overview.png)

##### 11 · Boat

![Fit the boat magnets across the textile](Image/Assembly_07_Boat.png)

#### Manufacturing Files and Hardware

<details>
<summary>Print files, cutting files and hardware</summary>

**3D printing** · F8 uses orange PETG.

| Part | Qty | STL | 3DM |
|---|---|---|---|
| A1 | 4 | [A1.stl](Model/A1.stl) | [A1.3dm](Model/A1.3dm) |
| A2 | 4 | [A2.stl](Model/A2.stl) | [A2.3dm](Model/A2.3dm) |
| B1 | 3 | [B1.stl](Model/B1.stl) | [B1.3dm](Model/B1.3dm) |
| B2 | 3 | — | [B2.3dm](Model/B2.3dm) |
| C1 | 3 | [C1.stl](Model/C1.stl) | [C1.3dm](Model/C1.3dm) |
| C2 | 3 | [C2.stl](Model/C2.stl) | [C2.3dm](Model/C2.3dm) |
| C3 | 3 | [C3.stl](Model/C3.stl) | [C3.3dm](Model/C3.3dm) |
| C4 | 3 | [C4.stl](Model/C4.stl) | [C4.3dm](Model/C4.3dm) |
| D1 | 1 | [D1.stl](Model/D1.stl) | [D1.3dm](Model/D1.3dm) |
| D2 | 1 | [D2.stl](Model/D2.stl) | [D2.3dm](Model/D2.3dm) |
| D3 | 1 | [D3.stl](Model/D3.stl) | [D3.3dm](Model/D3.3dm) |
| D4 | 1 | [D4.stl](Model/D4.stl) | [D4.3dm](Model/D4.3dm) |
| D5 | 1 | [D5.stl](Model/D5.stl) | [D5.3dm](Model/D5.3dm) |
| F8 | 1 | [F8.stl](Model/F8.stl) | [F8.3dm](Model/F8.3dm) |

**Laser cutting** · Cut each file once.

| File | Material |
|---|---|
| [A3.dxf](Model/A3.dxf) | 5 mm clear acrylic |
| [A4.dxf](Model/A4.dxf) | 5 mm clear acrylic |
| [A5.dxf](Model/A5.dxf) | 5 mm clear acrylic |
| [A6.dxf](Model/A6.dxf) | 5 mm clear acrylic |
| [D6.dxf](Model/D6.dxf) · [D6.3dm](Model/D6.3dm) | 5 mm sheet |
| [D7.dxf](Model/D7.dxf) · [D7.3dm](Model/D7.3dm) | 5 mm plywood |
| [E1-E2_Layout_01.dxf](Model/E1-E2_Layout_01.dxf) | 4 mm birch plywood |
| [E1-E2_Layout_02.dxf](Model/E1-E2_Layout_02.dxf) | 4 mm birch plywood |

For the cam files, engrave `ENGRAVE_ID`; cut `CUT_LIGHTEN` and `0`.

**Mechanical hardware**

| Specification | Qty |
|---|---|
| M3 × 20 | 8 |
| M3 × 16 | 8 |
| M3 × 8 | 16 |
| M3 × 25 | 10 |
| M3 × 10 | 3 |
| M3 grub screw | 6 |
| M3 hex nut | 32 |
| M3 steel washer | 38 |
| M3 nylon washer | 8 |
| Ø7 / Ø3.4 × 2 mm spacer | 4 |
| 687ZZ bearing | 3 |
| Ø6 × 3 mm magnet | Up to 3 pairs |

</details>




## 3. Hardware Design, Wiring & Power Consumption

### Bill of Materials (Components & Justification)

| Component | Qty | Justification |
| :--- | :---: | :--- |
| **Arduino Nano Every** | 1 | 5V logic compatibility, and 12 available I/O pins (`D2–D5`, `D8–D11`, `A0–A3`) to drive all three stepper motors simultaneously. |
| **28BYJ-48 Stepper Motor (5V)** | 3 | Unipolar stepper motor which has internal `64:1` planetary gear, reduction delivering a high torque to lift the tensioned TPU textile smoothly over the cam shapes. |
| **ULN2003 Darlington Driver Board** | 3 | Acts as a power amplifier and electronic switchboard between the Arduino Nano and the motor. |
**USB-C Power Bank & Imperial DSDE Power Board** | 1 | Portable 5 V power bank connected via USB-C to the custom Imperial DSDE Power Board, providing regulated 5 V and 3.3 V breadboard rails, a physical ON/OFF slide switch, and selectable current limiting (`0.5 A` / `2 A`). |
| **Praktika HD USB Webcam (1280×720p)** | 1 | Wide-angle 720p sensor captures left, centre, and right interaction areas.

### Pin Wiring & Electrical Safety
- **Power Distribution (5 V Rail):** A portable USB-C power bank feeds the **Imperial DSDE Power Board**, which plugs directly into the breadboard power rails. The board's **5 V and GND pins** supply power to all three `ULN2003` stepper driver boards (the `3.3 V` rail is unused).
- **Common Ground:** The `GND` and `5V` pins on the Power Board area soldered on a veroboard, on the same rail as the `GND` and `5V` rails of all three `ULN2003` drivers and the Arduino Nano Every's `GND` pin.
- **Cam Motor 1 (Left):** Arduino `D2, D3, D4, D5` $\rightarrow$ ULN2003 #1 (`IN1–IN4`)
- **Cam Motor 2 (Centre):** Arduino `D8, D9, D10, D11` $\rightarrow$ ULN2003 #2 (`IN1–IN4`)
- **Cam Motor 3 (Right):** Arduino `A0, A1, A2, A3` $\rightarrow$ ULN2003 #3 (`IN1–IN4`)

<table border="0" cellpadding="5" cellspacing="0" width="100%">
  <tr>
    <td width="50%" align="center" valign="top">
      <img src="Image/pinout CPS.png" alt="Digital pinout circuit scheme, made in Fritzing" width="100%"><br>
      <em>Digital pinout circuit schema, made in Fritzing</em>
    </td>
    <td width="50%" align="center" valign="top">
      <img src="Image/electronics.jpeg" alt="Visual outcome of electronics pinout" width="100%"><br>
      <em>Visual outcome of electronics pinout</em>
    </td>
  </tr>
</table>

- **Electrical Safety**
  - **Current Limiting & Hardware Switch:** The Power Board includes a built-in current-limit jumper and an onboard OFF–ON slide switch for immediate hardware power cutoff.
  - **Coil De-Energising:** In Class 6 (All Stop) and automatically upon closing the Processing window, `disableOutputs()` cuts holding current to all twelve motor coils so the steppers do not overheat or drain the power bank when idle.

### Estimated Power Consumption
- **Single Motor Load:** Each `28BYJ-48` stepper motor draws approximately `200–240 mA` at `5 V` (`~1.1–1.2 W`) under cam load.
- 
<p align="center">
  <img src="Image/total power used calculation.jpeg" alt="Total estimated power consumption calculations" width="45%">
</p>



## 4. Software Design & Pipeline

The software pipeline runs autonomously without manual intervention once launched, using a **single unified Arduino sketch** that transitions smoothly across all six modes:

<p align="center">
  <img src="Image/pipeline.drawio.png" alt="Pipeline diagram" width="100%">
</p>

### Explanation of Each Software Stage
1. **`Python/hand_to_wekinator.py`:** This code was partially written by Claude Sonnet 5.5. This code captures mirrored HD webcam video and uses MediaPipe's `hand_landmarker.task` model to turn hand landmarks into 3 simple, normalised numbers (hand count, horizontal palm position, and open finger ratio). This keeps tracking reliable regardless of lighting or how far you stand from the camera. It also includes a 5-frame memory buffer (`two_hand_memory`) so brief tracking glitches don't interrupt two-hand gestures, and a centre-zone snap (`0.30 ≤ x ≤ 0.70`) that locks middle-screen hands cleanly into Class 3 before streaming the data to Wekinator over OSC (`/wek/inputs`, port `6448`).
2. **`Wekinator/WekinatorProjectfinal/`:** Configured with **3 inputs**, **1 output** using Wekinator's **All classifiers (default: k-Nearest Neighbour)** setting, and **6 classes**, it classifies incoming features in real time and sends the predicted class (`1`–`6`) over OSC (`/wek/outputs`, port `12000`).
3.  **`Processing/wave_fabric_bridge/wave_fabric_bridge.pde`:** This code was mostly written by Claude Sonnet 5.5. This code displays the active wave mode on screen and passes commands from Wekinator over USB to the Arduino Serial Monitor. To keep the movement smooth, it waits until Wekinator predicts the same gesture **3 frames in a row (`NEEDED = 3`)** before switching modes, preventing split-second camera glitches from making the motors twitch—and automatically sends `'6'` (`All Stop`) when you close the window so the motors turn off safely.
4. **`Arduino/waves_final/waves_final.ino`:** We used Claude Sonnet 5.5 to explain the AccelStepper library. We used the `AccelStepper` library to drive all three motors simultaneously without blocking the loop, it listens over USB (`9600` baud) for commands `'1'`–`'6'` from Processing and smoothly switches each cam between slow (`200` steps/s), fast (`600` steps/s), and stopped states (0).


### Instructions for How to Run
1. **Install Libraries:**
   - **Arduino IDE:** Install `AccelStepper` via *Sketch → Include Library → Manage Libraries...*.
   - **Processing:** Install `oscP5` via *Sketch → Import Library → Manage Libraries...*.
   - **Python 3:** Run `pip install opencv-python mediapipe python-osc` in your terminal.
2. **Upload Arduino Firmware:** Connect the Arduino Nano Every via USB, switch on the Imperial DSDE Power Board, and upload `Arduino/waves_final/waves_final.ino`.
3. **Start Wekinator:** Open `Wekinator/WekinatorProjectfinal/WekinatorProjectfinal.wekproj` in Wekinator and click **Run** (confirm Input port `6448` and Output port `12000`).
4. **Start Processing Connection:** Open `Processing/wave_fabric_bridge/wave_fabric_bridge.pde`, verify `"COM4"` matches your Arduino's serial port, and click **Run**.
5. **Start Python Tracker:** Open your terminal (or Command Prompt / VS Code terminal), move into the `Python` folder, and run the tracking script:
   ```bash
   cd Python
   python hand_to_wekinator.py



## 5. Machine Learning: Training, Evaluation & Reflection

ANDREA ADD WEKINATOR IMAGES

### Feature Engineering & Training Dataset

Python computes 3 normalised features (`/wek/inputs`) per frame:
1. **Hand Count Ratio:** `0.0` (0 hands), `0.5` (1 hand), or `1.0` (2 hands).
2. **Palm Centre X Coordinate:** Horizontal position of MediaPipe landmark `9` (`0.0` = far left, `0.5` = centre zone, `1.0` = far right).
3. **Extended Finger Ratio:** Count of raised fingers (index, middle, ring, pinky; each `1` if fingertip-to-wrist distance exceeds middle-joint-to-wrist distance) divided by `4.0` (`0.0` to `1.0`).

Using the Python MediaPipe camera model, approximately 1050 data units were trained for each of the 6 classes, considering hand distance from the camera itself, amount of people in the background and varying lighting conditions. (`Wekinator/WekinatorProjectfinal/current/currentData.arff`):
These 6 classes map directly to the physical wave behaviours defined in the **User Interaction Model (Section 1)**.

### Model Justification & Formal Performance Evaluation- ANDREA FINISH
- **Chosen Model:** Wekinator's **All classifiers (default — k-Nearest Neighbour, $k=1$)** configured with **3 inputs** and **1 discrete classifier output** across **6 classes**.
- **Model Justification:** As our 3 input features give each gesture a distinct numerical signature (for example, `0.25` finger ratio for Class 6 vs `1.00` for Classes 2–4, and `1.0` hand ratio for Class 5), k-NN ($k=1$) works especially well here. It compares live hand inputs to the closest example in our `7,200`-sample dataset, giving near-instant predictions without needing complex neural networks.
- **Comparison of Feature Preprocessing & Model Performance:**
  - *Baseline (Raw Unfiltered Coordinates):* In initial tests without feature stabilisation, hovering near the `x = 0.30` or `x = 0.70` zone borders caused frequent boundary flicker between Class 2, Class 3, and Class 4, while fast two-hand gestures occasionally dropped to 1 hand for a single frame.
  - *Refined Pipeline (Zone Snapping + Temporal Filtering):* Adding the centre-zone snap (`0.30 ≤ x ≤ 0.70`) and 5-frame two-hand memory buffer in Python, combined with a 3-frame debounce filter (`NEEDED = 3`) in Processing, eliminated false state transitions during live testing.
  - *Cross-Validation Accuracy:* `[Insert your exact percentage from Wekinator's "Evaluate" button here, e.g., "5-fold cross-validation in Wekinator achieved 98.7% classification accuracy across our 7,200-sample dataset, with confusion limited strictly to transitional frames between zones."]`

### Step-by-Step Guide to Train & Run the Model
1. Launch `Python/hand_to_wekinator.py` so `/wek/inputs` is actively streaming 3 features on port `6448`.
2. Open `Wekinator/WekinatorProjectfinal/WekinatorProjectfinal.wekproj` in Wekinator.
3. **To Run the Pre-Trained Model:** Click **Run** immediately—Wekinator loads `model0.xml` and begins outputting predictions on port `12000`.
4. **To Retrain for a New Camera Angle or Environment:**
   - Click **Delete All Examples** (if retraining from scratch).
   - Select Class **`1`**, hold **Start Recording** to capture ~1,200 examples with no user hands active (varying background movement and lighting), then stop.
   - Repeat for Classes **`2`** (left palm), **`3`** (centre palm), **`4`** (right palm), **`5`** (two hands), and **`6`** (one index finger), varying hand distance around `40 cm` during recording.
   - Click **Train**, optionally click **Evaluate** to verify cross-validation accuracy, and click **Run**.

### Limitations & Future Explorations
- **Discrete Speed Levels vs Continuous Control:** Using discrete classification restricts each cam to fixed slow (`200` steps/s) or fast (`600` steps/s) speeds. With more time, replacing discrete classification with Wekinator's **continuous Neural Network regression** outputs mapped to palm vertical height (`Y` coordinate) would enable smooth, proportional speed modulation across `0–800` steps/s.
- **Static Pose vs Dynamic Velocity:** The current 3-feature model evaluates single-frame hand positions rather than movement velocity over time; collecting sequential gesture data and adding frame-to-frame palm velocity features would allow the TPU textile to mirror the speed of a user's wave directly.
- **2D Occlusion & Extreme Angles:** MediaPipe can still lose finger accuracy when hands are tilted sharply toward the camera or overlap closely in two-hand mode; adding a wider-angle lens or multi-view calibration would reduce occlusion blind spots.
- **Integrated Lighting:** Adding diffused LEDs inside the transparent acrylic frame beneath the TPU fabric would accentuate the moving cam silhouettes and wave crests in low-light environments.


## 8. External Sources & Libraries Cited
### Declaration of AI Use

The six gesture–response diagrams in the Interaction Model section were created from the project's STL models using Python scripts generated with assistance from OpenAI Codex (OpenAI, 2026). 

The assembly guide illustrations were created from the project's CAD models with assistance from ChatGPT (OpenAI, 2026).
