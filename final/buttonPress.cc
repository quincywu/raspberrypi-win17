/*
 *  buttonPress to activate wiringPiISR to turn servo lock and unlock door
 */

#include <iostream>
#include <wiringPi.h>
#include "buttonPress.hh"

#define PWM_SERVO       12      // this is physical pin 12
#define BUTTON_GPIO     13      // this is GPIO27, pin 13
#define LOCK            29      // manually calibrated values
#define UNLOCK          118     // for servo positions

void buttonPress(void) {      // ISR on button press - not debounced
   cout << "Button was pressed -- finishing ." << endl;
   const int state = digitalRead(PWM_SERVO);
   if(state) pwmWrite(PWM_SERVO, UNLOCK);
   if(!state) pwmWrite(PWM_SERVO, LOCK);

}
