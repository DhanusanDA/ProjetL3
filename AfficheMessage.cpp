#include "Tunnel.h"
#include "AfficheMessage.h"

rgb_lcd lcd;
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;


void AfficherMessage() {
    lcd.setCursor(0, 0);
    lcd.print(Dist);
    lcd.setCursor(1, 0);
    lcd.print("Cm"); 
    delay(100);
}