#include "Arduino.h"
#include "TargetStationary.h"
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
  state = COUNTDOWN_TARGET;
  lastState = COUNTDOWN_TARGET;
}

void Target::Update()
{
  unsigned long currentMillis = millis();
  bool stateChanged = state == lastState;

  // if (stateChanged) {
  //   // on exit ?
  //   switch(lastState) {
  //     case EMPTY_TARGET:
  //       break;
  //     default:
  //       break;
  //   }
  //   // on enter ?
  //   switch(state) {
  //     case EMPTY_TARGET:
  //       break;
  //     default:
  //       break;
  //   }
  // }
  //

  lastState = state;

  if (currentMillis - previousMillis > 50) {
    previousMillis = currentMillis;
    CHSV colour;
    int brightness;
    int updown;
    switch(state) {
      case EMPTY_TARGET:
        updown = (currentMillis/10)%255;
        // if (updown > 255) {
        //   updown = 512 - updown;
        // }
        brightness = sin8(updown)/10;
        colour = CHSV(122 + brightness*brightness/25, 255, 255);
        for(int i = 0; i < _length; i++) {
          _leds[_startPin + i] = colour;
        }
        break;
      case AVAILABLE_TARGET:
        brightness = sin8((currentMillis/3 + 255/2)%255)/5;
        colour = CHSV(255, 255, 255 - brightness);
        for(int i = 0; i < _length; i++) {
          _leds[_startPin + i] = colour;
        }
        break;
      case COUNTDOWN_TARGET:
        updown = _length*(currentMillis%1000)/1000;
        brightness = (currentMillis%5000)/1000;
        for(int i = 0; i < _length; i++) {
          if (i < updown) {
            _leds[_startPin + i] = CHSV(brightness*255/5,255,255);
          } else {
            _leds[_startPin + i] = CHSV((brightness-1)*255/5,255,255);
          }
        }
        break;
    }

  }

  // check to see if it's time to change the state of the LED

  // if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime)) {
  //   ledState = LOW;  // Turn it off
  //   previousMillis = currentMillis;  // Remember the time
  //   for(int i = 0; i < _length; i++) {
  //     _leds[_startPin + i] = CRGB::Black;
  //   }
  //   // digitalWrite(ledPin, ledState);  // Update the actual LED
  // } else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime)) {
  //   ledState = HIGH;  // turn it on
  //   previousMillis = currentMillis;   // Remember the time
  //   for(int i = 0; i < _length; i++) {
  //     _leds[_startPin + i] = CRGB::Red;
  //   }
  // }
}
