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

  // get photosensor range and remap it
  outputValue = map(sensorValue, 0, 1000, 1000, 0);


  if (outputValue < 500) {
    analogWrite(ledGreen, 255);
  } else {
    analogWrite(ledGreen, 0);
  }

  
  // print the values to Serial for easier debugging
  Serial.print("sensorValue = ");
  Serial.print(sensorValue);
  Serial.print(" ~~~ ");
  Serial.print("outputValue = ");
  Serial.println(outputValue);
  
  delay(10);
    
}
