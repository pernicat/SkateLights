#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN        3
#define NUMPIXELS  8

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 50

#define HUE_MAX 65535
#define HUE_STEP  512

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pixels.begin();
}

void loop() {

  for(uint16_t c=0; c<HUE_MAX; c+=HUE_STEP) {

    for(uint16_t i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.ColorHSV((c + (i*HUE_STEP)) % HUE_MAX, 255, 255));
      pixels.show();
    }

    delay(DELAYVAL);
  }
}
