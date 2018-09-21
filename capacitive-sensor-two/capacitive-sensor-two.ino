#include <CapacitiveSensor.h>

CapacitiveSensor capSensor1 = CapacitiveSensor(2, 4);
CapacitiveSensor capSensor2 = CapacitiveSensor(2, 5);

int threshold1 = 80;
int threshold2 = 150;
int delayGlobal = 50; 

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
  long sensorValue1 = capSensor1.capacitiveSensor(30);
  long sensorValue2 = capSensor2.capacitiveSensor(30);

  Serial.print("sensor1 = ");
  Serial.print(sensorValue1);
  Serial.print(" /// sensor2 = ");
  Serial.println(sensorValue2);

  if (sensorValue1 > threshold1) {
    blueOn();
  }

  if (sensorValue2 > threshold2) {
    redOn();
  }

  delay(delayGlobal);
  
}

void redOn() {
  analogWrite(ledRed, 255);
  analogWrite(ledGreen, 0);
  analogWrite(ledBlue, 0);
  delay(delayGlobal);
}

void greenOn() {
  analogWrite(ledRed, 0);
  analogWrite(ledGreen, 255);
  analogWrite(ledBlue, 0);
  delay(delayGlobal);
}

void blueOn() {
  analogWrite(ledRed, 0);
  analogWrite(ledGreen, 0);
  analogWrite(ledBlue, 255);
  delay(delayGlobal);
}
