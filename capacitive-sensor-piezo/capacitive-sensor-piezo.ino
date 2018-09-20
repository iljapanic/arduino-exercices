#include <CapacitiveSensor.h>

CapacitiveSensor capSensor = CapacitiveSensor(2, 4);

int treshold = 300;

const int piezo = 8;


void setup() {
  Serial.begin(9600);
  pinMode(piezo, OUTPUT);
}

void loop() {
  long sensorValue = capSensor.capacitiveSensor(30);

  Serial.println(sensorValue);

  int outputValue = map(sensorValue, 0, 1000, 0, 10000);


  if (sensorValue > treshold) {
    tone(piezo, outputValue, 700);
  } else {
    noTone(piezo);
  }
  
  delay(10);
  
}
