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

#endif