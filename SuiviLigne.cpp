#include "SuiviLigne.h"
#include "piloterMoteur.h"

MeRGBLineFollower LightSensorRGB_1(PORT_3);
int vitesse = 30;
int flag = 0;
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
  //On diminue progresssivement le moteur gauche et on fait fonctionner le moteur droit a vitesse nominale
  //while (pos != 0b1001){
    piloterMoteur(MOTEUR_A, ARRIERE, 25); 
    piloterMoteur(MOTEUR_B, AVANT, 40);
    //vitesse = vitesse - 1;
    //delay(300);
  //}
}
//Fonction pour faire pivoter le robot a droite
void tournerDroite()
{
  //On diminue progresssivement le moteur droit et on fait fonctionner le moteur gauche a vitesse nominale
  //while (pos != 0b1001){
    piloterMoteur(MOTEUR_A, ARRIERE, 40); 
    piloterMoteur(MOTEUR_B, AVANT, 25);
    //vitesse = vitesse - 1;
    //delay(300);
  //}
}
void grandetournerGauche()
{
  //On diminue progresssivement le moteur gauche et on fait fonctionner le moteur droit a vitesse nominale
  //while (pos != 0b1001){
    piloterMoteur(MOTEUR_A, ARRIERE, 10); 
    piloterMoteur(MOTEUR_B, AVANT, 40);
    //vitesse = vitesse - 1;
    //delay(300);
  //}
}
//Fonction pour faire pivoter le robot a droite
void grandetournerDroite()
{
  //On diminue progresssivement le moteur droit et on fait fonctionner le moteur gauche a vitesse nominale
  //while (pos != 0b1001){
    piloterMoteur(MOTEUR_A, ARRIERE, 40); 
    piloterMoteur(MOTEUR_B, AVANT, 10);
    //vitesse = vitesse - 1;
    //delay(300);
  //}
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
  delay(50);
}
