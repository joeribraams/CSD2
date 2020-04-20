#include <iostream>		// Include all needed libraries here
#include <wiringPi.h>

using namespace std;		// No need to keep using “std”

int main()
{
  wiringPiSetup();			// Setup the library
  pinMode(0, INPUT);		// Configure GPIO0 as an input
  pinMode(1, OUTPUT);		// Configure GPIO1 as an output

  // Main program loop
  while(1)
  {
  	// Button is pressed if digitalRead returns 0
    if(digitalRead(0) == 1)
    {
    	// Toggle the LED
    	digitalWrite(1, !digitalRead(1));
      delay(500); 	// Delay 500ms
    }
  }
  return 0;
}
