# 🤖 Supermarket Assistant Robot using ROS

A mobile robotic assistant built with **ROS (Robot Operating System)** and **Arduino** to enhance the shopping experience by guiding customers and autonomously following them through the store. The robot integrates **blob detection**, **infrared and ultrasonic sensing**, and **low-level motor control** to navigate supermarket environments and carry items for customers.

---

## 🧠 Key Features

- 🔵 **Blob Tracking**: Uses **OpenCV** and camera feed to detect and follow a colored object (e.g., shopper’s guide marker).
- 🟢 **Range Sensing**: Combines **ultrasonic** and **infrared sensors** to detect obstacles and maintain safe distances.
- 🦿 **Low-Level Control**: Translates **ROS velocity commands (`cmd_vel`)** to servo motor signals using `i2cpwm_board` messages.
- 🧩 **ROS Integration**: Modular ROS nodes for **perception** (`blob_detector`, `range_detector`), **planning** (`chase_the_ball.py`), and **actuation** (`low_level_control_blob_chase.py`).

---

## 🛠️ Components Used

- **Arduino Uno** for range sensing and IR detection (`Infrared.ino`)
- **Raspberry Pi** / ROS-compatible PC to run ROS nodes and process camera input
- **Ultrasonic Sensor**, **Infrared Sensor**, **Camera**, **Servo Motors**

---

## 🗂️ ROS Topics

- `/blob/point_blob`
- `/dkcar/control/cmd_vel`
- `/servos_absolute`

---

## 🧭 System Architecture

1. **Color Tracking** via HSV filter using `range_detector.py`
2. **Blob Detection** with keypoint tracking in `blob_detector.py`
3. **Steering Logic** via `chase_the_ball.py` based on blob's position
4. **Motor Control** with `low_level_control_blob_chase.py` to convert velocity to PWM
5. **Infrared & Ultrasonic Sensing** handled on Arduino (`Infrared.ino`)

---

## 🛒 Outcome

- Enables **real-time following** of shoppers in a mock supermarket setting
- Demonstrates **end-to-end integration** of perception, control, and actuation using ROS
- Developed as part of the *Principles of Measurements and Sensors* course at **Amrita Vishwa Vidyapeetham**

---
