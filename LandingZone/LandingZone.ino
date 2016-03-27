// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16

float touchSensorValue = 0;

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 300; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);
 
}

void loop() {
  touchSensorValue = analogRead(A0);
  touchSensorValue = touchSensorValue/100;
  Serial.println(touchSensorValue);

  if (touchSensorValue > 4 && touchSensorValue < 5) {
    clearSign();
     sign(0,false,"green");
  } else if (touchSensorValue >= 5 && touchSensorValue < 6) {
    clearSign();
     sign(0,false,"yellow");
  } else if (touchSensorValue > 6 && touchSensorValue <= 8) {
    clearSign();
     //sign(0,false,"red");
     blinkingSign("red");
  } else if (touchSensorValue < 4) {
    clearSign();
  }

}

void sign(int offset, boolean skip , String color) {
  for(int i=offset;i<NUMPIXELS;i++){
    if (color == "green") {
          pixels.setPixelColor(i, pixels.Color(0,255,0)); // Moderately bright green color.
    }
    if (color == "red") {
       pixels.setPixelColor(i, pixels.Color(239,0,0)); // Moderately bright red color.   
    }
    if (color == "yellow") {
             pixels.setPixelColor(i, pixels.Color(255,255,0)); // Moderately bright red color.   
    }
    pixels.show(); // This sends the updated pixel color to the hardware.
    if (skip) {
      i++;
    }
  }
}

void blinkingSign(String color) {
    clearSign();
    sign(0,true,color);
    delay(500);
    clearSign();
    sign(1,true,color);
    delay(500);
    
}

void clearSign() {
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.
    
  }
}
