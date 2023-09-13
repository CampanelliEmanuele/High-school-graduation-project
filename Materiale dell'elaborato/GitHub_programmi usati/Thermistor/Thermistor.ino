int soglia;

void setup() {
  Serial.begin(9600);
  //pinMode(13, OUTPUT); // LED di verifica

  int v = analogRead(A3);
  delay(500);
  v += analogRead(A3);
  delay(500);
  v += analogRead(A3);
  delay(500);
  soglia = (v/3)+4;
  Serial.print("La soglia è: "); Serial.print(soglia);
}

void loop() {
  int v = analogRead(A3);

  digitalWrite(13, LOW);
  if (v > soglia){
    Serial.print("Soglia superata: "); Serial.println(v);
    //digitalWrite(13, HIGH);
  } else { Serial.print("Soglia NON superata: "); Serial.println(v); } 
  delay(50);
}
