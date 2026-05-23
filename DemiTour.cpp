#include "DemiTour.h"

void DemiTour(){
  piloterMoteur(MOTEUR_A, AVANT, 30); 
  piloterMoteur(MOTEUR_B, ARRIERE, 30);
  delay(2000);
  arreter();
  delay(30);
  piloterMoteur(MOTEUR_A, AVANT, 25); 
  piloterMoteur(MOTEUR_B, AVANT, 25);
  delay(300);
  while(true){
    LightSensorRGB_1.updataAllSensorValue();       // mise à jour du capteur
    pos = LightSensorRGB_1.getPositionState();     // relecture de pos
    if (pos == 0b1001 ) break;
  }
}