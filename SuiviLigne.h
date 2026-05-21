#ifndef SUIVILIGNE_H
#define SUIVILIGNE_H
#include <Arduino.h>
#include <MeRGBLineFollower.h>        //Ajout de la bibliothèque pour lire les données du capteur de suiveur de ligne 
#include "piloterMoteur.h"

extern MeRGBLineFollower LightSensorRGB_1;
extern int vitesse;

void avancer();
void tournerGauche();
void tournerDroite();
void grandetournerGauche();
void grandetournerDroite();
void arreter();
void SuiviLigne();

#endif