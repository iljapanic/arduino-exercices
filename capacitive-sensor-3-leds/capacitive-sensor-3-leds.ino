#include <CapacitiveSensor.h>

// pins for the loops
CapacitiveSensor capSensorRed = CapacitiveSensor(2, 4);
CapacitiveSensor capSensorGreen = CapacitiveSensor(2, 5);
CapacitiveSensor capSensorBlack = CapacitiveSensor(2, 6);

// pins for the LEDs 
const int ledWhite = 8;
const int ledGreen = 9;
const int ledBlue = 10;

// treshold for LEDs to turn on
int threshold = 1000; 


void setup() {
  Serial.begin(9600);
  pinMode(ledWhite, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
}


void loop() {

  // read sensor values every 30ms
  long sensorValueRed = capSensorRed.capacitiveSensor(30);
  long sensorValueGreen = capSensorGreen.capacitiveSensor(30);
  long sensorValueBlack = capSensorBlack.capacitiveSensor(30);

  // print values to Serial for debugging
  Serial.print("sensorRed = ");
  Serial.print(sensorValueRed);
  Serial.print("; sensorGreen=");
  Serial.print(sensorValueGreen);
  Serial.print("; sensorBlack=");
  Serial.println(sensorValueBlack);


  // turn on the lights based on the capacitor 
  
  if (sensorValueRed > threshold) {
    whiteOn();
  } else {
    whiteOff();
  }

  if (sensorValueGreen > threshold) {
    greenOn();
  } else {
    greenOff();
  }

  if (sensorValueBlack > threshold) {
    blueOn();
  } else {
    blueOff();
  }

  delay(500);
  
}


void whiteOn() {
  digitalWrite(ledWhite, HIGH);
}

void whiteOff() {
  digitalWrite(ledWhite, LOW);
}

void greenOn() {
  digitalWrite(ledGreen, HIGH);
}

void greenOff() {
  digitalWrite(ledGreen, LOW);
}

void blueOn() {
  digitalWrite(ledBlue, HIGH);
}

void blueOff() {
  digitalWrite(ledBlue, LOW);
}
