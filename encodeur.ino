#define A 5
#define B 6


int Etat_capteur_precedant;
int Etat_capteur;
int n_var=0;
int n_a=0;
int angle=0;


void setup() {
  Serial.begin(9600);

  pinMode(A, INPUT_PULLUP);
  pinMode(B, INPUT_PULLUP);

  Serial.println("Test encodeur optique sur D5");
  Etat_capteur_precedant = digitalRead(A);
  Serial.print("c_apres = ");
  Serial.println(Etat_capteur_precedant);



  angulaire();
}

  
void angulaire(){
    n_var=0;
    n_a=0;
    angle=0;
  while (angle<90)  //la ducoup on fait a vancer le robot pendant 7 cases
    {
      //fonction qui fait tourner la roue
      Etat_capteur = digitalRead(A);
      Serial.print("c_avant = ");
      Serial.println(Etat_capteur);
      Serial.print("c_apres = ");
      Serial.println(Etat_capteur_precedant);
      delay(1000);
      Serial.print("c_avant = ");
      Serial.println(Etat_capteur);
      if (Etat_capteur != Etat_capteur_precedant)
      {


        n_var ++;
        Etat_capteur_precedant = Etat_capteur;

       if(n_var==2)
       {
        n_a++;
        n_var=0;
       }
        angle=n_a*30;
        Serial.println(angle);
        delay(200);
      }
      Serial.print("n_var = ");
      Serial.println(n_var);
            Serial.print("n_a = ");
      Serial.println(n_a);
    }
}

void loop() {

  Etat_capteur = digitalRead(A);
  Serial.print("et = ");
  Serial.println(Etat_capteur);

  Serial.print("A = ");
  Serial.println(digitalRead(A));

  delay(1000);
}