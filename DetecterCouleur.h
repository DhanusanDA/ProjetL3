#ifndef DETECTERCOULEUR_H
#define DETECTERCOULEUR_H
#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <Adafruit_NeoPixel.h>


#define LED_PIN    4       // Fil DATA du ruban sur D6 du Grove Shield
#define LED_COUNT  30      // Nombre de LEDs


extern Adafruit_NeoPixel strip;   // déclaration seulement
extern Adafruit_TCS34725 tcs;     // déclaration seulement


void DetecterCouleur();
void ONLED(uint8_t r, uint8_t g, uint8_t b);
void OFFLED();
#endif