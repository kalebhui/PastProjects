int const rPotPin = A0;
int const gPotPin = A1;
int const bPotPin = A2;

int const OutPin = 6;

int rVal;
int gVal;
int bVal;

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h>
#endif


#define LED_PIN    6


#define LED_COUNT 150


Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  strip.begin();       
  strip.show();          
  strip.setBrightness(50); 
}



void loop() {

  rVal = analogRead(rPotPin) / 4;
  gVal = analogRead(gPotPin) / 4;
  bVal = analogRead(bPotPin) / 4;

  colorWipe(strip.Color(rVal, gVal, bVal), 0); 
}


void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { 
    strip.setPixelColor(i, color);        
    strip.show();                          
    delay(wait);                           
  }
}
