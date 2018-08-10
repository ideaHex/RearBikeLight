/*  _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _
 * / \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \  
 * \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ 
 *
 * Rear Tail light for bicycle
 * Uses two 8 LED neopixel arraye & Digispark
 * 
 *   for more information visit
 *    www.ideahex.com
 * 
 * Written by Damian Kleiss 
 *  _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _
 * / \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \  
 * \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \*/#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN       1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 16

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

unsigned long previousMillis = 0;
const long interval = 15;

unsigned int ptr = 0;
const unsigned int numFrames = 57;

const unsigned char colour[numFrames] = {25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,26,26,28,32,40,56,87,146,254,146,87,56,40,56,87,146,254,146,87,56,40,32,28,26,26,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25};

 
void setup()
{
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;

    if (++ptr >= numFrames)
    {
      ptr = 0;
    }

    for (int i = 0; i < NUMPIXELS; i++)
    {
      pixels.setPixelColor(i, pixels.Color(colour[ptr], 0 , 0 ));
      pixels.show(); // This sends the updated pixel color to the hardware.

    }
  }
}
