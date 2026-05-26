#include "RecupLigne.h"

void RecupLigne (int a, int b, int c){
    while(true){
    LightSensorRGB_1.updataAllSensorValue();       // mise à jour du capteur
    pos = LightSensorRGB_1.getPositionState();     // relecture de pos
    if (pos == 0b0000 || pos == 0b0011 || pos == 0b0011) break;
    }
    delay(c);
    arreter();
    piloterMoteur(MOTEUR_A, a, 25); 
    piloterMoteur(MOTEUR_B, b, 25);
    while(true){
    LightSensorRGB_1.updataAllSensorValue();       
    pos = LightSensorRGB_1.getPositionState();     
    if (pos == 0b1001 || pos == 0b1100) break;
    }
}
