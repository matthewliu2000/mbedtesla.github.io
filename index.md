# Mbed Tesla

brought to you by David Gomez, Matthew Liu, & Adam Rappaport
  
![Mbed Tesla](./assets/mbedtesla.png)

# Navigation <a name ="navi"></a>
- [Project Idea](#projectidea)  
- [Instructions](#instructions)  
- [Hardware](#hardware)  
- [Software](#software)  
- [Demo Video](#demo)

---
## Project Idea <a name = "projectidea"></a>
Bluetooth controlled mbed robot with similar functionality as a real car such as moving, turning, blinking lights to signal, honking horn, and collision detection.  

The robot will utilize the adafruit bluetooth app and module in order to be controlled. The robot will be able to be controlled for driving forwards, backwards, and turning. The robot will additionally have headlights and breaklights with different levels of brightness. The speaker can be controlled to honk. Additionally, the robot will feature a SONAR sensor in the front that will prevent crashing into objects. All functionality will be handled concurrently with mbed RTOS threads.  

----
## Instructions <a name = "instructions"></a>
To recreate the project:  
1.  Build robot chassis with motors and attach breadboards as shown in pictures  
2.  Attach embed devices and wire appropriately according to [Hardware](#hardware)   
3.  Compile and load source code onto main mbed and sonar mbed  
4.  Connect battery packs to circuit to power mbed  
5.  Connect via BlueFruit Connect on android/iphone  

----
## Hardware <a name = "hardware"></a> 
**List of Devices/Comm Protocol/Helpful Components**  
- LEDS: digital PWM pXX, pXX, pXX, pXX 
- SONAR: Trig p6, Echo p7 (HC-SR04)  
- Bluetooth: RS232 Serial (Rx p27, Tx p28)  
- Speaker: Class D audio amplifier (TPA2005D1)  
- DC Motors: H-bridge motor driver  
- DC barrel jack adapter  
- 1000 μF electrolytic decoupling capacitor  
- Robot chassis
- mbed ARM microcontrontroller (LPC1768)  

![wiring](./assets/wiring.jpg) 

----
## Software <a name = "software"></a> 
**Code Snippets**  
Collission detection:  
![collision_detection algorithm](./assets/collisiondetection.png)  
Bluetooth:  
![bluetooth control algorithm](./assets/bluetooth.png)  

**Full Source Code**  
- [source code main mbed](./assets/robot.cpp)  
- [source code sonar mbed](./assets/sensor.cpp)  

----
## Demo Video <a name = "demo"></a>

[Mbed Tesla Demo](https://clipchamp.com/watch/pJKSNSl9IBr)  

Back to [Navigation](#navi)!
