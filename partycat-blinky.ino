// Party Cat v4 Test
// This example will cycle through R, G, B, and W on all pixels.

#include <NeoPixelBus.h>

const uint16_t PixelCount = 2;
const uint8_t PixelPin = 3;  // Esp8266 i2s DMA pin

#define colorSaturation 255

// four element pixels, GRBW
NeoPixelBus<NeoGrbwFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);

// three element pixels, in different order
//NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);
//NeoPixelBus<NeoRgbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);


RgbwColor red(colorSaturation, 0, 0, 0);
RgbwColor green(0, colorSaturation, 0, 0);
RgbwColor blue(0, 0, colorSaturation, 0);
RgbwColor white(0, 0, 0, colorSaturation);
RgbwColor black(0);


void setup()
{
    Serial.begin(115200);
    Serial.println();
    Serial.println("Initializing...");
    Serial.flush();

    // this resets all the neopixels to an off state
    strip.Begin();
    strip.Show();

    Serial.println("Running...");
}


void loop()
{
    Serial.println("red");
    for (int i=0; i<PixelCount; i++) {
      strip.SetPixelColor(i, red);
    }
    strip.Show();
    delay(1000);

    Serial.println("off");
    for (int i=0; i<PixelCount; i++) {
      strip.SetPixelColor(i, black);
    }
    strip.Show();
    delay(1000);

    Serial.println("green");
    for (int i=0; i<PixelCount; i++) {
      strip.SetPixelColor(i, green);
    }
    strip.Show();
    delay(1000);

    Serial.println("off");
    for (int i=0; i<PixelCount; i++) {
      strip.SetPixelColor(i, black);
    }
    strip.Show();
    delay(1000);

    Serial.println("blue");
    for (int i=0; i<PixelCount; i++) {
      strip.SetPixelColor(i, blue);
    }
    strip.Show();
    delay(1000);

    Serial.println("off");
    for (int i=0; i<PixelCount; i++) {
      strip.SetPixelColor(i, black);
    }
    strip.Show();
    delay(1000);

    Serial.println("white");
    for (int i=0; i<PixelCount; i++) {
      strip.SetPixelColor(i, white);
    }
    strip.Show();
    delay(1000);

    Serial.println("off");
    for (int i=0; i<PixelCount; i++) {
      strip.SetPixelColor(i, black);
    }
    strip.Show();
    delay(1000);
    
}
