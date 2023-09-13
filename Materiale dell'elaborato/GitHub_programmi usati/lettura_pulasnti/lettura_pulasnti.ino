int soglia = 5;
void setup() {
  Serial.begin(9600);
}
void loop() {
  int buttons = analogRead(A2);
  Serial.println(buttons);
  
  if ( (buttons > 203 - soglia) && (buttons < 203 + soglia) ){
    //Serial.println("1");
  } else if ( (buttons > 406 - soglia) && (buttons < 406 + soglia) ){
    //Serial.println("2");
  } else if ( (buttons > 610 - soglia) && (buttons < 610 + soglia) ){
    //Serial.println("3");
  } else if ( (buttons > 816 - soglia) && (buttons < 816 + soglia) ){
    //Serial.println("4");
  }
  
  delay(10);
}
