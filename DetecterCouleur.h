#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <Adafruit_NeoPixel.h>


#define LED_PIN    4       // Fil DATA du ruban sur D6 du Grove Shield
#define LED_COUNT  30      // Nombre de LEDs
#define SEUIL_DOMINANT 200
#define SEUIL_MIXTE  150
#define SEUIL_ABSENT  150

extern Adafruit_NeoPixel strip;   // déclaration seulement
extern Adafruit_TCS34725 tcs;     // déclaration seulement


void classifierCouleur();
void DetecterCouleur();
