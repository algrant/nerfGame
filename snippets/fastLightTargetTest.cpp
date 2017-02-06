#include "FastLED.h"
#include <BlinkenLight.h>
#include <Target.h>

#include "Arduino.h"

BlinkenLight target(13, 1000, 1000);

CRGB leds[22];

Target colourTarget(leds, 0, 5, 1000, 1000);
Target colourTarget2(leds, 5, 5, 1500, 1500);

void setup() {
  FastLED.addLeds<NEOPIXEL, 6>(leds, 22);
  Serial.begin(9600);
}
void loop() {
  // static uint8_t hue = 0;
  // FastLED.showColor(CHSV(hue++, 255, 55));
  // delay(100);
  target.Update();
  colourTarget.Update();
  colourTarget2.Update();
  if (millis() % 500 == 0){
    Serial.print(leds[1]);
  }
  FastLED.show();
}
