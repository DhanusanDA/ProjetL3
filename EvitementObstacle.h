#ifndef EVITEMENTOBSTACLE_H
#define EVITEMENTOBSTACLE_H

#include <Ultrasonic.h>               //Ajout de la bibliothèque pour lire les données du capteur à ultrason
#include <Wire.h>                     // Protocole I2C
#include <Arduino.h>
#include "piloterMoteur.h"
#include "Tunnel.h"
#include "SuiviLigne1.h"
#include "RecupLigne.h"

void EvitementObstacle(int i);

#endif