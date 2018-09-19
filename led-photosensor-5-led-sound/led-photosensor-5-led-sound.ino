// asign inputs-outputs to pins - stay constant
const int ledRed = 7;
const int ledBlue = 6;
const int ledYellow = 5;
const int ledClear = 4;
const int piezo = 13;
const int photosensor = A0;

// variables that will change throughout the loop
int sensorValue = 0;
int outputValue = 0;

// initial setup
void setup() {
  pinMode(piezo, OUTPUT);
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
  if (outputValue > 300 && outputValue < 500) {
    redOn();
    tone(piezo, outputValue, 750);
  } else if (outputValue > 500 && outputValue < 600) {
    blueOn();
    tone(piezo, outputValue, 750);
  } else if (outputValue > 600 && outputValue < 700) {
    yellowOn();
    tone(piezo, outputValue, 750);
  } else if (outputValue > 700) {
     clearOn();
     noTone(piezo);
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

void piezoOn() {
  tone(piezo, 400, 100);
}

void redOn() {
  analogWrite(ledRed, 255);
  analogWrite(ledBlue, 0);
  analogWrite(ledYellow, 0);
  analogWrite(ledClear, 0);
}

void blueOn() {
  analogWrite(ledRed, 0);
  analogWrite(ledBlue, 255);
  analogWrite(ledYellow, 0);
  analogWrite(ledClear, 0);
}

void yellowOn() {
  analogWrite(ledRed, 0);
  analogWrite(ledBlue, 0);
  analogWrite(ledYellow, 255);
  analogWrite(ledClear, 0);
}

void clearOn() {
  analogWrite(ledRed, 0);
  analogWrite(ledBlue, 0);
  analogWrite(ledYellow, 0);
  analogWrite(ledClear, 255);
}
