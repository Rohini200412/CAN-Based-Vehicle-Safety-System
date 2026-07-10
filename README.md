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
