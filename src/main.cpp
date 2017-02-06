// #include "Arduino.h"
//
// int buttonPin = 9;
// int ledPin = 13;
// int ledDelay = 1000;
// bool ledBlinkState = HIGH;
// long ledTimer;
// bool buttonPressed;
// bool ledState;
//
// void checkBlinkTimer() {
//   if (millis() - ledTimer > ledDelay) {
//     ledTimer = millis();
//     ledBlinkState = !ledBlinkState;
//   }
// }
//
// void checkButtonPress() {
//   buttonPressed = (digitalRead(buttonPin) == HIGH);
// }
//
// void determineLedState() {
//   if (ledBlinkState || buttonPressed) {
//     ledState = HIGH;
//   } else {
//     ledState = LOW;
//   }
// }
//
// void display() {
//   digitalWrite(ledPin, ledState);
// }
//
// void determineState() {
//   checkBlinkTimer();
//   checkButtonPress();
//   determineLedState();
// }
//
//
// // Run first on Arduino
// void setup() {
//   pinMode(buttonPin, INPUT);
//   pinMode(ledPin, OUTPUT);
//
//   ledTimer = millis();
// }
//
// // Arduino main loop
// void loop() {
//   determineState();
//   display();
// }
