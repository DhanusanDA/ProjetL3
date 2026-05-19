#include <Wire.h>                     // Protocole I2C
#include <Arduino.h>
#include <MeOrion.h>
#include <MeRGBLineFollower.h>        //Ajout de la bibliothèque pour lire les données du capteur de suiveur de ligne 

// Adresses trouvées par ton scanner
#define MOTEUR_A 0x66  //60
#define MOTEUR_B 0x68  //65 pour CA

// Commandes de direction pour le DRV8830
#define ARRET     0x00
#define AVANT     0x01
#define ARRIERE   0x02
#define FREIN     0x03

MeRGBLineFollower LightSensorRGB_1(PORT_3);
int vitesse = 30;
uint8_t pos = LightSensorRGB_1.getPositionState();

//-------------------------------------------------
//Fonctions permettant de faire bouger le robot
//-------------------------------------------------

// Fonction pour piloter un moteur
void piloterMoteur(byte adresse, byte direction, byte vitesse) {
  // La vitesse sur ce module va de 0 à 63 (6 bits)
  if (vitesse > 63) vitesse = 63;
 
  // Le registre de contrôle est 0x00
  // On combine la vitesse et la direction dans un seul octet
  byte commande = (vitesse << 2) | direction;
 
  Wire.beginTransmission(adresse);
  Wire.write(0x00);      // Registre de contrôle
  Wire.write(commande);  // Valeur vitesse + direction
  Wire.endTransmission();
}

//Fonction pour faire avancer le robot tout droit 
void avancer() 
{
  //On met les deux moteurs a la même vitesse de rotation
  piloterMoteur(MOTEUR_A, ARRIERE, 30); 
  piloterMoteur(MOTEUR_B, AVANT, 30);
}
//Fonction pour faire pivoter le robot a gauche
void tournerGauche()
{
  //On diminue progresssivement le moteur gauche et on fait fonctionner le moteur droit a vitesse nominale
  //while (pos != 0b1001){
    piloterMoteur(MOTEUR_A, ARRIERE, 28); 
    piloterMoteur(MOTEUR_B, AVANT, 45);
    //vitesse = vitesse - 1;
    //delay(300);
  //}
}
//Fonction pour faire pivoter le robot a droite
void tournerDroite()
{
  //On diminue progresssivement le moteur droit et on fait fonctionner le moteur gauche a vitesse nominale
  //while (pos != 0b1001){
    piloterMoteur(MOTEUR_A, ARRIERE, 35); 
    piloterMoteur(MOTEUR_B, AVANT, 18);
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

void setup() {
  Serial.begin(9600);
  Wire.begin();
  LightSensorRGB_1.begin();
  Serial.println("Initialisation terminee");
  delay(1000);
}

void loop() {
  LightSensorRGB_1.updataAllSensorValue();
  pos = LightSensorRGB_1.getPositionState();
  Serial.println(pos, BIN);

  // Cas du  robot centré
  if(pos == 0b1001){ 
    Serial.println("avancer");
    avancer();
  }
  // Tout les cas de robot etant trop a gauche
  else if(pos == 0b1100 || pos == 0b1110 || pos == 0b1000 || pos == 1101 ){
    Serial.println("tournée à gauche");
    tournerGauche();
  }
  // Tout les cas de robot etant trop a droite
  else if(pos == 0b0001 || pos == 0b0011 || pos == 0b0111 || pos == 1011 ){
    Serial.println("tournée à droite");
    tournerDroite();
  }
  // Cas où la ligne est pleine donc arret
  else if (pos == 0b0000){
    Serial.println("arret");
    arreter();
  }
  // Flag
  else if (pos == 0b0000){
    Serial.println("flag");
  }
  delay(10);
}
