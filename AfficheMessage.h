#ifndef AFFICHEMESSAGE_H
#define AFFICHEMESSAGE_H
#include <Wire.h>
#include "rgb_lcd.h"

extern rgb_lcd lcd;

extern const int colorR;
extern const int colorG;
extern const int colorB;

void AfficherMessage();
#endif