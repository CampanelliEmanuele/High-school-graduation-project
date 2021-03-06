#ifndef characters_code_h
#define characters_code_h

byte arrow_0[8] = {     // Arrow down
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B11111,
  B01110,
  B00100
};

byte u[8] = {           // ù (u minuscola accentata)
  B01000,
  B00100,
  B10001,
  B10001,
  B10001,
  B10011,
  B01101,
  B00000
};

byte indicatore[8] = {  // *indicatore*Opzione 1 ...
  B00000,
  B11000,
  B11100,
  B11110,
  B11110,
  B11100,
  B11000,
  B00000
};

byte animazione_1[] = { // Freccia che indica di premere un pulsante 
  B00100,
  B10101,
  B01110,
  B00100,
  B00000,
  B01110,
  B11111,
  B10001
};

byte animazione_2[] = { // Pulsante premuto 
  B00100,
  B10101,
  B01110,
  B00100,
  B10001,
  B01010,
  B10001,
  B11111
};

#endif