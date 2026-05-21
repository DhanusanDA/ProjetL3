#ifndef TUNNEL_H
#define TUNNEL_H
#include "Ultrasonic.h"
#include <Wire.h>
#include "SuiviLigne.h"
#include "piloterMoteur.h"
#ifdef USE_TINYUSB
#include <Adafruit_TinyUSB.h>
#endif

extern Servo myservo;
extern long Dist;
extern uint8_t pos;
extern Ultrasonic ultrasonic;

void Tunnel();

#endif 