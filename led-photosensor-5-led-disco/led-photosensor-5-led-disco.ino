// asign inputs-outputs to pins - stay constant
const int ledGreen = 13;
const int ledRed = 7;
const int ledBlue = 6;
const int ledYellow = 5;
const int ledClear = 4;
const int photosensor = A0;

// variables that will change throughout the loop
int sensorValue = 0;
int outputValue = 0;

// initial setup
void setup() {
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledClear, OUTPUT);
  pinMode(photosensor, INPUT);
  Serial.begin(9600);
}

void loop() {

  // read the potenciometer value
  sensorValue = analogRead(photosensor);

  // get photosensor range and remap it to LED range
  outputValue = map(sensorValue, 0, 1023, 1023, 0);


  //  turn on LEDs based on the light coming to the photosesor
  
  if (outputValue < 300) {
    greenOn();
  } else if (outputValue > 300 && outputValue < 500) {
    redOn();
  } else if (outputValue > 500 && outputValue < 600) {
    blueOn();
  } else if (outputValue > 600 && outputValue < 700) {
    yellowOn();
  } else if (outputValue > 700) {
     clearOn();
  }

  
  
  // print the values to Serial for debugging
  Serial.print("sensorValue = ");
  Serial.print(sensorValue);
  Serial.print(" ~~~ ");
  Serial.print("outputValue = ");
  Serial.println(outputValue);
  
  delay(10);
    
}


// functions for turning individuals leds on (and the rest off)

void greenOn() {
  analogWrite(ledGreen, 255);
  analogWrite(ledRed, 0);
  analogWrite(ledBlue, 0);
  analogWrite(ledYellow, 0);
  analogWrite(ledClear, 0);
}

void redOn() {
  analogWrite(ledGreen, 0);
  analogWrite(ledRed, 255);
  analogWrite(ledBlue, 0);
  analogWrite(ledYellow, 0);
  analogWrite(ledClear, 0);
}

void blueOn() {
  analogWrite(ledGreen, 0);
  analogWrite(ledRed, 0);
  analogWrite(ledBlue, 255);
  analogWrite(ledYellow, 0);
  analogWrite(ledClear, 0);
}

void yellowOn() {
  analogWrite(ledGreen, 0);
  analogWrite(ledRed, 0);
  analogWrite(ledBlue, 0);
  analogWrite(ledYellow, 255);
  analogWrite(ledClear, 0);
}

void clearOn() {
  analogWrite(ledGreen, 0);
  analogWrite(ledRed, 0);
  analogWrite(ledBlue, 0);
  analogWrite(ledYellow, 0);
  analogWrite(ledClear, 255);
}
