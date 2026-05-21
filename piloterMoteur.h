#ifndef PILOTERMOTEUR_H
#define PILOTERMOTEUR_H
#include <Arduino.h>
#include <Wire.h>
// Adresses trouvées par ton scanner
#define MOTEUR_A 0x66  //60
#define MOTEUR_B 0x68  //65 pour CA

// Commandes de direction pour le DRV8830
#define ARRET     0x00
#define AVANT     0x01
#define ARRIERE   0x02
#define FREIN     0x03

void piloterMoteur(byte adresse, byte direction, byte vitesse);

#endif

