// pins for resistor
const int pressureSensor = A0;

// pins for the LEDs 
const int ledWhite = 8;
const int ledGreen = 9;
const int ledBlue = 10;


void setup() {
  Serial.begin(9600); 
  pinMode(ledWhite, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
}


void loop() {

  // read touch sensor values
  long sensorValue = analogRead(pressureSensor);

  // print values to Serial for debugging
  Serial.print("resistorValue = ");
  Serial.println(sensorValue);

  if (sensorValue < 500) {
    whiteOn();
  } else {
    whiteOff();
  }

  if (sensorValue > 500 && sensorValue < 800) {
    blueOn();
  } else {
    blueOff();
  }

  if (sensorValue > 800) {
    greenOn();
  } else {
    greenOff();
  }



  delay(100);
  
}


// simple functions for turning the LEDs on and off
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
