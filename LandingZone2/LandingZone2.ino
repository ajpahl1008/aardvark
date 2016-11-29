
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int greenPin = 0;     // the FSR and 10K pulldown are connected to a0
int greenReading;     // the analog reading from the FSR resistor divider
int yellowPin = 1;
int yellowReading;
int redPin = 2;
int redReading;

void setup(void) {
//  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
//  #if defined (__AVR_ATtiny85__)
//     if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
//  #endif
  pixels.begin(); 
  Serial.begin(9600);
}

void loop(void) {
  greenReading = analogRead(greenPin);
  yellowReading = analogRead(yellowPin);
  redReading = analogRead(redPin);

  if (isGreen(greenReading, yellowReading, redReading)) {
    greenSign();
    Serial.println("I see you!!!!");
  } else if (isYellow(greenReading, yellowReading, redReading)) {
    yellowSign();
    Serial.println("Keep Going...");
  } else if (isRed(greenReading, yellowReading, redReading)) {
    redSign();
    Serial.println("STOP!!");
  } else {
    clearSign();
    Serial.println("Nobody's Here");
    
  }
  delay(500);
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
  } else if (greenReading < 10 && yellowReading > 10 && redReading < 10) {
    return true;
  } else if (greenReading > 10 && yellowReading < 10 && redReading < 10) {
    return true;
  } else {
    return false;
  }
}

void greenSign() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }

}

void yellowSign() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 255, 0)); // Moderately bright red color.
    pixels.show(); // This sends the updated pixel color to the hardware.

  }
}

void redSign() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(239, 0, 0)); // Moderately bright red color.
    pixels.show(); // This sends the updated pixel color to the hardware.

  }
}

void clearSign() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}
