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

const uint32_t green = pixels.Color(0, 64, 0, 64);
const uint32_t red = pixels.Color(64, 0, 0, 64);


void setupNeoRing() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show();
  pixels.setBrightness(25);  
}

/**
 * Display level.
 */
void NoeRingdisplayLevel(int level, int limit) {
  // Calculate number of pixels and color.
  int current = level / (1023 / NUMPIXELS) + 1;
  uint32_t color = (level > limit) ? red : green;
    
  for (int i = 0; i < current; i++) {
    pixels.setPixelColor(i, color);
    pixels.show();
    delay(100);
  }
}

/**
 * Turn off all pixels.
 */
void neoRingReset() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, 0);
  }
  pixels.show();
}

