#include <ESP8266WiFi.h>
#include <ws2812_i2s.h>

#define RED_LED_PIN 16
#define WHITE_PIN 14

#define PWM_RANGE_FULL (1024)
#define RGB_RANGE_FULL (256)

#define NUM_LEDS 10
static WS2812 ledstrip;

void setup() {
  analogWriteRange(PWM_RANGE_FULL);
  pinMode(WHITE_PIN, OUTPUT);
  digitalWrite(WHITE_PIN, LOW);

  pinMode(RED_LED_PIN, OUTPUT);
  digitalWrite(RED_LED_PIN, LOW);

  Serial.begin(115200);

  ledstrip.init(NUM_LEDS);
}

void loop() {
  // Alternate status LED on/off
  digitalWrite(RED_LED_PIN, !digitalRead(RED_LED_PIN));

  // Set the white PWM channel to a random brightness
  analogWrite(WHITE_PIN, random(RGB_RANGE_FULL));

  // Set up each WS2812 pixel to a random colour
  Pixel_t pixels[NUM_LEDS];
  for(int i=0; i<NUM_LEDS; i++) {
    pixels[i].R = random(256);
    pixels[i].G = random(256);
    pixels[i].B = random(256);
  }

  // Flush the new pixel data down the string
  ledstrip.show(pixels);

  // Wait one second
  delay(1000);
}
