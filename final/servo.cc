#include <iostream>
#include <wiringPi.h>
#include "buttonPress.hh"

using namespace std;
// ASSERT

#define PWM_SERVO       12      // this is physical pin 12
#define BUTTON_GPIO     13      // this is GPIO27, pin 13
#define LOCK            29      // manually calibrated values
#define UNLOCK          118     // for servo positions

int main() {                             // must be run as root
   wiringPiSetupPhys();                  // use the physical pin numbers
   pinMode(PWM_SERVO, PWM_OUTPUT);            // use the RPi PWM output
   pinMode(BUTTON_GPIO, INPUT);          // the button input
   wiringPiISR(BUTTON_GPIO, INT_EDGE_RISING, &buttonPress);

   // Setting PWM frequency to be 10kHz with a full range of 128 steps
   // PWM frequency = 19.2 MHz / (divisor * range)
   // 10000 = 19200000 / (divisor * 128) => divisor = 15.0 = 15
   pwmSetMode(PWM_MODE_MS);              // use a fixed frequency
   pwmSetRange(128);                     // range is 0-128 (steps for servo)
   pwmSetClock(15);                      // gives a precise 10kHz signal
   cout << "The PWM Output is enabled" << endl;

   pwmWrite(PWM_SERVO, 32);                   // duty cycle of 25% (32/128)
   return 0;                             // PWM output stays on after exit
}
//void delay (unsigned int howLong) millisecond
