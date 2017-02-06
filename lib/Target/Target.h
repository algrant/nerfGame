/*
  Target.h - Library to control strip of LEDs in a circle as well as deal with button inputs I guess.
*/
#ifndef Target_h
#define Target_h

#include "Arduino.h"
#include "FastLED.h"

class Target
{
  public:
    Target(CRGB * leds, int startPin, int length, long OnTime, long OffTime);
    void Update();
  private:
    CRGB * _leds;
    int _startPin;
    int _length;      // the number of the LED pin
    long OnTime;     // milliseconds of on-time
    long OffTime;    // milliseconds of off-time

    // These maintain the current state
    int ledState;             		// ledState used to set the LED
    unsigned long previousMillis;  	// will store last time LED was updated
};

#endif
