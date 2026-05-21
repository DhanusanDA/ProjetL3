#include "DetecterCouleur.h"
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_TCS34725 tcs = Adafruit_TCS34725(
  TCS34725_INTEGRATIONTIME_50MS,
  TCS34725_GAIN_4X
);

void classifierCouleur(uint8_t &r, uint8_t &g, uint8_t &b) {

  // Rouge pur : R dominant
  if (r >= SEUIL_DOMINANT && g < SEUIL_ABSENT && b < SEUIL_ABSENT) {
    r = 255; g = 0; b = 0;
    Serial.println("Couleur detectee : ROUGE");
    return;
  }
  // Vert pur : G dominant
  if (g >= SEUIL_DOMINANT && r < SEUIL_ABSENT && b < SEUIL_ABSENT) {
    r = 0; g = 255; b = 0;
    Serial.println("Couleur detectee : VERT");
    return;
  }
  // Bleu pur : B dominant
  if (b >= SEUIL_DOMINANT && r < SEUIL_ABSENT && g < SEUIL_ABSENT) {
    r = 0; g = 0; b = 255;
    Serial.println("Couleur detectee : BLEU");
    return;
  }

  // Jaune : R et G présents
  if (r >= SEUIL_MIXTE && g >= SEUIL_MIXTE && b < SEUIL_ABSENT) {
    r = 255; g = 255; b = 0;
    Serial.println("Couleur detectee : JAUNE");
    return;
  }
  /* Cyan : G et B présents
  if (g >= SEUIL_MIXTE && b >= SEUIL_MIXTE && r < SEUIL_ABSENT) {
    r = 0; g = 255; b = 255;
    Serial.println("Couleur detectee : CYAN");
    return;
  }
  // Magenta : R et B présents
  if (r >= SEUIL_MIXTE && b >= SEUIL_MIXTE && g < SEUIL_ABSENT) {
    r = 255; g = 0; b = 255;
    Serial.println("Couleur detectee : MAGENTA");
    return;
  }

  // Blanc 
  if (r >= SEUIL_MIXTE && g >= SEUIL_MIXTE && b >= SEUIL_MIXTE) {
    r = 255; g = 255; b = 255;
    Serial.println("Couleur detectee : BLANC");
    return;
  }*/
}

void DetecterCouleur(){
  Serial.println("debut loop");
  uint16_t r, g, b, c;

  // Allumer la LED du capteur pour éclairer l'objet
  //tcs.setInterrupt(false);
  delay(10);

  unsigned long debut = millis();
  // Lire les valeurs brutes
  tcs.getRawData(&r, &g, &b, &c);
  if (millis() - debut > 200) {
      Serial.println("TIMEOUT I2C !");
  }

  // Éteindre la LED du capteur
  //tcs.setInterrupt(true);

  // Éviter division par zéro
  if (c == 0) return;

  // Normaliser vers 0-255
  uint8_t red   = constrain((uint32_t)r * 255 / c, 0, 255);
  uint8_t green = constrain((uint32_t)g * 255 / c, 0, 255);
  uint8_t blue  = constrain((uint32_t)b * 255 / c, 0, 255);
  
  // Seuil des couleurs pour une couleur plus vive
  uint8_t maxVal = max(red, max(green, blue));
  if (maxVal == 0) return;

  red = (uint32_t)red * 255 / maxVal;
  green = (uint32_t)green * 255 / maxVal;
  blue = (uint32_t)blue * 255 / maxVal;
  
  // Moniteur série
  Serial.print("R: "); Serial.print(red);
  Serial.print(" G: "); Serial.print(green);
  Serial.print(" B: "); Serial.println(blue);

  classifierCouleur(red, green, blue);

  // Afficher la couleur sur toutes les LEDs
  for (int i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(red, green, blue));
    delay(10);
  }
  strip.show();

  delay(10);
}