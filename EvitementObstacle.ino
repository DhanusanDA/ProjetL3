#include <Ultrasonic.h>               //Ajout de la bibliothèque pour lire les données du capteur à ultrason
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


Servo myservo;
MeRGBLineFollower LightSensorRGB_1(PORT_3);
int vitesse = 30;
volatile uint8_t pos = LightSensorRGB_1.getPositionState();
long DistanceObstacle ;
Ultrasonic ultrasonic(A1); // Entrée du Capteur Ultrason definie au port analog A0
bool FLAG1 = false;
bool FLAG2 = false;

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
void tournerGauche(int VitesseGauche, int VitesseDroite)
{
  //On diminue progresssivement le moteur gauche et on fait fonctionner le moteur droit a vitesse nominale
  //while (pos != 0b1001){
    piloterMoteur(MOTEUR_A, ARRIERE, VitesseGauche); 
    piloterMoteur(MOTEUR_B, AVANT, VitesseDroite);
    //vitesse = vitesse - 1;
    //delay(300);
  //}
}
//Fonction pour faire pivoter le robot a droite
void tournerDroite(int VitesseGauche, int VitesseDroite)
{
  //On diminue progresssivement le moteur droit et on fait fonctionner le moteur gauche a vitesse nominale
  //while (pos != 0b1001){
    piloterMoteur(MOTEUR_A, ARRIERE, VitesseGauche); 
    piloterMoteur(MOTEUR_B, AVANT, VitesseDroite);
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
//Fonction d'évitement d'obstacle
//-------------------------------------------------

void EvitementObstacle(int i)
{
  //Premier évitement d'obstacle
  if(i==1)
  {
    DistanceObstacle = ultrasonic.MeasureInCentimeters();
    Serial.println(DistanceObstacle);
    arreter();
    myservo.write(0);
    Serial.println("Servo 0");
    delay(1000);
    Serial.println("Pivotement");
    piloterMoteur(MOTEUR_A, AVANT, 25); 
    piloterMoteur(MOTEUR_B, AVANT, 25);
    delay(1000);
    while(DistanceObstacle>=25){
      DistanceObstacle = ultrasonic.MeasureInCentimeters();
      Serial.println(DistanceObstacle);
    }
    avancer();
    while(DistanceObstacle<=50)
    {
      DistanceObstacle = ultrasonic.MeasureInCentimeters();
      Serial.println(DistanceObstacle);
    }
    arreter();
    delay(100);
    tournerDroite(40, 15);
    while(DistanceObstacle>=35)
    {
      DistanceObstacle = ultrasonic.MeasureInCentimeters();
      Serial.println(DistanceObstacle);
    }
    avancer();
    while(DistanceObstacle<=50)
    {
      DistanceObstacle = ultrasonic.MeasureInCentimeters();
      Serial.println(DistanceObstacle);
    }
    delay(1000);
    piloterMoteur(MOTEUR_A, ARRIERE, 25); 
    piloterMoteur(MOTEUR_B, ARRIERE, 25);
    delay(1000);
    avancer();
    while(true){
    LightSensorRGB_1.updataAllSensorValue();       // mise à jour du capteur
    pos = LightSensorRGB_1.getPositionState();     // relecture de pos
    if (pos == 0b0000 || pos == 0b0001 || pos == 0b1000) break;
    }
    delay(200);
    arreter();
    piloterMoteur(MOTEUR_A, AVANT, 25); 
    piloterMoteur(MOTEUR_B, AVANT, 25);
    while(true){
    LightSensorRGB_1.updataAllSensorValue();       // mise à jour du capteur
    pos = LightSensorRGB_1.getPositionState();     // relecture de pos
    if (pos == 0b1001 ) break;
    }
  }

    if(i==2)
  {
    DistanceObstacle = ultrasonic.MeasureInCentimeters();
    Serial.println(DistanceObstacle);
    arreter();
    myservo.write(180);
    Serial.println("Servo 0");
    delay(1000);
    Serial.println("Pivotement");
    piloterMoteur(MOTEUR_A, ARRIERE, 25); 
    piloterMoteur(MOTEUR_B, ARRIERE, 25);
    delay(1000);
    while(DistanceObstacle>=25){
      DistanceObstacle = ultrasonic.MeasureInCentimeters();
      Serial.println(DistanceObstacle);
    }
    avancer();
    while(DistanceObstacle<=50)
    {
      DistanceObstacle = ultrasonic.MeasureInCentimeters();
      Serial.println(DistanceObstacle);
    }
    arreter();
    delay(100);
    tournerDroite(15, 40);
    while(DistanceObstacle>=37)
    {
      DistanceObstacle = ultrasonic.MeasureInCentimeters();
      Serial.println(DistanceObstacle);
    }
    avancer();
    while(DistanceObstacle<=50)
    {
      DistanceObstacle = ultrasonic.MeasureInCentimeters();
      Serial.println(DistanceObstacle);
    }
    piloterMoteur(MOTEUR_A, ARRIERE, 24); 
    piloterMoteur(MOTEUR_B, AVANT, 42);
    delay(1650);
    piloterMoteur(MOTEUR_A, ARRIERE, 32); 
    piloterMoteur(MOTEUR_B, AVANT, 27);
  }
  //Deuxième évitement d'obstacle 
 /*else if(i==2)
  {
    byte pos ;
        while((pos = LightSensorRGB_1.getPositionOffset())!=9)
        {
          Serial.println(".....");

        }
  }*/
}
//-------------------------------------------------
//Fonction de recuperation de ligne
//-------------------------------------------------


//-------------------------------------------------
//Fonction d'execution du code
//-------------------------------------------------

void setup() {
  Serial.begin(9600);
  Wire.begin();
  LightSensorRGB_1.begin();
  myservo.attach(A0);  // attaches the servo on pin 9 to the Servo object
  Serial.println("Initialisation terminée");
  delay(1000);
}

void loop() {
  
  DistanceObstacle = ultrasonic.MeasureInCentimeters(); // Permet de lire la distance du robot par rapport à un obstacle avec le capteur à ultrason
  myservo.write(90);
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
    piloterMoteur(MOTEUR_A, ARRIERE, 25); 
    piloterMoteur(MOTEUR_B, AVANT, 40);
  }
  // Tout les cas de robot etant trop a droite
  else if(pos == 0b1011){
    Serial.println("tournée à droite");
    piloterMoteur(MOTEUR_A, ARRIERE, 40); 
    piloterMoteur(MOTEUR_B, AVANT, 25);
  }

  // Tout les cas de robot etant trop a gauche
  else if(pos == 0b1100 || pos == 0b1110 || pos == 0b1000 ){
    Serial.println("tourner à gauche");
    tournerGauche(13, 40);
  }
  // Tout les cas de robot etant trop a droite
  else if(pos == 0b0001 || pos == 0b0011 || pos == 0b0111  ){
    Serial.println("tourner à droite");
    tournerDroite(40, 13);
    
  }
  // Cas où la ligne est pleine donc arret
  else if (pos == 0b0000){
    Serial.println("Arret");
    arreter();
  }


  // Flag
  else {
    Serial.print("Flag :");
  }

  //-------------------------------------------------
  //Evitement d'obstacle
  //-------------------------------------------------
  Serial.println(DistanceObstacle);
  if(DistanceObstacle <= 22 && FLAG1 == false)
  {
    Serial.println("Evitement");
    EvitementObstacle(1);
    FLAG1 = true;

  }
  if(DistanceObstacle <= 22 && FLAG2 == false)
  {
    Serial.println("Evitement");
    EvitementObstacle(2);
    FLAG2 = true;

  }

  delay(10);
}
