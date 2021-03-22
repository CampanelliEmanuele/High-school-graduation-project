#include <IRremote.h>
IRrecv irrecv(10);
decode_results res;

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

int soglia = 5;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void loop(){
  int readKeys();
  L_IRsensor();
}
int readKeys() {
  int buttons = analogRead(A2);
  Serial.println(buttons);
  
  if ( ((buttons > 203 - soglia) && (buttons < 203 + soglia)) or (res.value == 0xFF9867) ){            // OK = FF9867
    Serial.println("OK");
    return KY_OK;
  } else if ( ((buttons > 406 - soglia) && (buttons < 406 + soglia)) or (res.value == 0xFFB04F) ){      // NO = FFB04F
    Serial.println("NO");
    return KY_NO;
  } else if ( ((buttons > 610 - soglia) && (buttons < 610 + soglia)) or (res.value == 0xFF906F) ){      // UP = FF906F
    Serial.println("UP");
    return KY_UP;
  } else if ( ((buttons > 816 - soglia) && (buttons < 816 + soglia)) or (res.value == 0xFFE01F) ){      // DOWN = FFE01F
    Serial.println("DOWN");
    return KY_DOWN;
  } else return KY_NONE; 
  
  delay(10);
}
void L_IRsensor(){ 
  if (irrecv.decode(&res)){
    Serial.println(res.value, HEX);
    irrecv.resume(); 
  }
  delay(100);
}
