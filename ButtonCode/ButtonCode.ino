
int redLedPin = 13;
int yellowLedPin = 12;
int greenLedPin = 11;
int buttonOnePin = 7;
int buttonTwoPin = 6;
int buttonThreePin = 5;

int val1 = 0;
int val2 = 0;
int val3 = 0;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buttonOnePin,INPUT);
  pinMode(buttonTwoPin,INPUT);
  pinMode(buttonThreePin,INPUT);
}

void loop() {
  val1 = digitalRead(buttonOnePin);
  val2 = digitalRead(buttonTwoPin);
  val3 = digitalRead(buttonThreePin);

  if (val1 == HIGH) {
    digitalWrite(redLedPin,LOW);
    delay(30);
  } else {
    digitalWrite(redLedPin,HIGH);
    delay(30);
  }
  
  if (val2 == HIGH ) {
    digitalWrite(yellowLedPin, LOW);
    delay(30);
  } else { 
    digitalWrite(yellowLedPin,HIGH);
    delay(30);
  }

  if (val3 == HIGH ) {
    digitalWrite(greenLedPin, LOW);
    delay(30);
  } else { 
    digitalWrite(greenLedPin,HIGH);
    delay(30);
  }
}
