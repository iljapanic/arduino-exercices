int sensorPin = 0;
int LedRed = 13;
int Ledwhite = 12;

void setup() 
{
pinMode(LedRed, OUTPUT);
pinMode(Ledwhite, OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int reading = analogRead(sensorPin); 
float voltage = reading*5.0;
voltage/= 1024.0;

float temperatureC = (voltage-0.5)*100;
Serial.print(temperatureC);
Serial.println("degrees C");

if(temperatureC < 29) {
  analogWrite(Ledwhite, 255);
  analogWrite(LedRed, 0);
} else {
  analogWrite(Ledwhite, 0);
  analogWrite(LedRed, 255);
}


delay(500);
}
