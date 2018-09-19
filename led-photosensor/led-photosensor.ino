// asign inputs-outputs to pins - stay constant
const int ledGreen = 13;
const int photosensor = A0;

// variables that will change throughout the loop
int sensorValue = 0;
int outputValue = 0;

// initial setup
void setup() {
  pinMode(ledGreen, OUTPUT);
  pinMode(photosensor, INPUT);
  Serial.begin(9600);
}

void loop() {

  // read the potenciometer value
  sensorValue = analogRead(photosensor);

  // get photosensor range (0-1023) and remap its to values for LEDs (0-255)
//  outputValue = map(sensorValue, 0, 1023, 255, 0);


  if (sensorValue > 400) {
    analogWrite(ledGreen, 255);
  } else {
    analogWrite(ledGreen, 0);
  }

  
  // print the values to Serial for easier debugging
  Serial.print("photosensor-input = ");
  Serial.print(sensorValue);
  Serial.print(" ~~~ ");
  Serial.print("LED-output = ");
  Serial.println(outputValue);
  
  delay(10);
    
}
