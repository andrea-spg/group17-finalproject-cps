"""
Group 17 - Andrea Spagnolo, Bingxian Zhong, Zhiru Niu
CPS - Hand-Controlled Wave Fabric
Software: Python (MediaPipe Hand Tracking -> Wekinator OSC)

HOW IT WORKS:
1. Captures webcam video, flips it horizontally (mirror view), and tracks up to 2 hands
   using MediaPipe's hand_landmarker.task model.
2. Extracts 3 normalised features per frame and sends them to Wekinator (/wek/inputs, port 6448):
   - Input 1: Number of hands detected (0.0 = none, 0.5 = 1 hand, 1.0 = 2 hands)
   - Input 2: Palm horizontal X position (0.0 = left, 0.5 = centre, 1.0 = right)
   - Input 3: Extended fingers ratio (0.0 to 1.0 across index, middle, ring, pinky)
3. Press 'q' in the video window to quit cleanly.
"""

import cv2
import mediapipe as mp
from mediapipe.tasks import python as mp_python
from mediapipe.tasks.python import vision
from pythonosc.udp_client import SimpleUDPClient

wek = SimpleUDPClient("127.0.0.1", 6448)  # Send 3 OSC inputs to Wekinator on port 6448
FINGERS = [(8, 6), (12, 10), (16, 14), (20, 18)]  # (tip, middle joint) landmark pairs


def finger_up(hand, tip, joint):
    # Returns 1 if fingertip is further from the wrist (landmark 0) than its middle joint
    wrist = hand[0]
    d_tip = (hand[tip].x - wrist.x) ** 2 + (hand[tip].y - wrist.y) ** 2
    d_joint = (hand[joint].x - wrist.x) ** 2 + (hand[joint].y - wrist.y) ** 2
    return int(d_tip > d_joint)


# Initialise MediaPipe Hand Landmarker (requires hand_landmarker.task in the same folder)
options = vision.HandLandmarkerOptions(
    base_options=mp_python.BaseOptions(model_asset_path="hand_landmarker.task"),
    num_hands=2,
)
detector = vision.HandLandmarker.create_from_options(options)

# Try external USB webcam indices (2, 0) before falling back to built-in laptop camera (1)
cap = None
for cam_idx in [2, 0, 1]:
    temp_cap = cv2.VideoCapture(cam_idx, cv2.CAP_DSHOW)
    if not temp_cap.isOpened():
        temp_cap = cv2.VideoCapture(cam_idx)
    if temp_cap.isOpened():
        cap = temp_cap
        print(f"Connected to Camera index {cam_idx}")
        break

if cap is None:
    raise SystemExit("Could not open any camera. Check connection or close other apps using it.")

# Set 1280x720 widescreen resolution and full-screen display window
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
cv2.namedWindow("Hand", cv2.WINDOW_NORMAL)
cv2.setWindowProperty("Hand", cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_FULLSCREEN)

two_hand_memory = 0  # Holds 2-hand state for 5 frames to bridge brief tracking drops

while True:
    ok, frame = cap.read()
    if not ok:
        print("Failed to grab frame from camera.")
        break

    frame = cv2.flip(frame, 1)
    h, w, _ = frame.shape
    rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    hands = detector.detect(mp.Image(image_format=mp.ImageFormat.SRGB, data=rgb)).hand_landmarks

    # Smooth 2-hand detection so brief 1-frame drops do not interrupt Class 5
    raw_n = len(hands)
    two_hand_memory = 5 if raw_n == 2 else max(0, two_hand_memory - 1)
    n = 2 if two_hand_memory > 0 else raw_n

    if not hands:
        features = [0.0, 0.5, 0.0]
        text = "no hand"
    else:
        hand = hands[0]
        raw_x = hand[9].x  # Palm centre X (0 = left, 1 = right)
        count = sum(finger_up(hand, t, j) for t, j in FINGERS)

        # Snap X to 0.50 when 1 hand is inside the centre zone to stabilise Class 3
        x = 0.50 if (n == 1 and 0.30 <= raw_x <= 0.70) else raw_x
        features = [n / 2.0, x, count / 4.0]
        text = f"hands {n}   x {x:.2f}   fingers {count}"

        for hd in hands:
            for lm in hd:
                cv2.circle(frame, (int(lm.x * w), int(lm.y * h)), 4, (0, 255, 0), -1)

    wek.send_message("/wek/inputs", features)

    # Draw vertical zone dividers (left / middle / right thirds) and status overlay
    cv2.line(frame, (w // 3, 0), (w // 3, h), (255, 255, 0), 1)
    cv2.line(frame, (2 * w // 3, 0), (2 * w // 3, h), (255, 255, 0), 1)
    cv2.putText(frame, text, (10, h - 15), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 255), 2)

    cv2.imshow("Hand", frame)
    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

cap.release()
cv2.destroyAllWindows()