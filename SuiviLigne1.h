#ifndef SUIVILIGNE_H
#define SUIVILIGNE_H
#include <Arduino.h>
#include <MeRGBLineFollower.h>        //Ajout de la bibliothèque pour lire les données du capteur de suiveur de ligne 
#include "piloterMoteur.h"

extern MeRGBLineFollower LightSensorRGB_1;
extern int vitesse;
extern uint8_t pos;

void avancer();
void tournerGauche();
void tournerDroite();
void tournerGaucheVariable(int VitesseGauche, int VitesseDroite);
void tournerDroiteVariable(int VitesseGauche, int VitesseDroite);
void moytournerGauche();
void moytournerDroite();
void grandetournerGauche();
void grandetournerDroite();
void arreter();
void SuiviLigne();

void avancer2();
void tournerGauche2();
void tournerDroite2();
void tournerGaucheVariable2(int VitesseGauche, int VitesseDroite);
void tournerDroiteVariable2(int VitesseGauche, int VitesseDroite);
void moytournerGauche2();
void moytournerDroite2();
void grandetournerGauche2();
void grandetournerDroite2();
void arreter2();
void SuiviLigne2();

#endif