🚗 CAN-Based Vehicle Safety & Monitoring System using LPC2129 ARM7
<img width="1149" height="1369" alt="file_000000000870722fb7d2be2e5fa914d3" src="https://github.com/user-attachments/assets/23184af3-59bc-49ec-b21e-3cb5212e897f" >

⭐ Overview

This project implements a CAN-Based Vehicle Safety & Monitoring System using LPC2129 ARM7 microcontrollers. The system is designed with three independent nodes (ECUs) connected through the CAN Bus to enable reliable real-time communication.
The Main Control Node monitors engine temperature using the DS18B20 sensor, displays the information on the LCD, and controls the vehicle indicators through CAN communication. The Reverse Alert Node continuously measures obstacle distance using the HC-SR04 ultrasonic sensor and transmits the data to the Main Node. If an obstacle is detected within the safety limit, the system alerts the driver.
This project demonstrates a modular embedded system architecture with reliable inter-node communication suitable for real-time vehicle monitoring applications.
🏗️ Complete System Architecture
(Image)
🎯 Project Objectives
Monitor engine temperature in real time.
Display temperature and system status on the LCD.
Control left and right indicators using CAN communication.
Detect reverse obstacles using an ultrasonic sensor.
Alert the driver when an obstacle is detected.
Demonstrate reliable communication between multiple ECUs using the CAN protocol.
Build a scalable and modular embedded system.
🔌 Hardware Components
Component
Purpose
LPC2129 ARM7
Main Controller
MCP2551
CAN Transceiver
DS18B20
Temperature Monitoring
HC-SR04
Obstacle Detection
20×4 LCD
Display
LEDs
Indicator & Alert
Push Buttons
User Input
🖥️ System Block Diagram
(Image)
🔄 System Working Flow
(Flowchart Image)
🖥️ Main Control Node
The Main Control Node acts as the central controller of the system. It reads engine temperature from the DS18B20 sensor, displays the temperature on the LCD, monitors user switches, transmits CAN messages to the Indicator Node, and receives obstacle distance information from the Reverse Alert Node.
(Image)
💡 Indicator Node
The Indicator Node continuously receives CAN messages from the Main Control Node. According to the received message, it controls the left or right indicator LEDs, demonstrating reliable real-time CAN communication.
(Image)
📡 Reverse Alert Node
The Reverse Alert Node measures obstacle distance using the HC-SR04 ultrasonic sensor. The measured distance is transmitted to the Main Control Node through the CAN Bus. Whenever the distance falls below the predefined safety limit, an alert LED is activated.
(Image)
🚀 Features
Real-time Temperature Monitoring
CAN-Based Communication
Three ECU Architecture
Reverse Obstacle Detection
Indicator Control
LCD Status Display
Embedded C Firmware
LPC2129 ARM7 Based System
Reliable Distributed Communication
💻 Software Used
Embedded C
Keil µVision
Flash Magic
🔧 Hardware Used
LPC2129 ARM7
MCP2551 CAN Transceiver
DS18B20 Temperature Sensor
HC-SR04 Ultrasonic Sensor
20×4 LCD
LEDs
Push Buttons
Power Supply
📷 Project Gallery
Complete Hardware Setup
Main Control Node
Indicator Node
Reverse Alert Node
LCD Output
CAN Communication
Working Demo
👩‍💻 Author
Rohini
Bachelor of Technology (Electronics & Communication Engineering)
Embedded Firmware Engineer
📜 License
This project is intended for educational and academic purposes. Feel free to learn from, modify, and improve this project for non-commercial use.
🙏 Thank You
