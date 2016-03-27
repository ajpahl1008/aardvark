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

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 300; // delay for half a second

void setup() {
//  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
//#if defined (__AVR_ATtiny85__)
//  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
//#endif
//  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
}

int r = 0;
int g = 0;
int b = 0;
void loop() {
  
//   for(int i=0;i<NUMPIXELS;i++){
        pixels.setPixelColor(0, pixels.Color(255,0,0)); // Moderately bright green color.
        pixels.setPixelColor(1, pixels.Color(255,165,0)); // Moderately bright green color.
        pixels.setPixelColor(2, pixels.Color(255,255,0)); // Moderately bright green color.
        pixels.setPixelColor(3, pixels.Color(0,128,0)); // Moderately bright green color.
        pixels.setPixelColor(4, pixels.Color(0,0,255)); // Moderately bright green color.
        pixels.setPixelColor(5, pixels.Color(75,0,130)); // Moderately bright green color.
        pixels.setPixelColor(6, pixels.Color(238,130,238)); // Moderately bright green color.
        
        pixels.show(); // This sends the updated pixel color to the hardware.
//   }
//   delay(100);
//   g++;
//   b++;
}


