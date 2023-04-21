# Mbed Tesla

brought to you by David Gomez, Matthew Liu, & Adam Rappaport
  
![Mbed Tesla](./assets/mbedtesla.png)

# Navigation <a name ="top"></a>
- [Project Idea](#projectidea)  
- [Instructions](#instructions)  
- [Hardware](#hardware)  
- [Software](#software)  
- [Demo Video](#demo)

---
## Project Idea <a name = "projectidea"></a>
Bluetooth controlled mbed robot with similar functionality as a real car such as moving, turning, blinking lights, honking horn, and collision detection.  

The robot will utilize the adafruit bluetooth app and module in order to be controlled. The robot will be able to be controlled for driving forwards, backwards, and turning. The robot will additionally have headlights and breaklights with different levels of brightness. The speaker can be controlled to honk. Additionally, the robot will feature a LIDAR sensor in the front that will prevent crashing into objects. All this functionality will be handled with mbed RTOS threads.  

----
## Instructions <a name = "instructions"></a>

Back to [Top](#top)!

----
## Hardware <a name = "hardware"></a> 
**Hardware and Comm Protocol Used**  
- LEDS: digital PWM pXX, pXX, pXX, pXX 
- SONAR: Trig p6, Echo p7  
- LIDAR: I2C (SCL p27, SDA p28)  
- Bluetooth: RS232 Serial (Rx p27, Tx p28)  
- Speaker:  
- DC Motors:  
- LCD Display:  

![wiring](./assets/wiring.jpg) 

----
## Software <a name = "software"></a> 
**Code Snippets**  

![collision_detection](./assets/collision_detection.jpg)  

![bluetooth state machine](./assets/state_machine.jpg)  

**Full Source Code**  
- [source code](https://drive.google.com/drive/folders/1TNty7M6peybXFbq6Ig-HpSm_tmf9db-7?usp=sharing)  

----
## Demo Video <a name = "demo"></a>

[Chopin - Fantaisie Impromptu](https://www.youtube.com/watch?v=hCwSzsDiuXU)  

![drone sim](https://media.giphy.com/media/P2zNidvSMBVJPJ1LjU/giphy.gif)  

Back to [Top](#top)!
