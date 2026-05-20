#include "Ultrasonic.h"
#include <Wire.h>

#ifdef USE_TINYUSB
#include <Adafruit_TinyUSB.h>
#endif

// Adresses trouvées par ton scanner
#define MOTEUR_A 0x66  //60
#define MOTEUR_B 0x68  //65 pour CA

// Commandes de direction pour le DRV8830
#define ARRET     0x00
#define AVANT     0x01
#define ARRIERE   0x02
#define FREIN     0x03
#include <Servo.h>

Servo myservo;  // create Servo object to control a servo
// twelve Servo objects can be created on most boards

int pos = 0;    // variable pour la position du servomoteur
int vitesse = 10;    // variable pour la vitesse des moteur, pour lisser les rotation
long Dist;
Ultrasonic ultrasonic(A1); // Entrée du Capteur Ultrason definie au port analog A1

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Test Mini I2C Motor Driver (DRV8830)");
  myservo.attach(A0);  // attaches the servo on pin 9 to the Servo object
}

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

void Tunnel() {
  Dist = ultrasonic.MeasureInCentimeters(); // Distance en cm definie dans la variable "Distance"
  piloterMoteur(MOTEUR_A, ARRIERE, 40); // Vitesse 40/63
  piloterMoteur(MOTEUR_B, AVANT, 40);
  // Section 2
  if (){//mettre conditions pas de suivi de ligne et flag numero 2
    for (pos = 0; pos <= 180; pos += 1) { // va de 0 degrées a 180 degrées
      myservo.write(pos);              // dit au servomoteur d'aller a la positions definie dans la variable 'pos' donnée emise en angle 
      delay(15);                       
      Serial.println(Dist);
      if (Dist<=20 && pos<90 ){
        myservo.write(0);
        piloterMoteur(MOTEUR_B, AVANT, 10);
        while(Dist<20){
          piloterMoteur(MOTEUR_A, ARRIERE, vitesse); //Moteur A Doit etre en ARRIERE Pour aller en AVANT + Roue de Gauche
          vitesse = vitesse + 2
          delay(30)
        }
      }
      if (Dist<=20 && pos>90 ){
        myservo.write(180);
        piloterMoteur(MOTEUR_A, ARRIERE, 10); //Moteur A Doit etre en ARRIERE Pour aller en AVANT + Roue de Gauche
        while(Dist<20){
          piloterMoteur(MOTEUR_B, AVANT, vitesse);
          vitesse = vitesse + 2
          delay(30)
        }
      }
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);
      Serial.println(Dist);
      if (Dist<=20 && pos<90 ){
        myservo.write(0);
        piloterMoteur(MOTEUR_B, AVANT, 10);
        while(Dist<20){
          piloterMoteur(MOTEUR_A, ARRIERE, vitesse); //Moteur A Doit etre en ARRIERE Pour aller en AVANT + Roue de Gauche
          vitesse = vitesse + 2
          delay(30)
        }
      }
      if (Dist<=20 && pos>90 ){
        myservo.write(180);
        piloterMoteur(MOTEUR_A, ARRIERE, 10); //Moteur A Doit etre en ARRIERE Pour aller en AVANT + Roue de Gauche
        while(Dist<20){
          piloterMoteur(MOTEUR_B, AVANT, vitesse);
          vitesse = vitesse + 2
          delay(30)
        }
      }
    }
  }
  /*Section 3
  if (){//mettre conditions pas de suivi de ligne et flag numero 3
    myservo.write(90);
    if (Dist<30){
      piloterMoteur(MOTEUR_A, ARRIERE, 10); 
      piloterMoteur(MOTEUR_B, ARRIERE, 10);
      while(Dist>=30){}
      piloterMoteur(MOTEUR_A, ARRIERE, 10); 
      piloterMoteur(MOTEUR_B, AVANT, 10);
      if(Dist<30){
        piloterMoteur(MOTEUR_A, ARRIERE, 10); //Moteur A Doit etre en ARRIERE Pour aller en AVANT + Roue de Gauche
        while(Dist>30){
          piloterMoteur(MOTEUR_B, AVANT, vitesse);
          vitesse = vitesse + 2
          delay(30)
        }
      }

    }
  }*/  
}
