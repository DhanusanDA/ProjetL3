#include "Tunnel.h"
#include "piloterMoteur.h"
#include "DetecterCouleur.h"
#include "EvitementObstacle.h"
#include "RecupLigne.h"

Servo myservo;
long Dist = 0;
int posservo = 0;    // variable pour la position du servomoteur


Ultrasonic ultrasonic(A2);

void Tunnel(){
  while(true) {
    LightSensorRGB_1.updataAllSensorValue();
    pos = LightSensorRGB_1.getPositionState();
    
    // Condition de sortie du tunnel
    if(pos == 0b1001 || pos == 0b0011) {
      arreter();
      break;  // on sort de la boucle et Tunnel() rend la main
    }
  Dist = ultrasonic.MeasureInCentimeters(); // Distance en cm definie dans la variable "Distance"
  piloterMoteur(MOTEUR_A, ARRIERE, 30); // Vitesse 40/63
  piloterMoteur(MOTEUR_B, AVANT, 30);
  myservo.write(22);              // dit au servomoteur d'aller a la positions definie dans la variable 'pos' donnée emise en angle                    
  Serial.println(Dist);
if(Dist <= 20){                          // cas extrême gauche en premier
  piloterMoteur(MOTEUR_A, ARRIERE, 10);
  piloterMoteur(MOTEUR_B, AVANT, 40);
}
else if(Dist <= 24){                     // puis cas modéré
  piloterMoteur(MOTEUR_A, ARRIERE, 26);
  piloterMoteur(MOTEUR_B, AVANT, 40);
}
else if(Dist >= 25){                     // cas modéré droite
  piloterMoteur(MOTEUR_A, ARRIERE, 40);
  piloterMoteur(MOTEUR_B, AVANT, 26);
}
else {
  avancer();                             // zone neutre 22-24cm → tout droit
}

if (pos == 0b1001 || pos == 0b0011 ){
  //arreter();
  RecupLigne(ARRIERE, ARRIERE);
  delay(500);
}
}
}