Advanced Drone Detection using CNN with ESP32
Overview

This project implements an AI-based drone detection system using a Convolutional Neural Network (CNN) with an ESP32 microcontroller and ESP32-CAM. When a drone is detected, the system activates a servo motor, triggers a buzzer alert, and uploads detection data to an IoT server for logging and remote monitoring.

Key Features

Real-time drone detection using CNN

Image capture via ESP32-CAM

Servo motor activation for tracking

Buzzer alert on detection

Detection event stored on IoT server

Remote monitoring and data logging

Hardware Components

ESP32 Microcontroller

ESP32-CAM Module

Servo Motor

Buzzer

Power Supply

Connecting Wires

Software & Tools

CNN Model (Drone Detection)

Embedded C and C++

Arduino IDE / PlatformIO

Python (CNN training)

IoT Cloud Platform (MQTT / HTTP based)

Working Principle

ESP32-CAM captures live images.

CNN analyzes images for drone detection.

When a drone is detected:

Servo motor is activated.

Buzzer sounds an alert.

Detection data (time, status, image/ID) is sent to an IoT server.

Data can be viewed remotely via dashboard or API.

Applications

Anti-drone surveillance

Restricted and sensitive area security

Smart IoT-based monitoring systems

Future Enhancements

Cloud dashboard with analytics

Email/SMS alerts

GPS-based location tagging

Higher-accuracy CNN models
