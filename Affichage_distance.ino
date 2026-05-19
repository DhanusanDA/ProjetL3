#include <Wire.h>
#include <rgb_lcd.h>
#include "Ultrasonic.h"

#ifdef USE_TINYUSB
#include <Adafruit_TinyUSB.h>
#endif

// LCD RGB Grove
rgb_lcd lcd;

// Capteur Grove Ultrasonic sur port D7
Ultrasonic ultrasonic(7);

void setup() {
  Serial.begin(9600);
  Serial.println("Demarrage...");

  // LCD : 16 colonnes, 2 lignes
  lcd.begin(16, 2);
  
  // Couleur de fond bleu
  lcd.setRGB(0, 0, 255);
  
  lcd.setCursor(0, 0);
  lcd.print("Distance:");

  Serial.println("LCD initialise");
  Serial.println("Capteur pret");
}

void loop() {
  long distanceCm = ultrasonic.MeasureInCentimeters();
  long distanceInch = ultrasonic.MeasureInInches();

  // Moniteur serie
  Serial.println("------------------------");
  Serial.print("Distance : ");
  Serial.print(distanceCm);
  Serial.println(" cm");
 


  // Affichage LCD
  lcd.setCursor(0, 1);
  lcd.print(distanceCm);
  lcd.print("  cm");
  delay(200);
}
