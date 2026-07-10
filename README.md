CAN-Based Vehicle Safety & Monitoring System

➤ This project implements a CAN-Based Vehicle Safety and Monitoring System using LPC2129 ARM7 microcontrollers and MCP2551 CAN transceivers.

➤ The system is designed to improve vehicle safety by monitoring engine temperature, controlling vehicle indicators, and detecting reverse obstacles using CAN communication.

➤ The complete system is divided into three different nodes:

→ Main Control Node

→ Indicator Node

→ Reverse Alert Node

➤ All the nodes communicate using CAN protocol.

━━━━━━━━━━━━━━━━━━━━━━

MAIN CONTROL NODE

➤ The Main Control Node continuously reads engine temperature using the DS18B20 temperature sensor.

➤ The measured temperature is displayed on the LCD display.

➤ External interrupt switches are used for controlling left and right indicators.

➤ When a switch is pressed, the Main Node sends corresponding CAN data to the Indicator Node.

➤ Another switch is used for changing vehicle mode between Forward and Reverse.

➤ In Reverse mode, the Main Node receives obstacle distance data from the Reverse Alert Node using CAN communication.

➤ The received distance is displayed on the LCD.

➤ If an obstacle is detected near the vehicle, an alert indication is provided using an LED.

━━━━━━━━━━━━━━━━━━━━━━

INDICATOR NODE

➤ The Indicator Node continuously receives CAN messages from the Main Node.

➤ Based on the received CAN data, left or right scrolling indicators are activated.

➤ Non-blocking scrolling logic is implemented for smooth indicator operation.

━━━━━━━━━━━━━━━━━━━━━━

REVERSE ALERT NODE

➤ The Reverse Alert Node continuously reads obstacle distance using the HC-SR04 ultrasonic sensor.

➤ The measured distance is transmitted to the Main Node using CAN communication.

➤ An alert LED is activated whenever the obstacle distance is below the safety limit.

━━━━━━━━━━━━━━━━━━━━━━

HARDWARE COMPONENTS USED

→ LPC2129 ARM7 Microcontroller

→ MCP2551 CAN Transceiver

→ DS18B20 Temperature Sensor

→ HC-SR04 Ultrasonic Sensor

→ 20x4 LCD Display

→ LEDs

→ Push Buttons

━━━━━━━━━━━━━━━━━━━━━━

SOFTWARE USED

→ Embedded C

→ Keil uVision

→ Flash Magic

━━━━━━━━━━━━━━━━━━━━━━

PIN CONNECTIONS

MAIN CONTROL NODE

→ P0.8 to P0.15  → LCD Data Pins

→ P0.18          → LCD RS

→ P0.19          → LCD EN

→ P0.20          → LCD RW

→ P0.14          → Left Indicator Switch

→ P0.15          → Right Indicator Switch

→ P0.16          → Reverse Mode Switch / DS18B20 Data Pin

→ P0.24          → CAN TX

→ P0.25          → CAN RX

━━━━━━━━━━━━━━━━━━━━━━

INDICATOR NODE

→ P0.8 to P0.15  → Indicator LEDs

→ P0.24          → CAN TX

→ P0.25          → CAN RX

━━━━━━━━━━━━━━━━━━━━━━

REVERSE ALERT NODE

→ P0.21          → Ultrasonic Trigger Pin

→ P0.22          → Ultrasonic Echo Pin

→ P0.20          → Alert LED

→ P0.24          → CAN TX

→ P0.25          → CAN RX

━━━━━━━━━━━━━━━━━━━━━━

CAN IDs USED

→ 0x101 → Indicator Control Data

→ 0x102 → Reverse Mode Data

→ 0x201 → Reverse Distance Data

━━━━━━━━━━━━━━━━━━━━━━

FEATURES OF THE PROJECT

→ Real-time engine temperature monitoring

→ Left and right vehicle indicator control

→ Reverse obstacle detection

→ CAN-based node communication

→ LCD status display

→ Alert indication during obstacle detection

→ Fault-tolerant embedded system design

→ Timeout protection for sensors and CAN communication

→ Non-blocking LED scrolling implementation

━━━━━━━━━━━━━━━━━━━━━━

APPLICATIONS

→ Automotive safety systems

→ Vehicle monitoring systems

→ Driver assistance systems

→ Embedded CAN network applications

━━━━━━━━━━━━━━━━━━━━━━

CONCLUSION

➤ This project successfully demonstrates a distributed automotive embedded system using CAN protocol.

➤ The system provides reliable communication between multiple nodes and implements vehicle safety features such as temperature monitoring, indicator control, and reverse obstacle detection using LPC2129 microcontrollers.
