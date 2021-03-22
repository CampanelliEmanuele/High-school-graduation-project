int pin = 19; // il numero 19 corrisponde al pin analogico A5

void setup() {
  pinMode(pin, OUTPUT); // si dichiara il pin come output
}

void loop() {                  // collegando un LED al pin in questione 
  digitalWrite(pin, HIGH);     // il LED viene acceso
  delay(500);                  // dopo mezzo secondo 
  digitalWrite(pin, LOW);      // spegne il LED
  delay(500);                  // dopo mezzo secondo ripartirà e lo riaccenderà
}
