#include "EvitementObstacle.h"



void EvitementObstacle(int i)
{
  //Premier évitement d'obstacle
  if(i==1)
  {
    Dist = ultrasonic.MeasureInCentimeters();
    Serial.println(Dist);
    arreter();
    myservo.write(0);
    Serial.println("Servo 0");
    delay(1000);
    Serial.println("Pivotement");
    piloterMoteur(MOTEUR_A, AVANT, 25); 
    piloterMoteur(MOTEUR_B, AVANT, 25);
    delay(1000);
    while(Dist>=25){
      Dist = ultrasonic.MeasureInCentimeters();
      Serial.println(Dist);
    }
    avancer();
    while(Dist<=40)
    {
      Dist = ultrasonic.MeasureInCentimeters();
      Serial.println(Dist);
    }
    arreter();
    delay(100);
    tournerDroiteVariable(40, 15);
    while(Dist>=35)
    {
      Dist = ultrasonic.MeasureInCentimeters();
      Serial.println(Dist);
    }
    avancer();
    delay(100);
    while(Dist<=50)
    {
      Dist = ultrasonic.MeasureInCentimeters();
      Serial.println(Dist);
    }
    delay(1000);
    piloterMoteur(MOTEUR_A, ARRIERE, 25); 
    piloterMoteur(MOTEUR_B, ARRIERE, 25);

    delay(1000);
    avancer();
    RecupLigne(AVANT, AVANT);
  }

    if(i==2)
  {
    Dist = ultrasonic.MeasureInCentimeters();
    Serial.println(Dist);
    arreter();
    myservo.write(180);
    Serial.println("Servo 0");
    delay(1000);
    Serial.println("Pivotement");
    piloterMoteur(MOTEUR_A, ARRIERE, 25); 
    piloterMoteur(MOTEUR_B, ARRIERE, 25);
    delay(1000);
    while(Dist>=25){
      Dist = ultrasonic.MeasureInCentimeters();
      Serial.println(Dist);
    }
    avancer();
    while(Dist<=50)
    {
      Dist = ultrasonic.MeasureInCentimeters();
      Serial.println(Dist);
    }
    arreter();
    delay(100);
    tournerDroiteVariable(15, 40);
    while(Dist>=25)
    {
      Dist = ultrasonic.MeasureInCentimeters();
      Serial.println(Dist);
    }
    avancer();
     delay(30);
    while(Dist<=50)
    {
      Dist = ultrasonic.MeasureInCentimeters();
      Serial.println(Dist);
    }
    piloterMoteur(MOTEUR_A, ARRIERE, 39); 
    piloterMoteur(MOTEUR_B, AVANT, 42);
    RecupLigne(ARRIERE, ARRIERE);
  }
}