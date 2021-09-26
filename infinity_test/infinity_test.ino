#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    60

CRGB leds[NUM_LEDS];
int counter;
//RGB values
uint8_t red_color_code; //between 0-255
uint8_t green_color_code; //between 0-255
uint8_t blue_color_code; //between 0-255

void setup() 
{
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  counter=0;
  red_color_code = 0;
  green_color_code = 120;
  blue_color_code = 120;
  Serial.begin(115200);
  
}

void loop() 
{
    for(counter=0; counter<=NUM_LEDS; counter++)
    {
      //counter=(counter+1)%NUM_LEDS;
      leds[counter] = CRGB(red_color_code, green_color_code, blue_color_code);
      FastLED.show();
      if(counter == NUM_LEDS)
      {
        counter = 0;
        red_color_code = red_color_code + 5;
        blue_color_code = blue_color_code - 5;
        green_color_code = green_color_code - 5;
//        red_color_code++;
//        blue_color_code--;
//        green_color_code--;
      }
      delay(100);  
      leds[counter] = CRGB(0, 0, 0);
      if(red_color_code == 255)
      {
        red_color_code = 0;
      }
      if(green_color_code == 0)
      {
        green_color_code = 255;
      }
      if(blue_color_code == 0)
      {
        blue_color_code = 255;
      }
      
      Serial.print("red_color_code : ");
      Serial.println(red_color_code);
      Serial.print("green_color_code : ");
      Serial.println(green_color_code);
      Serial.print("blue_color_code : ");
      Serial.println(blue_color_code);
      Serial.print("Counter is:");
      Serial.println(counter);
    }
}
