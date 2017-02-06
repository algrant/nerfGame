// #include "Arduino.h"
// #include <Adafruit_NeoPixel.h>
// #ifdef __AVR__
//   #include <avr/power.h>
// #endif
//
// #define PIN 6
// int points = 22;
//
// // Main Display Setup
// Adafruit_NeoPixel strip = Adafruit_NeoPixel(points, PIN, NEO_RGB + NEO_KHZ800);
//
// void setup() {
//
//   delay(2000);
//
//   strip.begin();
//   strip.show(); // Initialize all pixels to 'off'
// }
//
// int rot = 0;
// int speed = 5;
// void loop() {
//   rot = (rot+1)%points;
//
//   for(uint16_t i=0; i<points; i++) {
//     if (i == rot) {
//       strip.setPixelColor(i, strip.Color(255,255,255));
//     } else {
//       if ( i == (rot -1)%points || i == (rot + 1) % 25) {
//          strip.setPixelColor(i, strip.Color(200,200,200));
//
//       } else {
//               strip.setPixelColor(i, strip.Color(0,0,0));
//
//       }
//     }
// //    int r = (255*(25)/i + rot)%255;
// //    strip.setPixelColor(i, Wheel(r)) ; //strip.Color(10*(q%2), 10*(q%2) , 10*(q%2)));
//   }
//   strip.show();
//   delay(25);
// }
//
//
// // Input a value 0 to 255 to get a color value.
// // The colours are a transition r - g - b - back to r.
// uint32_t Wheel(byte WheelPos) {
//   WheelPos = 255 - WheelPos;
//   if(WheelPos < 85) {
//     return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
//   }
//   if(WheelPos < 170) {
//     WheelPos -= 85;
//     return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
//   }
//   WheelPos -= 170;
//   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
// }
