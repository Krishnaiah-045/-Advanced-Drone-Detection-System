🚁 Advanced Drone Detection using CNN with ESP32
📌 Overview

An AI-powered drone detection system using a Convolutional Neural Network (CNN) integrated with ESP32 and ESP32-CAM. When a drone is detected, the system moves a servo motor, activates a buzzer, and stores detection data on an IoT server for remote monitoring.

✨ Features

Real-time drone detection using CNN

ESP32-CAM based image capture

Servo motor activation on detection

Buzzer alert for instant warning

Detection logs uploaded to IoT server

Low-cost embedded AI solution

🛠 Hardware Used

ESP32 Microcontroller

ESP32-CAM

Servo Motor

Buzzer

Power Supply

💻 Software & Technologies

Embedded C / C++

Arduino IDE / PlatformIO

CNN (Drone Detection Model)

Python (Model Training)

IoT Server (HTTP / MQTT based)

⚙️ Working Flow

ESP32-CAM captures live images

CNN detects drone presence

On detection:

Servo motor is triggered

Buzzer is activated

Detection data is sent to IoT server

Data is stored for monitoring and analysis

🌐 IoT Data Stored

Detection status

Timestamp

Image / event ID

🎯 Applications

Anti-drone surveillance

Restricted area monitoring

Smart security systems

🔮 Future Enhancements

Cloud dashboard visualization

SMS / Email alerts

Multi-axis servo tracking

Improved CNN accuracy
