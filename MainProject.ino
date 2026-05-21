#include "Tunnel.h"
#include "SuiviLigne.h"
#include "piloterMoteur.h"
#include <MeOrion.h>
#include <Wire.h>
#include "DetecterCouleur.h"

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Test Mini I2C Motor Driver (DRV8830)");
  myservo.attach(A0);  // attaches the servo on pin 9 to the Servo object
  LightSensorRGB_1.begin();
  Serial.println("Initialisation terminee");
  delay(1000);
}

void loop() {
  SuiviLigne();
  if (pos == 0b1111){
    Tunnel();
  }
}
