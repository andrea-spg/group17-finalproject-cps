# CPS17 · Wave Machine

**Final mechanical build and illustrated assembly guide**  
Andrea Spagnolo · Bianca Zhong · Zhiru Niu  
English edition · 12 November 2026

Three rows of cams lift a flexible textile in sequence to create a moving wave surface. Each cam sits at a different recorded angle on its square rod. A webcam provides input to the team's separate gesture-control system. An orange PETG boat sits on the textile and is held in place by magnets across the fabric.

This README is the main entry point for the mechanical build. It contains the parts list, fabrication files, assembly instructions and reference checks. Electronics and final control code are documented separately by the team.

![Final assembly with orange PETG boat](assets/Assembly_Overview.png)

*The boat position, textile extent and webcam body in the illustration are schematic. They show how the parts relate, not a measured cloth shape or motion simulation.*

## Quick links

- [Final configuration](#final-configuration)
- [Parts index and manufacturing files](#parts-index-and-manufacturing-files)
- [Standard hardware](#standard-hardware)
- [Printing](#printing)
- [Laser cutting](#laser-cutting)
- [Assembly](#assembly)
- [Viewer](#viewer)
- [Validation and archive status](#validation-and-archive-status)
- [Printable assembly manual](docs/CPS17_Assembly_Manual_EN.pdf)
- [Printable parts index](docs/CPS17_Parts_Index_EN.pdf)

## Final configuration

| Item | Final build |
|---|---|
| Top corners | Four replacement brackets, **12 mm higher** than the original blue design |
| Upper cover | Plain plywood, **no engraving** |
| Left shaft, seen from the drive side | **C / Motor 3**, E1 outer profile, 14 cams |
| Centre shaft | **B / Motor 2**, E2 centre profile, 14 cams |
| Right shaft | **A / Motor 1**, E1 outer profile, 14 cams |
| Passive supports | Rounded bearing supports, one 687ZZ bearing per shaft |
| Webcam mount | **One D5 front bridge**, turned 180° outwards and fitted with double-sided tape |
| Rear middle support | Not fitted |
| Bottom structure | Slotted feet and inner corner brackets locate the four acrylic walls; no separate bottom frame |
| Boat | **F8, orange PETG**, existing model with three underside magnet pockets |

![Top-view position names, with the drive side at the bottom](assets/Position_Map.png)

**Orientation rule:** stand at the motor/drive side. Left to right is **C–B–A = motors 3–2–1**. In a top view, put the bearing side at the top and the motor side at the bottom: D1 top left, D2 top right, D3 bottom left, D4 bottom right.

## Parts index and manufacturing files

**One part, one code.** A1 in the drawing means `A1.stl`, `A1.3dm` and, where available, `A1.step`. There is no separate manufacturing numbering system. Existing part codes are retained so this edition remains comparable with earlier assembly work.

Standard screws, nuts, washers, frame spacers and magnets have **no part codes**. Their specifications are written directly beside the drawing and in the hardware table.

![Main parts index with pale-blue labels](assets/Parts_Index.png)

| Code | Part | Quantity | Files or supply |
|---|---|---|---|
| A1 | Slotted foot | 4 | [A1.stl](STL/A1.stl) · [A1.3dm](3DM/A1.3dm) · [A1.step](STEP/A1.step) |
| A2 | Inner corner bracket | 4 | [A2.stl](STL/A2.stl) · [A2.3dm](3DM/A2.3dm) · [A2.step](STEP/A2.step) |
| A3 | Front wall / drive side | 1 | [A3.dxf](DXF/A3.dxf) |
| A4 | Rear wall / bearing side | 1 | [A4.dxf](DXF/A4.dxf) |
| A5 | Left end wall | 1 | [A5.dxf](DXF/A5.dxf) |
| A6 | Right end wall | 1 | [A6.dxf](DXF/A6.dxf) |
| B1 | Motor hanger | 3 | [B1.stl](STL/B1.stl) · [B1.3dm](3DM/B1.3dm) · [B1.step](STEP/B1.step) |
| B2 | Drive coupling | 3 | [B2.stl](STL/B2.stl) · [B2.3dm](3DM/B2.3dm) · [B2.step](STEP/B2.step) |
| B3 | Stepper motor | 3 | Purchased: 28BYJ-48; match the actual voltage rating |
| B4 | Square acrylic rod | 3 | Existing nominal 5 × 5 mm acrylic rod; final length to record |
| C1 | Rounded bearing base | 3 | [C1.stl](STL/C1.stl) · [C1.3dm](3DM/C1.3dm) |
| C2 | Rounded bearing cap | 3 | [C2.stl](STL/C2.stl) · [C2.3dm](3DM/C2.3dm) |
| C3 | Passive rod adaptor | 3 | [C3.stl](STL/C3.stl) · [C3.3dm](3DM/C3.3dm) |
| C4 | Inner-race collar | 3 | [C4.stl](STL/C4.stl) · [C4.3dm](3DM/C4.3dm) |
| C5 | 687ZZ bearing | 3 | Purchased: 687ZZ, 7 × 14 × 5 mm |
| D1 | Top-left corner +12 mm | 1 | [D1.stl](STL/D1.stl) · [D1.3dm](3DM/D1.3dm) · [D1.step](STEP/D1.step) |
| D2 | Top-right corner +12 mm | 1 | [D2.stl](STL/D2.stl) · [D2.3dm](3DM/D2.3dm) · [D2.step](STEP/D2.step) |
| D3 | Bottom-left corner +12 mm | 1 | [D3.stl](STL/D3.stl) · [D3.3dm](3DM/D3.3dm) · [D3.step](STEP/D3.step) |
| D4 | Bottom-right corner +12 mm | 1 | [D4.stl](STL/D4.stl) · [D4.3dm](3DM/D4.3dm) · [D4.step](STEP/D4.step) |
| D5 | Front bridge / reversed | 1 | [D5.stl](STL/D5.stl) · [D5.3dm](3DM/D5.3dm) · [D5.step](STEP/D5.step) |
| D6 | Lower sewing frame | 1 | [D6.3dm](3DM/D6.3dm) · [D6.dxf](DXF/D6.dxf) |
| D7 | Plain cover frame | 1 | [D7.3dm](3DM/D7.3dm) · [D7.dxf](DXF/D7.dxf) |
| E1 | Outer cams / C and A | 28 | [Layout 01](DXF/E1-E2_Layout_01.dxf) · [Layout 02](DXF/E1-E2_Layout_02.dxf) |
| E2 | Centre cams / B | 14 | [Layout 01](DXF/E1-E2_Layout_01.dxf) · [Layout 02](DXF/E1-E2_Layout_02.dxf) |
| F1 | As-built textile | 1 | Final production STL/3MF still to be archived |
| F2 | PRAKTICA webcam | 1 | Purchased: PRAKTICA HD USB-A Webcam |
| F3 | Double-sided tape | As needed | Purchased: double-sided tape, as fitted |
| F4 | Shaft spacers | As built | As-built spacers; dimensions and cut list to record |
| F8 | Boat / orange PETG | 1 | [F8.stl](STL/F8.stl) · [F8.3dm](3DM/F8.3dm) · [F8.step](STEP/F8.step) |

E1 and E2 are stored together on two cutting layouts. `E1-E2_Layout_01.dxf` and `E1-E2_Layout_02.dxf` are sheet names, not extra part codes. The [original combined cam source](DXF/E1-E2_Source.dxf) is also retained. **Cut either the two layouts or your own nesting of the source; do not cut all three files.**

Machine-readable lists: [parts](data/Parts.csv), [print quantities](data/Print_Quantities.csv), [standard hardware](data/Standard_Hardware.csv), [cam assembly map](data/Cam_Assembly_Map.csv).

## Standard hardware

These quantities come from the source design and should be checked against the physical build. Screw lengths refer to the fastener specification, not a drawing code. Confirm the fitted head type and usable screw length before ordering replacements.

| Specification | Reference quantity | Use / note |
|---|---|---|
| M3 x 20 screw | 8 | Bottom connections; source design count. |
| M3 x 16 screw | 8 | Through-wall fixing; source design count. |
| M3 x 8 screw | 16 | 6 motor screws + 10 clamps; check actual fitted length. |
| M3 x 25 screw | 10 | 6 bearing-cap screws + 4 top-frame screws. |
| M3 x 10 screw | 3 | Rear inner-race collars. |
| M3 grub screw | 6 | Drive-hanger wall clamps; choose length to fit. |
| M3 hex nut | 32 | Source design count. |
| M3 steel washer | 38 | Source design count. |
| M3 nylon washer | 8 | Against acrylic walls. |
| 2 mm frame spacer | 4 | Between upper and lower frames. |
| Disc magnet / 6 x 3 mm | As fitted | 6 x 3 mm magnets. Up to 3 pairs; actual fitted quantity not yet recorded. |

The four frame spacers are nominally **OD 7 mm / ID 3.4 mm / thickness 2 mm**. Keep these separate from the as-built **F4 shaft spacers**, whose actual length, count and fixing method still need recording. The boat has capacity for three magnet pairs, but the number fitted in the final build has not been recorded.

## Printing

All dimensions are in **millimetres**. Print at **100% scale**. Each STL is a single part; use the quantities below. The package contains **14 STL designs, 32 printed objects in total including the boat**.

| File | Part | Print quantity |
|---|---|---|
| [A1.stl](STL/A1.stl) | Slotted foot | 4 |
| [A2.stl](STL/A2.stl) | Inner corner bracket | 4 |
| [B1.stl](STL/B1.stl) | Motor hanger | 3 |
| [B2.stl](STL/B2.stl) | Drive coupling | 3 |
| [C1.stl](STL/C1.stl) | Rounded bearing base | 3 |
| [C2.stl](STL/C2.stl) | Rounded bearing cap | 3 |
| [C3.stl](STL/C3.stl) | Passive rod adaptor | 3 |
| [C4.stl](STL/C4.stl) | Inner-race collar | 3 |
| [D1.stl](STL/D1.stl) | Top-left corner +12 mm | 1 |
| [D2.stl](STL/D2.stl) | Top-right corner +12 mm | 1 |
| [D3.stl](STL/D3.stl) | Bottom-left corner +12 mm | 1 |
| [D4.stl](STL/D4.stl) | Bottom-right corner +12 mm | 1 |
| [D5.stl](STL/D5.stl) | Front bridge / reversed | 1 |
| [F8.stl](STL/F8.stl) | Boat / orange PETG | 1 |

- **D1–D4 are complete +12 mm replacement corners.** Do not stack them on the original corners. Use each handed file in its named position; do not mirror it in the slicer.
- **D5 is printed once** and then turned outwards during assembly. Reverse installation is a physical rotation, not a mirrored print.
- **F8 is orange PETG**, matching the final build. For other printed parts, match the tested material and settings of the physical build.
- Final print profiles are not archived here. Check the slicer preview and chosen support settings before printing. A closed solid does not imply support-free printing or 100% infill.
- The **16 3DM files** contain the 14 printed models and the two top frames as closed Breps. The **10 STEP files** are optional exchange copies; STEP is not supplied for every part.

## Laser cutting

### Walls and textile frames

| Part / file | Nominal size | Material / quantity |
|---|---|---|
| [A3.dxf](DXF/A3.dxf) | 570 × 119 × 5 mm | Front wall, acrylic, 1 |
| [A4.dxf](DXF/A4.dxf) | 570 × 119 × 5 mm | Rear wall, acrylic, 1 |
| [A5.dxf](DXF/A5.dxf) | 376.4 × 119 × 5 mm | Left wall, acrylic, 1 |
| [A6.dxf](DXF/A6.dxf) | 376.4 × 119 × 5 mm | Right wall, acrylic, 1 |
| [D6.dxf](DXF/D6.dxf) | 564 × 300 mm, nominal 5 mm sheet | Lower sewing frame, 1 |
| [D7.dxf](DXF/D7.dxf) | 594 × 394 mm, nominal 5 mm sheet | Plain plywood cover, 1 |

Both textile frames have a **528 × 264 mm opening**. The cover leaves only **3 mm per side** on a 600 × 400 mm sheet; confirm the workshop's usable stock and machine area. Allow a separate sheet for each top frame. D7 is the unengraved final version.

### Two cam sheets

Use **600 × 400 × 4 mm laser birch plywood**, two sheets:

| Layout | Contents |
|---|---|
| [E1-E2_Layout_01.dxf](DXF/E1-E2_Layout_01.dxf) | C-01 to C-14, plus B-01 to B-07: 21 cams |
| [E1-E2_Layout_02.dxf](DXF/E1-E2_Layout_02.dxf) | A-01 to A-14, plus B-08 to B-14: 21 cams |

The layouts use translation only: original profiles, square holes, corrected phase relationships, ID strokes and entity types are preserved. No scaling or new kerf compensation has been applied. Minimum outside margin is 10 mm; the smallest measured part-to-part gap is approximately 4.65 mm.

![Two cam sheet layouts and position labels](assets/Cam_Layout_Map.png)

| DXF layer | Workshop operation | Entities in the complete cam set |
|---|---|---|
| `ENGRAVE_ID` | Mark / engrave first | 432 ID strokes |
| `CUT_LIGHTEN` | Cut internal lightening windows | 210 |
| `0` | Cut shaft holes, then outside outlines | 364 curve entities |

The complete set contains **42 outside profiles, 42 square holes and 210 lightening windows**. Several curve entities may form one closed outline, so entity counts are not part counts.

**Trial the shaft hole first.** The source square holes are nominally **4.90 mm**. The acrylic rod is nominally 5 × 5 mm; an earlier measurement was 5.28–5.32 mm. Measure the actual rods and cut a trial hole in the same 4 mm plywood. Ask the workshop to tune kerf for its machine and material before cutting the complete set.

[Original cam location map](assets/Cam_Source_Map.png) · [Exact position and phase table](data/Cam_Assembly_Map.csv)

## Assembly

Assemble with power off. The drawings are not to scale; use the CAD and DXF files for dimensions. Heavy dashed arrows indicate insertion or movement. Blue boxes identify custom/main parts; hardware callouts give the specification directly. `×3` or `×4` means repeat that operation.

### 01–02 · Feet and acrylic walls

![Feet, captive nuts and acrylic-wall assembly](assets/Assembly_01_Feet_Walls.png)

1. Turn each **A1** foot over. Insert **two M3 hex nuts** into the underside pockets.
2. Turn it back. Place **A2** on A1 and insert **two M3 × 20 screws with M3 steel washers** into the captive nuts. Leave slight adjustment room.
3. Lower the walls into the slots: **A3** at the motor side, **A4** at the bearing side, **A5/A6** at the left/right ends. Check the frame is square.
4. At each corner, fit **one M3 × 16 screw per wall**. Use a nylon washer against the acrylic, a steel washer under the screw head and an M3 nut inside. Tighten gently without bending the panel.

### 03–04 · Drive and rounded bearing modules

![Motor mounting and bearing module assembly](assets/Assembly_02_Drive_Bearing.png)

Build three drive modules and three bearing modules on the bench before mounting them to the walls.

1. Align the two **B3** motor tabs with **B1**. Fasten each motor with **two M3 × 8 screws, steel washers and M3 nuts**.
2. Align the bore of **B2** with the motor shaft and slide it on. The B1 wall slot hooks over the front wall; the coupling points inside the frame. Leave the **M3 grub screws** loose until alignment is complete.
3. Slide the round journal of **C3** through the inner race of the **C5 / 687ZZ bearing**. Fit **C4** at the rear and retain it with an **M3 × 10 screw**. The collar must contact only the inner race.
4. Seat the bearing's outer race in **C1**, then add **C2**. Tighten the two **M3 × 25 screws with steel washers and M3 nuts** evenly. Confirm the rotor still turns freely.

The rear retaining screw is easier to reach before hanging the bearing module on the wall.

### 05 · Cam sequence and orientation

![Individual E1 and E2 cam orientations in assembly order](assets/Assembly_03_Cam_Sequence.png)

- View each profile **from the motor end towards the bearing**.
- **01 is nearest the motor; 14 is nearest the bearing.**
- Repeat **E1-01 to E1-14** on both outer shafts, C and A.
- Use **E2-01 to E2-14** once on the centre shaft, B.
- Match both the square hole and the outside profile. A square hole permits four orientations; fitting it onto the rod does not establish the correct phase by itself.
- Preserve the recorded phases, including repeats and nonuniform increments. Do not substitute an evenly spaced angle sequence.

| Position from motor end | E1 phase on C and A | E2 phase on B |
|---|---|---|
| 01 | 0.0° | 0.0° |
| 02 | 10.0° | 10.0° |
| 03 | 20.0° | 20.0° |
| 04 | 30.0° | 30.0° |
| 05 | 40.0° | 40.0° |
| 06 | 50.0° | 50.0° |
| 07 | 60.0° | 60.0° |
| 08 | 70.0° | 90.0° |
| 09 | 80.0° | 100.0° |
| 10 | 90.0° | 110.0° |
| 11 | 90.0° | 120.0° |
| 12 | 100.0° | 130.0° |
| 13 | 80.0° | 140.0° |
| 14 | 90.0° | 150.0° |

The visual phase values are inherited from the approved assembly viewer. Use the illustrated profiles together with [Cam_Assembly_Map.csv](data/Cam_Assembly_Map.csv) to match a cut piece to its shaft and position. C-01/A-01 identify positions on the machine; E1-01 identifies the corresponding profile in this guide. These guide labels have not been added to the cutting DXF; existing engraved IDs are retained.

### 05–06 · Thread the cams and mount the shafts

![Threading square rods and lowering complete shaft modules onto the walls](assets/Assembly_04_Shafts.png)

1. Thread the cams and **F4 spacers** onto **B4** in the recorded order. Record spacer lengths and quantities from the existing build. Centre each cam pack under the textile opening.
2. Fit **B2** to the motor end and **C3** to the bearing end of each square rod. Check insertion depth and keep both ends adjustable.
3. Lower the complete front and rear mounts onto both wall edges together. Do not lock one end and bend the rod to fit the other.
4. Viewed from the drive side, install **C / Motor 3 on the left, B / Motor 2 in the centre, A / Motor 1 on the right**.
5. Align the couplings, check free rotation and then secure the drive hanger. In this context, Motor 1/2/3 identifies the motor, not a screw size.

### 07–08 · Raised corners and textile frames

![Four corner positions and exploded textile-frame assembly](assets/Assembly_05_Textile_Frames.png)

1. Place **D1 top left, D2 top right, D3 bottom left, D4 bottom right**, using a top view with the drive side at the bottom.
2. Insert an **M3 nut** into each top captive-nut pocket through the side opening. Seat the corner **20 mm** onto the wall.
3. Tap the **2.50 mm side holes to M3**, then use **M3 × 8 screws** to clamp the brackets to the walls.
4. Locate the sewn **F1 textile** on **D6**. Keep the **2 mm frame spacers** and add the plain **D7** cover.
5. At each corner, fit an **M3 × 25 screw with a steel washer** into the captive M3 nut. Tighten gradually and evenly without overstretching the textile.

D1–D4 are complete replacement brackets, already 12 mm higher than the original version. The frame-underside reference is **Z134** versus original **Z122**; nominal textile plane is **Z139**. The top locator lip is 3 mm high and locates the frame edge; it is not another height increase. The top through-hole is Ø3.40 mm.

### 09–10 · Reversed webcam bridge and final layout

![Reversed front bridge, taped webcam and final assembly](assets/Assembly_06_Webcam_Overview.png)

1. Use **one D5 at the front centre**. Rotate it **180° about the vertical axis**, keeping the top surface facing up. Do not turn it upside down or mirror the print.
2. Its two feet straddle the middle **B1** motor hanger and grip the **5 mm front acrylic wall**. Bridge engagement is 30 mm; the gap between its feet is 48 mm and the hanger width is 44 mm.
3. Secure the wall clamps with **two M3 × 8 screws**. Attach **F2 / PRAKTICA HD USB-A Webcam** to the platform using **F3 double-sided tape**.
4. Adjust the camera view and route its cable clear of the cams. No rear centre support is fitted in the final build.

Before adding the textile and boat, test free rotation on each shaft. Then test the final textile load on one axis at a time and finally on all three. Recheck any rubbing, vibration or missed steps. Electronics and final power/control instructions belong to the team's separate documentation.

### 11 · Orange PETG boat and magnets

![Orange boat underside pockets and magnets paired across the textile](assets/Assembly_07_Boat.png)

**F8** is approximately **60 × 31 × 48 mm**, printed in **orange PETG**. The existing hull has three underside blind pockets, each **Ø6.30 mm × 3.20 mm deep**, for **Ø6 × 3 mm disc magnets**. The pocket centres in the source model are X = −17, −5 and 7 mm; Y = 0. The entry chamfer is 0.20 mm at 45°, with a Ø6.70 mm mouth.

1. Dry-fit the magnets. A nominal 3 mm-thick magnet seats about **0.20 mm below** the bottom face. Use a small amount of suitable adhesive; do not force an undersized printed pocket.
2. Check attracting polarity before gluing. Keep magnet faces recessed or flush and remove sharp print edges.
3. Place matching magnets below the textile. Start with one pair and use only the pairs needed. Capacity is three pairs; the final fitted quantity still needs recording.
4. Turn the cams slowly by hand and check that the lower magnets clear all cams, rods and frame edges. Recheck the added motor load at low speed.

The magnets locate the boat on the textile so it can rise, fall and tilt. They do not provide forward propulsion. The assembly illustrations are not a fabric or magnetic-force simulation.

The hull is based on **3DBenchy by Daniel Norée / Creative Tools**. See [boat source and model notes](docs/Boat_Model_Notes.md) for retained attribution, source links and the original geometry report.

## Viewer

Download the complete folder and open **[CPS17_Viewer.html](viewer/CPS17_Viewer.html)** in a desktop browser. The HTML includes its geometry and viewer code. The README links to the program; its interactive controls run in the browser, not inside the Markdown text.

| Action | Control |
|---|---|
| Orbit | Drag |
| Pan | Shift-drag or right-drag |
| Zoom | Scroll wheel |
| Select a part | Click the model or choose from the part list |
| Inspect with surrounding parts | Focus |
| Inspect one part alone | Isolate |
| Separate / reassemble | Explode / Assemble or explosion slider |
| Inspect the mechanism | Uncover mechanism |
| Restore the complete view | As built |
| Inspect shaft movement | Shaft-angle slider or Rotate cams |

The camera, tape, textile extent and boat position are illustrative. The viewer boat mesh is simplified for performance; the manufacturing STL/3DM/STEP are unchanged. The viewer is not a collision, cloth, load or magnetic-force simulation. Its labels use the same main part codes as this README.

## Validation and archive status

### Manufacturing files

- **14 STL files:** closed/watertight, one connected component each, consistent winding.
- **16 3DM files:** one valid closed Brep each; no mesh objects.
- **9 DXF files:** retained structure/audit checks report no errors or repairs.
- **10 STEP files:** nine base-part reports are retained. The boat STEP is an exchange copy; a new independent STEP validation is not claimed.
- The two nested cam sheets retain all **1,006 source entities exactly once**.
- This revision changes filenames and documentation only. Manufacturing file hashes match the preceding English pack. Renaming does not change the geometry or the validity of its retained checks.

See [validation summary](checks/Validation_Summary.json), [base STL/3DM checks](checks/Closed_Solid_Checks.json), [boat closure checks](checks/Boat_Closed_Geometry_Check.json), [DXF checks](checks/DXF_Checks.json), [cam nesting checks](checks/Cam_Nesting_Checks.json) and [manufacturing hashes](checks/Manufacturing_File_Hashes.json).

These checks establish closed topology and file structure. They are not a new strength analysis, exhaustive global self-intersection audit, fit test or magnetic-force test. The boat's retained source report notes a local CAD seam residual up to approximately 0.142 mm; see [the original pocket and seam report](checks/Boat_Source_Pocket_and_Seam_Check.json).

### Still to add to the final project archive

- The actual **F1 textile-production STL/3MF** and its print settings.
- Final **B4 rod lengths**, **F4 spacer cut list**, spacer count and fixing method.
- Tested material grades, slicer settings, laser settings and kerf trial result.
- The physical hardware inventory and the fitted number of magnet pairs.
- The team's separate electronics and final gesture/control-code documentation.

These are open archive items, not supplied manufacturing files. This mechanical pack does not claim to include them.

### Folder contents

| Folder / file | Purpose |
|---|---|
| `README.md` | Main illustrated project and assembly guide |
| `STL/` | Printable parts, named by the manual code |
| `3DM/` | Closed Brep models, using the same codes |
| `STEP/` | Available exchange models, using the same codes |
| `DXF/` | Wall/frame profiles and combined cam layouts |
| `assets/` | Assembly diagrams, naming sheet and layout maps |
| `data/` | CSV lists and cam phase/position mapping |
| `viewer/` | Offline English assembly viewer |
| `docs/` | Optional printable PDFs and boat provenance |
| `checks/` | Geometry, nesting and archive verification records |
| `FILE_INDEX.txt` / `SHA256SUMS.txt` | File inventory and integrity hashes |

Keep this folder structure intact so the relative links and pictures work. For GitHub, upload the **extracted contents together**, with `README.md` at the repository root. The Markdown text, tables and links remain editable; the PDF is an optional print companion. The diagrams use Inter with pale-blue accents; GitHub controls the font of the Markdown body.
