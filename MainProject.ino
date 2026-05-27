#include "Tunnel.h"
#include "SuiviLigne.h"
#include "piloterMoteur.h"
#include <MeOrion.h>
#include <Wire.h>
#include "DetecterCouleur.h"
#include "EvitementObstacle.h"
#include "RecupLigne.h"
#include "DemiTour.h"
#include "AfficheMessage.h"
#include "piloterTir.h"

//-------------------------------------------------
// Définition des flags qui permettent de séparer les différentes sections
//-------------------------------------------------
bool FLAG0 = false;   // Départ
bool FLAG1 = false;   // Section 2
bool FLAG2 = false;   // Section 3
bool FLAG3 = false;   // Section 4
bool FLAG4 = false;   // Section 5&6&7
bool FLAG5 = false;   // Section 10&11
bool FLAG6 = false;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Test Mini I2C Motor Driver (DRV8830)");
  myservo.attach(A0);  // attaches the servo on pin 9 to the Servo object
  LightSensorRGB_1.begin();


  
  strip.begin();
  strip.setBrightness(150);
  strip.show();
  tcs.begin();
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  Serial.println("Initialisation terminee");
  Dist = 100;
  delay(1000);
}

void loop(){
  /*
  //-------------------------------------------------
  //Départ
  //-------------------------------------------------

  while (FLAG0 == false){
    arreter();
    while(pos != 0b0000){
      LightSensorRGB_1.updataAllSensorValue();
      pos = LightSensorRGB_1.getPositionState();
    }
    avancer();
    delay(70);
    FLAG0=true;
  }

  //-------------------------------------------------
  //Traverser du tunnel - Section 2
  //-------------------------------------------------
  while(FLAG1==false){
    SuiviLigne();
    Serial.println(FLAG1);
    LightSensorRGB_1.updataAllSensorValue();
    pos = LightSensorRGB_1.getPositionState();
    if(pos == 0b1111){
    Serial.println("Tunnel");
    Tunnel();
    FLAG1 = true;
    }
  }

  //-------------------------------------------------
  //Evitement d'obstacle - Section 3&4
  //-------------------------------------------------
  while(FLAG3==false)
  {
    SuiviLigne();
    Dist = ultrasonic.MeasureInCentimeters();//M.a.j de Distance
    Serial.println(Dist);
    myservo.write(90);
    if(Dist <= 18 && FLAG2 == false && FLAG1 == true)
    {
      Serial.println("Evitement 1");
      EvitementObstacle(1);
      FLAG2 = true;
      Serial.println(FLAG2);
    }
    else if(Dist <= 15 && FLAG2 == true)
    {
      Serial.println("Evitement 2");
      EvitementObstacle(2);
      FLAG3 = true;
      Serial.println(FLAG3);

    }
  }

  //-------------------------------------------------
  //Detection de couleur et Demi-tour - Section 5&6&7
  //-------------------------------------------------
  while(FLAG4==false){
    myservo.write(90);
    SuiviLigne();
    Dist = ultrasonic.MeasureInCentimeters(); //M.a.j de Distance
    if (Dist<=14){
      arreter();
      DetecterCouleur();
      DemiTour();
      FLAG4 = true;
    }
  }

  //-------------------------------------------------
  //Tir au Panier - Section 10&11
  //-------------------------------------------------
  while(FLAG5==false){
    SuiviLigne();
    if (pos==0b0000){FLAG5 = true;}
  }
  */
  while(FLAG6 == false){
  piloterTir(MOTEUR_C, ARRIERE, 63);
  delay(4000);
  piloterTir(MOTEUR_C, ARRET, 63);
  piloterTir(MOTEUR_D, ARRIERE, 63);
  FLAG6 = true;
  }
}
