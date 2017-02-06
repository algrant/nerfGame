#include "Arduino.h"
#include "Target.h"
#include "FastLED.h"

Target::Target(CRGB * leds, int startPin, int length, long on, long off)
{
  _leds = leds;
  _startPin = startPin;
  _length = length;
  OnTime = on;
  OffTime = off;

  ledState = LOW;
  previousMillis = 0;
}

void Target::Update()
{
  // check to see if it's time to change the state of the LED
  unsigned long currentMillis = millis();

  if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime)) {
    ledState = LOW;  // Turn it off
    previousMillis = currentMillis;  // Remember the time
    for(int i = 0; i < _length; i++) {
      _leds[_startPin + i] = CRGB::Black;
    }
    // digitalWrite(ledPin, ledState);  // Update the actual LED
  } else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime)) {
    ledState = HIGH;  // turn it on
    previousMillis = currentMillis;   // Remember the time
    for(int i = 0; i < _length; i++) {
      _leds[_startPin + i] = CRGB::Red;
    }
  }
}
