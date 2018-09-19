// asign inputs-outputs to pins - stay constant
int ledBlue = 8;
int ledRed = 9;
int ledGreen = 7;
int ledYellow = 6;
int button = 10;

// variables that will change throughout
int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;


void setup() {
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}


void turnLightsOn() {
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledBlue, HIGH);
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledYellow, HIGH);
}

void turnLightsOff() {
  digitalWrite(ledRed, LOW);
  digitalWrite(ledBlue, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
}


void loop() {

  buttonState = digitalRead(button);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;


  // turns on the LED every four button pushes by checking the modulo of the
  // button push counter. the modulo function gives you the remainder of the
  // division of two numbers:
  if (buttonPushCounter % 2 == 0) {
    turnLightsOn();
  } else {
    turnLightsOff();
  }

  
}
