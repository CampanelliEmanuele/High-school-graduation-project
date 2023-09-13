int rotation_direction_1 = 12;  // primo pin dell'integrato L293 per gestire il senso di rotazione del motore
int rotation_direction_2 = 13;  // secondo pin ....
int Enable_L293 = 11; // pin del L293 per usare la gestione in PWM
int PWM_trimmer = A1; // pin del segnale del pitenziometro che gestirà in PWM
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4 , 3, 2); // lcd(rs, en, d4, d5, d6, d7)

void setup() {
  Serial.begin(9600);
  pinMode(Enable_L293, OUTPUT);
  pinMode(rotation_direction_1, OUTPUT);
  pinMode(rotation_direction_2, OUTPUT);
  lcd.begin(16,2);
  lcd.print("DC motor state:");  
  lcd.setCursor(0,1); lcd.print("ON --> WORK");  
}

void loop() { 
  int PWM_trimmer_value = analogRead(PWM_trimmer);  
  int PWMvalue = map(PWM_trimmer_value, 0, 1023, 0, 255);  
  analogWrite(Enable_L293, PWMvalue);    
  delay(10); 
  Serial.println(PWM_trimmer_value);
  
  if (PWM_trimmer_value < 101){  
    digitalWrite(rotation_direction_1, LOW);
    digitalWrite(rotation_direction_2, LOW);
  } else {
    digitalWrite(rotation_direction_1, HIGH);
    digitalWrite(rotation_direction_2, LOW);
  }

}
