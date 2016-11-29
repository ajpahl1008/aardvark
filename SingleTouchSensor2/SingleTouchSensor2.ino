/* FSR simple testing sketch.

  Connect one end of FSR to power, the other end to Analog 0.
  Then connect one end of a 10K resistor from Analog 0 to ground

  For more information see www.ladyada.net/learn/sensors/fsr.html */

int greenPin = 0;     // the FSR and 10K pulldown are connected to a0
int greenReading;     // the analog reading from the FSR resistor divider
int yellowPin = 1;
int yellowReading;
int redPin = 2;
int redReading;

void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);
}

void loop(void) {
  greenReading = analogRead(greenPin);
  yellowReading = analogRead(yellowPin);
  redReading = analogRead(redPin);

//  Serial.print("Analog Green reading = ");
//  Serial.println(greenReading);     // the raw analog reading
//
//  Serial.print("Analog Yellow reading = ");
//  Serial.println(yellowReading);     // the raw analog reading
//
//  Serial.print("Analog Red reading = ");
//  Serial.println(redReading);     // the raw analog reading
//
//  Serial.println("***************");
  
    if (isGreen(greenReading, yellowReading, redReading)) {
      Serial.println("I see you!!!!");
    }
    if (isYellow(greenReading, yellowReading, redReading)) {
      Serial.println("Keep Going...");
    }
    if (isRed(greenReading, yellowReading, redReading)) {
      Serial.println("STOP!!");
    }

  delay(1000);

}

boolean isGreen(int greenReading, int yellowReading, int redReading) {
      if (greenReading < 10 && yellowReading > 10 && redReading > 10) {
        return true;
      } else {
        return false;
      }
}

boolean isYellow(int greenReading, int yellowReading, int redReading) {
      if (greenReading < 10 && yellowReading < 10 && redReading > 10) {
        return true;
      } else {
        return false;
      }
}

boolean isRed(int greenReading, int yellowReading, int redReading) {
      if (greenReading < 10 && yellowReading < 10 && redReading < 10) {
        return true;
      } else if (greenReading < 10 && yellowReading > 10 && redReading < 10){
        return true;
      } else if (greenReading > 10 && yellowReading < 10 && redReading < 10){
        return true;
      } else {
        return false;
      }
}

