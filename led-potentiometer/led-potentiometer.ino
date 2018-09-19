// asign inputs-outputs to pins - stay constant
const int ledBlue = 8;
const int ledRed = 9;
const int ledGreen = 7;
const int ledYellow = 6;
const int meter = A0;

// variables that will change throughout the loop
int sensorValue = 0;
int outputValue = 0;

// initial setup
void setup() {
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(meter, INPUT);
  Serial.begin(9600);
}

void loop() {

  // read the potenciometer value
  sensorValue = analogRead(meter);

  // get potentiometer range (0-1023) and remap its to values for LEDs (0-255)
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  // pass remaped values to LEDs
  analogWrite(ledRed, outputValue);
  analogWrite(ledYellow, outputValue);
  analogWrite(ledBlue, outputValue);
  analogWrite(ledGreen, outputValue);

  // print the values to Serial for easier debugging
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print(" ~ ");
  Serial.print("output = ");
  Serial.println(outputValue);
  
  delay(10);
    
}
