// CONSTANTS
const int buttonPin = 2;
const int ledPin =  9; 
const int motoPin = 12;

// VARIABLES
int buttonState = 0;
int lastButtonState = 0;

int buttonPushCounter = 0;

int brightness = 0;
int fadeAmt = 10;
int fadeFactor = 1;

// SETUP
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(motoPin, OUTPUT);
  
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);

}

// PROGRAM
void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      if (buttonPushCounter < 3) {
        buttonPushCounter++;

        brightness = brightness + fadeAmt * fadeFactor;
        analogWrite(ledPin, brightness);
      
        Serial.println("on");
        Serial.println("number of pushes: ");
        Serial.println(buttonPushCounter);

        Serial.println(brightness);
        Serial.println("factor");
        Serial.println(fadeFactor);

        fadeFactor = fadeFactor * 4;
      }
      else {
        analogWrite(ledPin, 0);
        delay(125);
        analogWrite(ledPin, 255);
  
        Serial.println("limit reached");
      }
      digitalWrite(motoPin, HIGH);
      delay(250);
      digitalWrite(motoPin, LOW);
    }
    else {
      Serial.println("off");
    }
    delay(50);
  }
  else {
  }
  lastButtonState = buttonState;
}
