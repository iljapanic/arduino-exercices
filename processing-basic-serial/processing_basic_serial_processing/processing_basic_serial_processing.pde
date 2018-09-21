import processing.serial.*;

Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial port


void setup() {
  
  // print a list of available ports
  printArray(Serial.list());
  
  // (in my case the Arduino is connected on port 13)  
  String portName = Serial.list()[13];
  
  // make sure to set up the same baud rate like the Arduino
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  if ( myPort.available() > 0) {  // If data is available,
    val = myPort.readStringUntil('\n');         // read it and store it in val
  } 
  println(val); //print it out in the console
  delay(100);
}
