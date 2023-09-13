#define DelayTime 10              // delay modificabile
#define SETPOINT 20               // range dell'errore, da modificare in base al valore desiderato

float Kp = 3;                     // costante proporionale, da modificare in base al valore desiderato
float Ki = 10;                    // costante integrativa, da modificare in base al valore desiderato
float Kd = 1;
int OutputPin = 11;               // pin modificabile a cui fornire il controllo calcolato
int InputPin = A0;

void setup() {
  Serial.begin(9600);             // inizzializza il monitor seriale
}

void loop() {
  int v = analogRead(InputPin);                       // variabile col valore rilevato dalla fotoresistenza
  float e = v - SETPOINT;                             // variabile d'errore, da modificare in base al valore desiderato
 
  int out = (int)(prop(e) + intgr(e) );     // calcola il valore del PI, tramite le rispettive funzione 
  out = map(out, 0, 510, 0, 255);                     // lo mappa
  out = constrain(out, 0, 255);                       // lo limita
  analogWrite(OutputPin, out);                        // lo scrive sul led
  Serial.println(e);                                  // mostra sul monitor seriale l'errore
  delay(DelayTime);                                   // aspetta una quantità di tempo decisa da noi
}

float prop(float e) {             // funzione per il calcolo del valore proporzionale
  float p = e*Kp;                 // calcola il valore proporzionale --> e*3
  return p;                       // lo restituisce
}

#define blen 100                  // lunghezza del buffer
float buf[blen];

float intgr(float e) {                     // funzione per il calcolo del valore integrativo
  buf[0] = e;                              // il primmo valore del buffer è l'errore
  for (int j = blen-1; j > 0; j--) {       // si crea un ciclo for in modo tale da far scorrere il valore dell'erroe
    buf[j] = buf[j-1];                     // alla posizione successica
  }
  float m = 0;                             // variabile che conterrà la media dei valori del buffer
  for (int j = 0; j < blen; j++){          // ciclo for usato per sommare tutti i valori del buffer ad m
    m += buf[j];                           // viene fatto il calcolo della media al posto dell'integrale perchè è più
  }                                        // semplice e il risultato ha variazioni trascurabili (in questo caso)
  m = m / (float)blen;                     // viene calcolata la media 
  float i = m*Ki;                          // la media viene moltiplicata per la costante integrativa --> m*10
  return i;                                // restituisce il valore
}

float deriv(float e){                                      // funzione per il calcolo del derivativo  
  float pervious_error = e;                                // si tiene in considerazione il valore precedeente dell'errore                    
  float d = Kd*((pervious_error - e) / DelayTime);         // si calcola la parte derivativa
  return d;                                                // restituisce il valore
}
