int bool_button_start = LOW;

void setup() {
  Serial.begin(9600);  
  pinMode(8, INPUT);
}

void loop() {
  if (digitalRead(8) == HIGH){
      bool_button_start =! bool_button_start;
      delay(50);
  } 
  Serial.println(bool_button_start);
}
