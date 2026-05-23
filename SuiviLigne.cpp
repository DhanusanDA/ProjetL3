#include "SuiviLigne.h"
#include "piloterMoteur.h"
#include "DetecterCouleur.h"
#include "EvitementObstacle.h"

MeRGBLineFollower LightSensorRGB_1(PORT_3);
int vitesse = 30;
uint8_t pos = 0;

//-------------------------------------------------
//Fonctions permettant de faire bouger le robot
//-------------------------------------------------

//Fonction pour faire avancer le robot tout droit 
void avancer() 
{
  //On met les deux moteurs a la même vitesse de rotation
  piloterMoteur(MOTEUR_A, ARRIERE, 40); 
  piloterMoteur(MOTEUR_B, AVANT, 40);
}
//Fonction pour faire pivoter le robot a gauche
void tournerGauche()
{
    piloterMoteur(MOTEUR_A, ARRIERE, 20); 
    piloterMoteur(MOTEUR_B, AVANT, 42);
}
//Fonction pour faire pivoter le robot a gauche
void tournerGaucheVariable(int VitesseGauche, int VitesseDroite)
{
    piloterMoteur(MOTEUR_A, ARRIERE, VitesseGauche); 
    piloterMoteur(MOTEUR_B, AVANT, VitesseDroite);
}
//Fonction pour faire pivoter le robot a droite
void tournerDroiteVariable(int VitesseGauche, int VitesseDroite)
{
    piloterMoteur(MOTEUR_A, ARRIERE, VitesseGauche); 
    piloterMoteur(MOTEUR_B, AVANT, VitesseDroite);

}
//Fonction pour faire pivoter le robot a droite
void tournerDroite()
{
    piloterMoteur(MOTEUR_A, ARRIERE, 40); 
    piloterMoteur(MOTEUR_B, AVANT, 22);
}
void grandetournerGauche()
{
    piloterMoteur(MOTEUR_A, ARRIERE, 13); 
    piloterMoteur(MOTEUR_B, AVANT, 40);
}
//Fonction pour faire pivoter le robot a droite
void grandetournerDroite()
{
    piloterMoteur(MOTEUR_A, ARRIERE, 40); 
    piloterMoteur(MOTEUR_B, AVANT, 13);
}
//Fonction pour arreter le robot
void arreter()
{
  //On arrete les deux moteurs 
  piloterMoteur(MOTEUR_A, ARRET, 0 ); 
  piloterMoteur(MOTEUR_B, ARRET, 0);
}

//-------------------------------------------------
//Fonction d'execution du code
//-------------------------------------------------

void SuiviLigne() {
  LightSensorRGB_1.updataAllSensorValue();
  pos = LightSensorRGB_1.getPositionState();
  Serial.println(pos, BIN);

  // Cas du  robot centré
  if(pos == 0b1001){ 
    Serial.println("avancer");
    avancer();
  }
    // Tout les cas de robot etant trop a gauche
  else if(pos == 0b1101){
    Serial.println("tournée à gauche");
    tournerGauche();
  }
  // Tout les cas de robot etant trop a droite
  else if(pos == 0b1011){
    Serial.println("tournée à droite");
    tournerDroite();
  }
  
  // Tout les cas de robot etant trop a gauche
  else if(pos == 0b1100 || pos == 0b1110 || pos == 0b1000){
    Serial.println("tournée à gauche");
    grandetournerGauche();
  }
  // Tout les cas de robot etant trop a droite
  else if(pos == 0b0001 || pos == 0b0011 || pos == 0b0111){
    Serial.println("tournée à droite");
    grandetournerDroite();
  }
  // Cas où la ligne est pleine donc arret
  else if (pos == 0b0000){
    Serial.println("arret");
    arreter();
  }
  // Flag
  else if (pos == 0b1111){
    Serial.println("flag");

  }
  delay(10);
}
