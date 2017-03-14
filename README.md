# raspberrypi-win17

https://www.twilio.com/blog/2014/03/build-your-own-lockitron-with-twilio-arduino-and-node-js.html
http://www.instructables.com/id/Remote-Controlled-Door-Lock/
http://circuitdigest.com/microcontroller-projects/raspberry-pi-digital-lock
https://hackaday.com/tag/door-lock/

https://www.newegg.com/Product/Product.aspx?Item=9SIA67038V9549&cm_re=servo-_-9SIA67038V9549-_-Product
https://www.amazon.com/Hitec-33322S-HS-322HD-Standard-Karbonite/dp/B0006O3XEA
https://www.amazon.com/Futaba-FUTM0031-S3003-Standard-Servo/dp/B0015H2V72



http://raspberrypi.stackexchange.com/questions/1207/how-to-measure-temperature

http://raspberrypi.stackexchange.com/questions/13203/creating-halt-wake-button

http://raspberrypi.stackexchange.com/questions/8689/how-do-i-display-the-temperature-from-the-internal-sensor-on-a-html-page

Auto-Execute a program on power up
http://raspberrypi.stackexchange.com/questions/15229/auto-execute-a-program-on-power-up

servo
http://raspberrypi.stackexchange.com/questions/29561/softpwm-of-wiringpi-for-servo-where-is-the-problem


GNU gprof output – flat profile

when the setuid bit is set and the file is owned by root
then the program is executed as if by root, regardless of the actual user account
that executes it p.272

gpio mode 1 pwm
gpio pwm-ms
gpio pwmc 384
gpio pwmr 1000
gpio pwm 1 29

Servo 4.8V
50 Hz = 20ms (PWM period)
duty cycle = 1-2ms
center 1.5ms pulse, 1.5/20 = 75/1000
left 1ms pulse, 1/20 = 50/1000 Using 49
right 2ms pulse, 2/20 = 100/1000 Using 99
140, 30, 85

gcc -D defines a macro to be used by the preprocessor.
$ gcc -Dname [options] [source files] [-o output file]

// myfile.c
#include <stdio.h>
 
void main()
{
    #ifdef DEBUG    
       printf("Debug run\n");
    #else
       printf("Release run\n");
    #endif
}

$ gcc -D DEBUG myfile.c -o myfile
$ ./myfile
Debug run
$

POWER management off
Rebooting the Raspberry Pi when it loses wireless connection
http://weworkweplay.com/play/rebooting-the-raspberry-pi-when-it-loses-wireless-connection-wifi/

crontab
http://raspberrypituts.com/raspberry-pi-simple-cron-jobs-explanation/
@reboot python /home/pi/myscript.py &

sudo chown root abc.sh
chmod u+s comphope.txt
Set the "Set-User-ID" bit of comphope.txt, so that anyone who attempts to access that file does so as if they are the owner of the file.

chmod u+s comphope.txt
Restricted Deletion Flag (or "Sticky Bit")

-lwiringPi -lpthread
g++ -std=c++11 -o doorlock doorlock.cpp -lwiringPi -lpthread
sudo chown root doorlock
sudo chmod u+s doorlock

Running Blynk server locally 
java -jar server-0.23.0.jar -dataFolder /home/pi/Blynk/
https://www.raspberrypi.org/documentation/linux/usage/rc-local.md

