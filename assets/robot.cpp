#include "Motor.h"
#include "Thread.h"
#include "mbed.h"
#include "rtos.h"
#include "stdio.h"
#include <stdio.h>

Serial bluemod(p28,p27);

DigitalIn sensor(p5);
Motor motor1(p25,p15,p16);
Motor motor2(p24,p19,p17);

DigitalOut frontLeftLED(p29);
DigitalOut backLeftLED(p30);
DigitalOut frontRightLED(p13);
DigitalOut backRightLED(p12);
DigitalOut testLED(LED3);
DigitalOut testLED2(LED4);

const double SPEEDINTERVAL = 0.25;
const double MAXSPEED = 0.5;

volatile double speedAmt = 0;

PwmOut Speaker(p26);
// mutex to make the lcd lib thread safe

volatile int turn = 0; // 0 still 1 left 2 right
char bnum = 0;
volatile int play = 0; // play audio
void audio(void const * args)
{
    while (1)
    {
        if (play == 1) {
            Speaker.period(1.0/523.25);
            Speaker = 0.005;
            Thread::wait(500);
            Speaker = 0;
            play = 0;
            
        }

    }
}

volatile int turnLeft;
volatile int turnRight;
volatile int leftPressed;
volatile int rightPressed;

void lights(void const * args)
{
    while (1)
    {
        if (leftPressed)
        {
            frontLeftLED = !frontLeftLED;
            backLeftLED = !backLeftLED;            
        }
        else 
        {
            frontLeftLED = 0;
            backLeftLED = 0;   

        }
        if (rightPressed)
        {
            frontRightLED = !frontRightLED;
            backRightLED = !backRightLED;
        }
        else 
        {
            frontRightLED = 0;
            backRightLED = 0;   

        }
        if (turnLeft && leftPressed)
        {
            leftPressed = 0;
            Thread::wait(100);
        }
        if (turnRight && rightPressed)
        {
            rightPressed = 0;
            Thread::wait(100);
        }

        Thread::wait(600);
    }
}

void bt(void const *args)
{
    while(1) {
        if (bluemod.readable()){
            if (bluemod.getc()=='!') {
                if (bluemod.getc()=='B') { //button
                    bnum = bluemod.getc();
                    if (bluemod.getc() == '1'){
                        switch (bnum){
                            case '1':  // Button1
                                play = 1;
                                break;

                            case '2': //button 2
                                speedAmt = 0;
                                break;

                            case '3': // left blinker
                                leftPressed = !leftPressed;
                                if (leftPressed) rightPressed = 0;           
                                break;

                            case '4': // right blinker
                                rightPressed = !rightPressed;
                                if (rightPressed) leftPressed = 0;
                                break;

                            case '5': //up
                                turn = 0;
                                turnLeft = 0;
                                turnRight = 0;
                                speedAmt += SPEEDINTERVAL;
                                if (speedAmt > MAXSPEED) speedAmt = MAXSPEED;
                                break;

                            case '6': //down
                                turn = 0;
                                turnLeft = 0;
                                turnRight = 0;
                                speedAmt -= SPEEDINTERVAL;
                                if (speedAmt < -MAXSPEED) speedAmt = -MAXSPEED;
                                break;

                            case '7': //left
                                turn = 1;
                                turnLeft = 1;
                                turnRight = 0;
                                speedAmt = 2*SPEEDINTERVAL; //maybe replace
                                break;

                            case '8': //right
                                turn = 2;
                                turnRight = 1;
                                turnLeft = 0;
                                speedAmt = 2*SPEEDINTERVAL; //maybe replace
                                break;

                            default:
                                break;
                        }  // switch(bnum)
                    }  // if (bluemod.getc() == '1')
                }  // if (bluemod.getc()=='B'
            } //if (bluemod.getc()=='!') 
        }  // if (bluemod.getc() == '1')
    } // while(1) 
}

int main()
{  
    Thread t2(bt);
    Thread t3(audio);
    Thread t4(lights);
    while(true) {       // main is the next thread
        if (sensor)
        {
            testLED=1;
            motor1.speed(-.5);
            motor2.speed(-.5);
            Thread::wait(1200);
            speedAmt= 0;
            testLED=0;
        }
        else if (turn == 0)
        {
            motor1.speed(speedAmt);
            motor2.speed(speedAmt);
        }
        else if (turn == 1)
        {
            motor1.speed(-speedAmt);
            motor2.speed(speedAmt);
        }
        else if (turn == 2)
        {
            motor1.speed(speedAmt);
            motor2.speed(-speedAmt);
        }
        Thread::wait(50);
    }
}
