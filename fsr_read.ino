#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    5
#define BRIGHTNESS  64
#define LED_TYPE    WS2812  // or SK6812
#define COLOR_ORDER GRB
#define THRESHOLD   10
CRGB leds[NUM_LEDS];

const int fsr_1_pin = A0;  // Analog pin A0
int fsr_1_reading = 0;     // Variable to store FSR reading

void setup() {
  Serial.begin(9600);   // Start serial communication

  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();  // ensure all LEDs start off
  FastLED.show();
}

void loop() {
  fsr_1_reading = analogRead(fsr_1_pin);  // Read the analog value from FSR
  if (fsr_1_reading > THRESHOLD) {
    Serial.print("FSR Reading: ");
    Serial.println(fsr_1_reading);
    fill_solid(leds, NUM_LEDS, CRGB::Blue);  // change color if desired
  } else {
    fill_solid(leds, NUM_LEDS, CRGB::Black); // turn off LEDs
  }
  
  FastLED.show();
  delay(50);  // adjust for responsiveness vs flicker
} 