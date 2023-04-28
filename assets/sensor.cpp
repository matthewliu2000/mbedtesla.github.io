#include "mbed.h"
#include "ultrasonic.h"
#include "Speaker.h"
Speaker mySpeaker(p26);
DigitalOut output(p5);
DigitalOut led(LED1);
 void dist(int distance)
{
    //put code here to execute when the distance has changed
    printf("Distance %d mm\r\n", distance);
    if (distance < 100 && distance > 0)
    {
        output = 1;
        led = 1;
    }
    else {
        output = 0;
        led = 0;
    }
}
ultrasonic mu(p6, p7, .1, 1, &dist);    //Set the trigger pin to D8 and the echo pin to D9
                                        //have updates every .1 seconds and a timeout after 1
                                        //second, and call dist when the distance changes
int main()
{
    mu.startUpdates();//start measuring the distance
    while(1)
    {
        //Do something else here
        mu.checkDistance();     //call checkDistance() as much as possible, as this is where
                                //the class checks if dist needs to be called.
    }
}
