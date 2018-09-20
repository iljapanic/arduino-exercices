#include <CapacitiveSensor.h>

CapacitiveSensor capSensor = CapacitiveSensor(2, 4);

int treshold = 100;

const int ledPin = 8;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  long sensorValue = capSensor.capacitiveSensor(30);

  Serial.println(sensorValue);

  if (sensorValue > treshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(10);
  
}
