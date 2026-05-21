#include "Tunnel.h"
#include "piloterMoteur.h"

Servo myservo;
long Dist = 0;
int posservo = 0;    // variable pour la position du servomoteur


Ultrasonic ultrasonic(A1);

void Tunnel(){
  Dist = ultrasonic.MeasureInCentimeters(); // Distance en cm definie dans la variable "Distance"
  piloterMoteur(MOTEUR_A, ARRIERE, 30); // Vitesse 40/63
  piloterMoteur(MOTEUR_B, AVANT, 30);
  myservo.write(0);              // dit au servomoteur d'aller a la positions definie dans la variable 'pos' donnée emise en angle 
  delay(30);                       
  Serial.println(Dist);
  Dist = ultrasonic.MeasureInCentimeters();
  if(Dist<=22){
  piloterMoteur(MOTEUR_A, ARRIERE, 20); // Vitesse 40/63
  piloterMoteur(MOTEUR_B, AVANT, 30);
  }
  if(Dist>=25){
  piloterMoteur(MOTEUR_A, ARRIERE, 30); // Vitesse 40/63
  piloterMoteur(MOTEUR_B, AVANT, 20);
  }
  if(Dist<=15){
  piloterMoteur(MOTEUR_A, ARRIERE, 10); // Vitesse 40/63
  piloterMoteur(MOTEUR_B, AVANT, 30);
  }
  if(Dist>=35){
  piloterMoteur(MOTEUR_A, ARRIERE, 30); // Vitesse 40/63
  piloterMoteur(MOTEUR_B, AVANT, 10);
  }

  // Section 2
  //if (){//mettre conditions pas de suivi de ligne et flag numero 2
  /*for (posservo = 30; posservo <= 150; posservo += 30) { // va de 0 degrées a 180 degrées
      myservo.write(posservo);              // dit au servomoteur d'aller a la positions definie dans la variable 'pos' donnée emise en angle 
      delay(30);                       
      Serial.println(Dist);
      Dist = ultrasonic.MeasureInCentimeters();
      if (Dist<= 20 && posservo<90 ){
        Dist = ultrasonic.MeasureInCentimeters();
        myservo.write(0);
        piloterMoteur(MOTEUR_A, ARRIERE, 5); //Moteur A Doit etre en ARRIERE Pour aller en AVANT + Roue de Gauche
        piloterMoteur(MOTEUR_B, AVANT, 30);
      }
      if (Dist<=20 && posservo>90 ){
        Dist = ultrasonic.MeasureInCentimeters();
        myservo.write(180);
        piloterMoteur(MOTEUR_A, ARRIERE, 30); //Moteur A Doit etre en ARRIERE Pour aller en AVANT + Roue de Gauche
        piloterMoteur(MOTEUR_B, AVANT, 5);
      }
      if (Dist<=35 && posservo<90 ){
        Dist = ultrasonic.MeasureInCentimeters();
        myservo.write(0);
        piloterMoteur(MOTEUR_A, ARRIERE, 25); //Moteur A Doit etre en ARRIERE Pour aller en AVANT + Roue de Gauche
        piloterMoteur(MOTEUR_B, AVANT, 40);
      }
      if (Dist<=35 && posservo>90 ){
        Dist = ultrasonic.MeasureInCentimeters();
        myservo.write(180);
        piloterMoteur(MOTEUR_A, ARRIERE, 40); //Moteur A Doit etre en ARRIERE Pour aller en AVANT + Roue de Gauche
        piloterMoteur(MOTEUR_B, AVANT, 25);
      }
    }

    for (posservo = 150; posservo >= 30; posservo -= 15) { // goes from 180 degrees to 0 degrees
      myservo.write(posservo);              // tell servo to go to position in variable 'pos'
      delay(150);
      Serial.println(Dist);
      Dist = ultrasonic.MeasureInCentimeters();
      if (Dist<=20 && pos<90 ){
        Dist = ultrasonic.MeasureInCentimeters();
        myservo.write(0);
        piloterMoteur(MOTEUR_A, ARRIERE, 5); //Moteur A Doit etre en ARRIERE Pour aller en AVANT + Roue de Gauche
        piloterMoteur(MOTEUR_B, AVANT, 30);
      }
      if (Dist<=20 && posservo>90 ){
        Dist = ultrasonic.MeasureInCentimeters();
        myservo.write(180);
        piloterMoteur(MOTEUR_A, ARRIERE, 30); //Moteur A Doit etre en ARRIERE Pour aller en AVANT + Roue de Gauche
        piloterMoteur(MOTEUR_B, AVANT, 5);
      }
      if (Dist<=35 && posservo<90 ){
        Dist = ultrasonic.MeasureInCentimeters();
        myservo.write(0);
        piloterMoteur(MOTEUR_A, ARRIERE, 25); //Moteur A Doit etre en ARRIERE Pour aller en AVANT + Roue de Gauche
        piloterMoteur(MOTEUR_B, AVANT, 40);
      }
      if (Dist<=35 && posservo>90 ){
        Dist = ultrasonic.MeasureInCentimeters();
        myservo.write(180);
        piloterMoteur(MOTEUR_A, ARRIERE, 40); //Moteur A Doit etre en ARRIERE Pour aller en AVANT + Roue de Gauche
        piloterMoteur(MOTEUR_B, AVANT, 25);
      }
    }*/
}
