#define DelayTime 10       // delay modificabile
#define SetPoint 20        // range dell'errore, da modificare in base al valore desiderato

#define InputPin A0        // pin di input de sensore
#define OutputPin 13       // pin su cui mandare il segnale, in questo caso un sempplie LED

float Kp = 1;              // Valore arbitrario
float Ki = 1;              // Valore arbitrario
float Kd = 1;              // Valore arbitrario

int PreviousError = 0;
int integral = 0; 

void setup() {
  Serial.begin(9600);             // inizzializza il monitor seriale
}

void loop() {
  float MeasureValue = analogRead(InputPin);
  float e = SetPoint - MeasureValue;
  float integral = integral + e*DelayTime;
  float derivative = (e - PreviousError)/DelayTime;
  float OutputValue = Kp*e + Ki*integral + Kd*derivative;
  PreviousError = e;
  OutputValue = map(OutputValue, 0, /*valore circa massimo*/1000, 0,255); 
  OutputValue = constrain(OutputValue, 0, 255);
  analogWrite(OutputPin,OutputValue);
  delay(DelayTime);
}
