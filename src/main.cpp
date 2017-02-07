
#include "Arduino.h"


// these constants won't change:
const int ledPin = 13;      // led connected to digital pin 13
const int knockSensor = A0; // the piezo is connected to analog pin 0
const int threshold = 100;  // threshold value to decide when the detected sound is a knock or not

// these variables will change:
int sensorReading = 0;      // variable to store the value read from the sensor pin
int ledState = LOW;         // variable used to store the last LED status, to toggle the light

long int prevMillis;
long int currentMillis;

void setup() {
  prevMillis = millis();
  pinMode(ledPin, OUTPUT); // declare the ledPin as as OUTPUT
  Serial.begin(9600);
}

void loop() {
  currentMillis = millis();
  // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(knockSensor);

  if (currentMillis - prevMillis >= 500){
    if (sensorReading >= threshold) {
      // toggle the status of the ledPin:
      ledState = !ledState;
      // update the LED pin itself:
      digitalWrite(ledPin, ledState);
      // send the string "Knock!" back to the computer, followed by newline
      Serial.println("Knock!");
      Serial.println(sensorReading);
    }

    prevMillis = currentMillis - currentMillis%5000;
  }

}
