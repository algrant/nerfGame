#include "FastLED.h"
#include <BlinkenLight.h>
#include <TargetStationary.h>

#include "Arduino.h"

#define TOTAL_LIGHTS 140

// BlinkenLight target(13, 1000, 1000);

CRGB leds[TOTAL_LIGHTS];

Target colourTarget(leds, 0, 23, 1000, 1000);
Target colourStrip1(leds, 23, 24, 1500, 1500);
Target colourTarget2(leds, 47, 22, 1000, 1000);
Target colourStrip2(leds, 69, 24, 1500, 1500);
Target colourTarget3(leds, 93, 23, 1000, 1000);
Target colourStrip3(leds, 116, 24, 1500, 1500);

void setup() {
  FastLED.addLeds<NEOPIXEL, 6>(leds, TOTAL_LIGHTS);
  colourStrip1.state = AVAILABLE_TARGET;
  colourStrip2.state = AVAILABLE_TARGET;
  colourStrip3.state = AVAILABLE_TARGET;

  Serial.begin(9600);
}

void loop() {
  // static uint8_t hue = 0;
  // FastLED.showColor(CHSV(hue++, 255, 150));
  // delay(100);
  colourTarget.Update();
  colourTarget2.Update();
  colourTarget3.Update();
  colourStrip1.Update();
  colourStrip2.Update();
  colourStrip3.Update();
  if (millis() % 500 == 0){
    Serial.print(leds[1]);
  }
  FastLED.show();
}
