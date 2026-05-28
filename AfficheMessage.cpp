#include "Tunnel.h"

#include "AfficheMessage.h"

rgb_lcd lcd;
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;


void AfficherMessage() {
    DistTir = ultrasonic.MeasureInCentimeters();
    if (DistTir<100){
    lcd.setCursor(0, 0);
    lcd.print(DistTir);
    lcd.setCursor(1, 0);
    lcd.print("Cm"); 
    delay(100);
    }
    else if (DistTir>=100){
    lcd.setCursor(0, 0);
    lcd.print(DistTir/100);
    lcd.setCursor(1, 0);
    lcd.print("m"); 
    delay(100);
    }
}