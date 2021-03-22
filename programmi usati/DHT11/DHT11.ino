#include <SimpleDHT.h>
SimpleDHT11 dht11;

#include <LiquidCrystal.h>
LiquidCrystal lcd (7, 6, 5, 4, 3, 2);
bool FIRST = true;

byte t = 0;
byte h = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {

  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(9, &t, &h, NULL)) != SimpleDHTErrSuccess){
    Serial.println("ERR");
    delay(1000);
    return;
  }
  Serial.print("t: ");
  Serial.print((int)t);
  Serial.print("°C h: ");
  Serial.print((int)h);
  Serial.println("% ");
  delay(1500);
  
  lcd.clear(); 
  lcd.print("Temp: "); lcd.print(t); lcd.print(".C"); 
  lcd.setCursor(0,1);  
  lcd.print("Humidity: "); lcd.print(h); lcd.print("%");
}
