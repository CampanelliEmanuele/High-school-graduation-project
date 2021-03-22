#ifndef lcd_h
#define lcd_h

#define KY_OK 0
#define KY_NO 1
#define KY_UP 2
#define KY_DOWN 3
#define KY_NONE 4
                        // DOWN UP OK START
#define TH_OK 203       // o o o x
#define TH_NO 406       // o o x o
#define TH_UP 610       // o x o o
#define TH_DOWN 765     // x o o o 
#define TH_NONE 1023

int soglia = 15;

int readKeys(){
  int buttons = analogRead(A2);
  Serial.println(buttons);
  if ( (buttons > 200 - soglia) && (buttons < 200 + soglia) ){
    Serial.println("1");
    return KY_OK;
  } else if ( (buttons > 402 - soglia) && (buttons < 402 + soglia) ){
    Serial.println("2");
    return KY_NO;
  } else if ( (buttons > 603 - soglia) && (buttons < 603 + soglia) ){
    Serial.println("3");
    return KY_UP;
  } else if ( (buttons > 809 - soglia) && (buttons < 809 + soglia) ){
    Serial.println("4");
    return KY_DOWN;
  } else return KY_NONE;
  
}

#endif
