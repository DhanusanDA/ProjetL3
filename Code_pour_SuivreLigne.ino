#include <Wire.h>                     // Protocole I2C
#include <MeRGBLineFollower.h>        //Ajout de la bibliothèque pour lire les données du capteur de suiveur de ligne 
#include <SparkFunMiniMoto.h>         //Ajout de la bibliothèque pour faire fonctionner les moteurs 

int Moteur_Propulsion_Gauche = 0xD0;
int Moteur_Propulsion_Droite = 0xCC;

MeRGBLineFollower Capteurligne(METTRE UN PORT PAR PITIE OUBLIE PAS);

int Vitesse = 20;
int Grande_Vitesse_Tournant = 15; 
int Petite_Vitesse_Tournant = 8;
//-------------------------------------------------
//Fonctions permettant de faire bouger le robot
//-------------------------------------------------

//Fonction pour faire avancer le robot tout droit 
void avancer() 
{
  //On met les deux moteurs a la même vitesse de rotation
  Moteur_Propulsion_Gauche.drive(Vitesse); 
  Moteur_Propulsion_Droite.drive(Vitesse);
}
//Fonction pour faire pivoter le robot a gauche
void tournerGauche()
{
  //On arrete le moteur gauche et on fait fonctionner le moteur droit a petite vitesse
  Moteur_Propulsion_Gauche.drive(Petite_Vitesse_Tournant);
  Moteur_Propulsion_Droite.drive(Grande_Vitesse_Tournant);
}
//Fonction pour faire pivoter le robot a droite
void tournerDroite()
{
  //On arrete le moteur droit et on fait fonctionner le moteur gauche a petite vitesse
  Moteur_Propulsion_Gauche.drive(Grande_Vitesse_Tournant);
  Moteur_Propulsion_Droite.drive(Petite_Vitesse_Tournant);
}
//Fonction pour arreter le robot
void arreter()
{
  //On arrete les deux moteurs 
  Moteur_Propulsion_Gauche.stop();
  Moteur_Propulsion_Droite.stop();
}

//-------------------------------------------------
//Fonction d'execution du code
//-------------------------------------------------

void setup() {
  Serial.begin(9600);
  Wire.begin();
  delay(1000);

}

void loop() {
  byte lectureLigne = CapteurLigne.getPositionOffset();// Permet de lire les données obtenues par le capteur suivi de ligne, on obtient une valeur en base 10 de 0 à 15

  switch(lectureLigne)
  {
    //1001 : Cas du robot centré
      case 9 : 
        avancer();
        break;

    //Tout les cas de robot etant trop a gauche 
      case 8 : //0011
      case 12 : //0111
      case 14 : 
        tournerDroite();
      break;

    //Tout les cas de robot etant trop a droite
      case 1 : //1000 
      case 3 : //1100
      case 7 : //1110
        tournerGauche();
      break;

  //Cas de ligne pour arreter
    case : 0
      arreter();
      break;

    default : 
    arreter();
    break;
  }
  delay(10)
}
