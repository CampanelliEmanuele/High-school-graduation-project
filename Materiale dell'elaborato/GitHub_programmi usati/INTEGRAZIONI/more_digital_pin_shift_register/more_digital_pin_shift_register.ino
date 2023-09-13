const int clockPin = 13; // SH_CP   i pin dello shift register per la  
const int latchPin = 12; // ST_CP   gestione delle uscita dello shift register
const int dataPin = 11;  // ds

void setup() {
  pinMode(clockPin, OUTPUT);   // vengono dichiarati come output
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  digitalWrite(latchPin, LOW);                   // si disattiva il pin latch per scrivere sulle uscite Q0-Q7
  shiftOut(dataPin, clockPin, MSBFIRST, 0xff);   // il valore delle uscite viene scritto in esadecimare
  digitalWrite(latchPin, HIGH);                  // si attiva il pin latch dello shift register
}

void loop() {  
  
}
