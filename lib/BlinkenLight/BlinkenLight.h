/*
  Target
*/
#ifndef BlinkenLight_h
#define BlinkenLight_h

#include "Arduino.h"

class BlinkenLight
{
  public:
    BlinkenLight(int pin, long on, long off);
    void Update();
  private:
    int ledPin;      // the number of the LED pin
    long OnTime;     // milliseconds of on-time
    long OffTime;    // milliseconds of off-time

    // These maintain the current state
    int ledState;             		// ledState used to set the LED
    unsigned long previousMillis;  	// will store last time LED was updated
};

#endif
