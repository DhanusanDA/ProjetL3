#ifndef PILOTERTIR_H
#define PILOTERTIR_H
#include <Arduino.h>
#include <Wire.h>
// Adresses trouvées par ton scanner
#define MOTEUR_C 0x60  //60 gros moteur
#define MOTEUR_D 0x65  //65 petit moteur

// Commandes de direction pour le DRV8830
#define ARRET     0x00
#define AVANT     0x01
#define ARRIERE   0x02
#define FREIN     0x03

void piloterTir(byte adresse, byte direction, byte vitesse);

#endif

