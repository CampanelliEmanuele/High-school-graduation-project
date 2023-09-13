int PWMled = 11; // pin del led gestito in PWM
int PWM_trimmer = A1; // pin del segnale del pitenziometro che gestirà in PWM

void setup() {
  Serial.begin(9600);
  pinMode(PWMled, OUTPUT); // il pin del led è un output
}

void loop() {
  int PWM_trimmer_value = analogRead(PWM_trimmer);  // si prende il valore del trimmer
  Serial.println(PWM_trimmer_value);  // lo si stampa 
  int PWMvalue = map(PWM_trimmer_value, 0, 1023, 0, 255); // lo si mappa (converte)
  analogWrite(PWMled, PWMvalue);   // lo si scrive sul led 
  delay(10); 
}
