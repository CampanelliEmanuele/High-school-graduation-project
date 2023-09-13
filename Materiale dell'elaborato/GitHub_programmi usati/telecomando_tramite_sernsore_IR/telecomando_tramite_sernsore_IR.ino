#include <IRremote.h>

int IRSensorPin = 2;
IRrecv irrecv(IRSensorPin);
decode_results res;

#define KY_OK 0
#define KY_NO 1
#define KY_UP 2
#define KY_DOWN 3
#define KY_NONE 4

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop(){
  L_IRsensor();
  readKeys();
}

void L_IRsensor(){ 
  if (irrecv.decode(&res)){
    Serial.println(res.value, HEX);
    irrecv.resume(); 
  }
  delay(100);
}

int readKeys() {  
  if (res.value == 0xFF9867) {            // OK = FF9867
    //Serial.println("OK");
    return KY_OK;
  } else if (res.value == 0xFFB04F) {      // NO = FFB04F
    //Serial.println("NO");
    return KY_NO;
  } else if (res.value == 0xFF906F) {      // UP = FF906F
    //Serial.println("UP");
    return KY_UP;
  } else if (res.value == 0xFFE01F) {      // DOWN = FFE01F
    //Serial.println("DOWN");
    return KY_DOWN;
  } else return KY_NONE; 
  
  delay(10);
}
