#ifndef Special_Characters_h
#define Special_Characters_h

byte arrow_up[] = {   // arrow up 
  B00100,
  B01110,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};
byte arrow_down[] = {   // arrow down 
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B11111,
  B01110,
  B00100
};
byte u[] = {   // u minuscola accentata --> ù
  B01000,
  B00100,
  B10001,
  B10001,
  B10001,
  B10011,
  B01101,
  B00000
};
byte indicatore[] = {   // *indicatore*Opzione 1 ...
  B00000,
  B11000,
  B11100,
  B11110,
  B11110,
  B11100,
  B11000,
  B00000
};
byte grado[] = { // °
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000
};
byte animazione_1[] = { // animazione indicazione di premere il pulsante
  B00100,
  B10101,
  B01110,
  B00100,
  B00000,
  B01110,
  B11111,
  B10001
};
byte animazione_2[] = { // animazione pulsante premuto
  B00100,
  B10101,
  B01110,
  B00100,
  B10001,
  B01010,
  B10001,
  B11111
};
byte ohm[] = { // simbolo ohm --> Ω
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01010,
  B11011,
  B00000
};

#endif
