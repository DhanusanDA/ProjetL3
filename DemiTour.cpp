#include "DemiTour.h"
int tempo = 0;

void DemiTour(){
  piloterMoteur(MOTEUR_A, AVANT, 30); 
  piloterMoteur(MOTEUR_B, ARRIERE, 30);
  delay(100);
  while (tempo < 300){
  if(pos == 0b1110 || pos == 0b1000 || pos == 0b1100){
    Serial.println("tournée à gauche");
    piloterMoteur(MOTEUR_A, AVANT, 30); 
    piloterMoteur(MOTEUR_B, ARRIERE, 42);
  }
  // Tout les cas de robot etant trop a droite
  if(pos == 0b0001 || pos == 0b0111 || pos == 0b0011){
    Serial.println("tournée à droite");
    piloterMoteur(MOTEUR_A, AVANT, 42); 
    piloterMoteur(MOTEUR_B, ARRIERE, 30);
  }
  delay(5);
  tempo = tempo+1;
  }
  arreter();
  delay(30);
  piloterMoteur(MOTEUR_A, AVANT, 25); 
  piloterMoteur(MOTEUR_B, AVANT, 25);
  delay(2000);
  while(true){
    LightSensorRGB_1.updataAllSensorValue();       // mise à jour du capteur
    pos = LightSensorRGB_1.getPositionState();     // relecture de pos
    if (pos == 0b1001 || pos == 0b0011 || 0b0001) break;
  }
}