#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    144

CRGB leds[NUM_LEDS];
int counter;
void setup() 
{
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  counter=0;
  
}
void loop() {  
  counter=(counter+1)%144;
  leds[counter] = CRGB(255, 0, 0);
  FastLED.show();
  delay(20);  
  leds[counter] = CRGB(0, 0, 0);
}
