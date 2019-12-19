void setup()
{
  Serial.begin(9600);
}
  
enum EtatCourant {
   Initialisation,
   AttenteReponse,
} etat = Initialisation;
  
void loop()
{
  switch ( etat ) {
     case Initialisation:
        etat = AttenteReponse;
     break;
  
     case AttenteReponse:
         switch ( Serial.read() ) {
             case 'T':
                Serial.println("La température est de 25°C");
                etat = AttenteReponse;
             break;
             case -1:     // rien reçu il faut attendre
             case '\n':   // ignorer terminateur
              break;
             default:
                Serial.println("Erreur saisie");
             break;
         }
     break;
    }
}
