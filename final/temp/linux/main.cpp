// Blynk "gp" numbers are BCM numbers, so gp17 is physical pin 11 
// #define BLYNK_DEBUG
#define BLYNK_PRINT stdout
#ifdef RASPBERRY
 #include <BlynkApiWiringPi.h>
#else
 #include <BlynkApiLinux.h>
#endif
#include <BlynkSocket.h>
#include <BlynkOptionsParser.h>

#include <iostream>
#include <wiringPi.h>
#include <unistd.h>
#include <SPI.h>
#include <BlynkSimpleEthernet.h>
#include <Servo.h>

static BlynkTransportSocket _blynkTransport;
BlynkSocket Blynk(_blynkTransport);

#include <BlynkWidgets.h>

#define PWM_SERVO     18      // this is PWM0, pin 12
#define BUTTON_GPIO   27      // this is GPIO27, pin 13
#define LEFT          31      // manually calibrated values
#define RIGHT         140     // for the left, right and
#define CENTER        85      // center servo positions
bool locked = false;         // sweep servo until button pressed
bool error = false;			 // assert

unsigned int uptime;      		// 1 second intervals
unsigned int pinStatus;   		// status of BCM 17
unsigned int lastpinStatus = 0; // to toggle

void printStatus(){
	printf("Status: %s\n", ((locked)?"locked":"unlocked") );
	//cout << "Status: " << ((locked)?"locked":"unlocked") << endl;
}

void lock() {
	int local_error = 0;
	for(int i=RIGHT-3; i<RIGHT; i++) {       
		pwmWrite(PWM_SERVO, i);
		local_error = usleep(10000);
		if(local_error == -1) error = true; 
	}
	locked = true;
	printStatus();
	// log details in database with timestamp
}

void unlock() {
	int local_error = 0;
	for(int i=LEFT+3; i>=LEFT; i--) {        
		pwmWrite(PWM_SERVO, i);
		local_error = usleep(10000);
		if(local_error == -1) error = true; 
	}
	locked = false;
	printStatus();
	// log details in database with timestamp
}

void buttonPress() {      // ISR on button press - not debounced
	printf("Button was pressed\n");
	
	if(locked) 
		unlock();
	else 
		lock();
   
	printStatus();
}

void myTimerEvent()       		// button widget on V0 or direct access gp17 button
{
  uptime = (millis() / 1000);
  Blynk.virtualWrite(V1, uptime);
  pinStatus = digitalRead(17);
  if(pinStatus != lastpinStatus){
	lastpinStatus = pinStatus;
	printf("GP17 pin status: %i\n", pinStatus);
	if(pinStatus == 1){    // this is to synchronise V1 button if gp17 button is pressed
		Blynk.virtualWrite(V0, 1);
	}
	else{
		Blynk.virtualWrite(V0, 0);
	}
  }
}

void setup()
{
  //nothing to go here yet
	wiringPiSetupGpio();  // must be run as root
                          // use the GPIO numbering
	pinMode(PWM_SERVO, PWM_OUTPUT);       // the PWM servo
	pinMode(BUTTON_GPIO, INPUT);          // the button input
	wiringPiISR(BUTTON_GPIO, INT_EDGE_RISING, &buttonPress);
	pwmSetMode(PWM_MODE_MS);              // use a fixed frequency
	pwmSetRange(1000);                    // 1000 steps
	pwmSetClock(384);                     // gives 50Hz precisely
}

BLYNK_WRITE(V0)  // button set at PUSH frequency
{
  if(param[0] == 1){
	printf("V0 turned device ON\n");
	digitalWrite (17, HIGH) ;  
  }
  else{
	printf("V0 turned device OFF\n");
	digitalWrite (17, LOW) ;
  }
}

void loop()
{
  Blynk.run();
  if(millis() >= uptime + 1){  // 1 second intervals
	myTimerEvent();
  }
}

int main(int argc, char* argv[])
{
    const char *auth, *serv;
    uint16_t port;
    parse_options(argc, argv, auth, serv, port);
    Blynk.begin(auth, serv, port);
    while(!error) {
		loop();
    }
	
	if(error)
		printf("Fatal Error, locking the door and exit program");
		//cout << "Fatal Error, locking the door and exit program" << endl;
	lock();
   
	printf("Program has finished gracefully -");
	//cout << "Program has finished gracefully -" << endl;
	
    return 0;
}