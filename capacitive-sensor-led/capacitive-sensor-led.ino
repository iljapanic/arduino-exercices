#include <CapacitiveSensor.h>

CapacitiveSensor capSensor = CapacitiveSensor(2, 4);

int threshold1 = 80;
int threshold2 = 150;

const int ledRed = 8;
const int ledGreen = 10;
const int ledBlue = 9;

void setup() {
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
}

void loop() {
  long sensorValue = capSensor.capacitiveSensor(30);

  Serial.println(sensorValue);

  if (sensorValue > threshold2) {
    redOn();
  } else if (sensorValue > threshold1) {
    greenOn();
  } else {
    blueOn();
  }

  delay(100);
  
}

void redOn() {
  analogWrite(ledRed, 255);
  analogWrite(ledGreen, 0);
  analogWrite(ledBlue, 0);
  delay(100);
}

void greenOn() {
  analogWrite(ledRed, 0);
  analogWrite(ledGreen, 255);
  analogWrite(ledBlue, 0);
  delay(100);
}

void blueOn() {
  analogWrite(ledRed, 0);
  analogWrite(ledGreen, 0);
  analogWrite(ledBlue, 255);
  delay(100);
}
