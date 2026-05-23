#include "DetecterCouleur.h"
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_TCS34725 tcs = Adafruit_TCS34725(
  TCS34725_INTEGRATIONTIME_50MS,
  TCS34725_GAIN_4X
);

void DetecterCouleur(){
    uint16_t r, g, b, c;
    tcs.getRawData(&r, &g, &b, &c);

    Serial.print("R:"); Serial.print(r);
    Serial.print(" G:"); Serial.print(g);
    Serial.print(" B:"); Serial.println(b);

    // Trouver couleur dominante
    if (r > g && r > b) {
      Serial.println("→ ROUGE");
      for (int i = 0; i < 3; i++) {
        ONLED(255, 0, 0);
        delay(500);
        OFFLED();
      }
    }
    else if (g > r && g > b) {
      Serial.println("→ VERT");
      for (int i = 0; i < 3; i++) {
        ONLED(0, 255, 0);
        delay(500);
        OFFLED();
      }
    }
    else if (b > r && b > g) {
      Serial.println("→ BLEU");
      for (int i = 0; i < 3; i++) {
        ONLED(0, 0, 255);
        delay(500);
        OFFLED();
      }
    }
    else {
      Serial.println("→ BLANC");
      ONLED(255, 255, 255);
    }
}
void ONLED(uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < LED_COUNT; i++) {
      strip.setPixelColor(i, strip.Color(r, g, b));
    }
    strip.show();
}

void OFFLED() {
    for (int i = 0; i < LED_COUNT; i++) {
      strip.setPixelColor(i, 0);
    }
    strip.show();
}

