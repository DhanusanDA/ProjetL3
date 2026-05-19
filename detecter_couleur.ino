#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <Adafruit_NeoPixel.h>


#define LED_PIN    6       // Fil DATA du ruban sur D6 du Grove Shield
#define LED_COUNT  30      // Nombre de LEDs


Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

Adafruit_TCS34725 tcs = Adafruit_TCS34725(
  TCS34725_INTEGRATIONTIME_50MS,
  TCS34725_GAIN_4X
);


void setup() {
  Serial.begin(9600);

  // Ruban LED
  strip.begin();
  strip.setBrightness(150);
  strip.show();

  // Capteur
  if (tcs.begin()) {
    Serial.println("Capteur TCS34725 detecte !");
  } else {
    Serial.println("Erreur : capteur non detecte");
    while (1);
  }
}

void loop() {
  uint16_t r, g, b, c;

  // Allumer la LED du capteur pour éclairer l'objet
  tcs.setInterrupt(false);
  delay(60);

  // Lire les valeurs brutes
  tcs.getRawData(&r, &g, &b, &c);

  // Éteindre la LED du capteur
  tcs.setInterrupt(true);

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

  // Afficher la couleur sur toutes les LEDs
  for (int i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(red, green, blue));
  }
  strip.show();

  delay(200);
}
