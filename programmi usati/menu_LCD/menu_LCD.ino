#include"lcd.h"
#include"Special_Characters.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4 , 3, 2); // lcd(rs, en, d4, d5, d6, d7)

int stato = 0; 
bool FIRST = true;
int bool_button_start = LOW;

int temperature_value = 0;
int humidity_value = 0;
int thermistor_T = 0;
int photoresistor_V = 0;
bool bool_DHT11 = false; // bolean variable too se the DHT11's state
bool bool_thermistor = false; // bolean variable too se the thermistor's state
bool bool_photoresistor = false; // bolean variable too se the photoresistor's state
bool bool_motor = false; // bolean variable too se the motor's state
bool bool_PWM = false;

void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT);
  S_LCD();
  S_sc();  // caratteri speciali
}

void loop() {
  if (digitalRead(8) == HIGH){
    bool_button_start =! bool_button_start;
    delay(50); } 
  while (bool_button_start == HIGH){ 
    Serial.print("alto"); 
    L_LCD();
    if (digitalRead(8) == HIGH){
    bool_button_start =! bool_button_start;
    delay(50); }
    if (bool_button_start == LOW){ 
      FIRST = true;
      lcd.clear();
      break;
    } 
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void S_LCD(){
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.clear();
}
void L_LCD(){
  switch(stato){
    case 0:
      press_button();
      break;
    case 1:
      start_system();
      break;
//********************************************************
      case 10:
        component_list();
        break; 
      case 11:
        CL1_DHT11();
        break;
      case 12:
        CL2_thermistor();
        break;
      case 13:
        CL3_photoresistor();
      case 14:
        CL4_motor();
        break;
      case 15:
        CL5_IRsensor();
        break;  
      case 16:
        CL6_L293DNE();
        break;
      case 17:
        CL7_LCD_display();
        break;
      case 18:
        CL8_trimmers();
        break;
//********************************************************
    case 20:
      output_components();
      break;
    case 21:
      OC1_DHT11();
      break;
    case 22:
      S_OC1_DHT11();
      break;
    case 23:
      OC2_thermistor();
      break;
    case 24:
      S_OC2_thermistor();
      break;
    case 25:
      OC3_photoresistor();
      break;
    case 26:
      S_OC3_photoresistor();
      break;
    case 27:
      OC4_motor();
      break;
    case 28:
      S_OC4_motor();
      break;
    case 29:
      OC5_PWM();
      break;
    case 30:
      S_OC5_PWM();
      break;
//********************************************************
    case 40:
      on_off_components();
      break;
    case 41:
      NFC1_DHT11();
      break;
    case 42:
      S_NFC1_DHT11();
      break;
    case 43:
      NFC2_thermistor();
      break;
    case 44:
      S_NFC2_thermistor();
      break;
    case 45:
      NFC3_photoresistor();
      break;
    case 46:
      S_NFC3_photoresistor();
      break;
    case 47:
      NFC4_motor();
      break;
    case 48:
      S_NFC4_motor();
      break;
//********************************************************
    case 60:
      shutdown_system();
      break;
    case 61:
      confirm_shutdown_system();
      break;
  }
}
void S_sc(){
  lcd.createChar(1, arrow_up);
  lcd.createChar(2, arrow_down);
  lcd.createChar(3, indicatore);
  lcd.createChar(4, u);
  lcd.createChar(5, grado);
  lcd.createChar(6, animazione_1);
  lcd.createChar(7, animazione_2);
  lcd.createChar(8, ohm);
}
void lcd_set(){
  lcd.clear();
  lcd.setCursor(0,0);
}
void arrow_up_func(){
  lcd.setCursor(15,0);
  lcd.write(byte(1));
}
void arrow_down_func(){
  lcd.setCursor(15,1);
  lcd.write(byte(2));
}
void indicator(){
  lcd.setCursor(0,1);
  lcd.write(byte(3));
}
void setStato(int s){
  stato = s;
  FIRST = true;
  lcd.clear();
  delay(300);
} 
void setStato(bool a){

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void press_button(){          // 0
  if (FIRST){
    lcd_set();
    lcd.print("Press a button");
    FIRST = false;     
  }
  int key = readKeys();
  switch(key){
    case KY_OK:
      setStato(1);
    break;
    case KY_NO:
      setStato(1);
    break;
    case KY_UP:
      setStato(1);
    break;
    case KY_DOWN:
      setStato(1);
    break;
  }
}
void start_system(){          // 1
  if (FIRST){
    lcd_set();
    lcd.print("Start sistem:");
    lcd.setCursor(0,1); lcd.print("    YES   NO");
    FIRST = false;     
  }
  int key = readKeys();
  switch(key){
    case KY_OK:
      setStato(10);
    break;
    case KY_NO:
      setStato(0);
    break;
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void component_list(){      // 10
  if (FIRST){
    lcd_set();
    lcd.print("Options men"); lcd.write(byte(4)); lcd.print(":");
    lcd.setCursor(0,1); indicator(); lcd.print("Component list"); arrow_down_func();
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_OK:
      setStato(11);
      break;
    case KY_DOWN:
    setStato(20);
      break;
  }
}
void CL1_DHT11(){       //11
  if (FIRST){
    lcd_set();
    lcd.print("Components used:");  
    lcd.setCursor(0,1); lcd.print("DHT11 sensor"); arrow_down_func();
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(10);
      break;
    case KY_DOWN:
    setStato(12);
      break;
  }
}
void CL2_thermistor(){        //12
  if (FIRST){
    lcd_set();
    lcd.print("DHT11"); arrow_up_func();
    lcd.setCursor(0,1); lcd.print("Thermistor"); arrow_down_func();
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(10);
      break;
    case KY_UP:
      setStato(11);
      break;
    case KY_DOWN:
    setStato(13);
      break;
  }
}
void CL3_photoresistor(){        //13
  if (FIRST){
    lcd_set();
    lcd.print("Thermistor"); arrow_up_func();
    lcd.setCursor(0,1); lcd.print("Photoresistor"); arrow_down_func();   
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(10);
      break;
    case KY_UP:
      setStato(12);
      break;
    case KY_DOWN:
    setStato(14);
      break;
  }  
}
void CL4_motor(){                       //14
  if (FIRST){
    lcd_set();
    lcd.print("Photoresistor"); arrow_up_func();
    lcd.setCursor(0,1);  lcd.print("DC motor"); arrow_down_func();
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(10);
      break;
    case KY_UP:
      setStato(13);
      break;
    case KY_DOWN:
      setStato(15);
      break;
  }
}
void CL5_IRsensor(){                    // 15
  if (FIRST){
    lcd_set();
    lcd.print("DC motor"); arrow_up_func();
    lcd.setCursor(0,1);  lcd.print("IR sensor"); arrow_down_func();
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(10);
      break;
    case KY_UP:
      setStato(14);
      break;
    case KY_DOWN:
      setStato(16);
      break;
  }
}
void CL6_L293DNE(){                     // 16
  if (FIRST){
    lcd_set();
    lcd.print("IR sensor"); arrow_up_func();
    lcd.setCursor(0,1);  lcd.print("IC L293DNE"); arrow_down_func();
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(10);
      break;
    case KY_UP:
      setStato(15);
      break;
    case KY_DOWN:
      setStato(17);
      break;
  }
}
void CL7_LCD_display(){                 // 17
  if (FIRST){
    lcd_set();
    lcd.print("IC L293DNE"); arrow_up_func();
    lcd.setCursor(0,1);  lcd.print("LCD display16x2"); arrow_down_func();
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(10);
      break;
    case KY_UP:
      setStato(16);
      break;
    case KY_DOWN:
      setStato(18);
      break;
  }
}
void CL8_trimmers(){                    // 18
  if (FIRST){
    lcd_set();
    lcd.print("LCD display 16x2"); arrow_up_func();
    lcd.setCursor(0,1);  lcd.print("Trimmer x2 10K"); lcd.write(byte(8));
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(10);
      break;
    case KY_UP:
      setStato(17);
      break;
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void output_components(){               // 20
  if (FIRST){
    lcd_set();
    lcd.print("Component list"); arrow_up_func();
    lcd.setCursor(0,1); indicator(); lcd.print("System outputs"); arrow_down_func();
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_UP:
      setStato(10);
      break;
    case KY_DOWN:
      setStato(40);
      break;
    case KY_OK:
      setStato(21);
      break;
  }
}
void OC1_DHT11(){                       // 21
  if (FIRST){
    lcd_set();
    lcd.print("Outputs value:"); 
    lcd.setCursor(0,1); indicator(); lcd.print("DHT11 sensor"); arrow_down_func();
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(20);
      break;
    case KY_OK:
      setStato(22);
      break;
    case KY_DOWN:
      setStato(23);
      break;
  }  
}
void S_OC1_DHT11(){                     // 22
  if (FIRST){ 
    lcd_set();  
    lcd.print("Temp: ");
    lcd.setCursor(0,1); lcd.print("Humidity: ");
    FIRST = false;
  } 
  if (bool_DHT11 == true){
     lcd.setCursor(6,0); lcd.print(temperature_value); lcd.write(byte(5)); lcd.print("C");
     lcd.setCursor(10,1); lcd.print(humidity_value); lcd.print("%");
  } else {
    lcd.setCursor(6,0); lcd.print("NONE");
    lcd.setCursor(10,1); lcd.print("NONE");
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(21);
      bool_DHT11 = false;
      break;
    case KY_OK:
      setStato(21);
      bool_DHT11 = true;
      break;
  }    
}
void OC2_thermistor(){                  // 23
  if (FIRST){
    lcd_set();
    lcd.print("DHT11 sensor"); arrow_up_func();
    lcd.setCursor(0,1); indicator(); lcd.print("Thermistor"); arrow_down_func();
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(20);
      break;
    case KY_UP:
      setStato(21);
      break;
    case KY_OK:
      setStato(24);
      break;
    case KY_DOWN:
      setStato(25);
      break;
  }   
}
void S_OC2_thermistor(){                // 24 
  if (FIRST){
    lcd_set();
    lcd.print("Thermistor"); 
    lcd.setCursor(0,1); lcd.print("Value: "); 
    FIRST = false;
  }
  if (bool_thermistor == true){
    int thermistor_value = analogRead(A3);
    lcd.setCursor(7,1); lcd.print(thermistor_value);
    delay(200);  
  } else {
    lcd.setCursor(7,1); lcd.print("NONE");
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(23);
      bool_thermistor = false;
      break;
    case KY_OK:
      setStato(23);
      bool_thermistor = true;
      break;
  }    
}
void OC3_photoresistor(){               // 25
  if (FIRST){
    lcd_set();
    lcd.print("Thermistor"); arrow_up_func();
    lcd.setCursor(0,1); indicator(); lcd.print("Photoresistor"); arrow_down_func();
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(20);
      break;
    case KY_UP:
      setStato(23);
      break;
    case KY_OK:
      setStato(26);
      break;
    case KY_DOWN:
      setStato(27);
      break;
  } 
}
void S_OC3_photoresistor(){             // 26
  if (FIRST){
    lcd_set();
    lcd.print("Photoresistor"); 
    lcd.setCursor(0,1); lcd.print("Value: ");   
    FIRST = false;
  }
  if (bool_photoresistor == true){
    int photoresistor_value = analogRead(A0);
    lcd.setCursor(7,1); lcd.print(photoresistor_value);
    delay(10);  
  } else {
    lcd.setCursor(7,1); lcd.print("NONE");
  }
  
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(25);
      bool_photoresistor = false;
      break;
    case KY_OK:
      setStato(25);
      bool_photoresistor = true;
      break;
  }    
}
void OC4_motor(){                       // 27
  if (FIRST){
    lcd_set();
    lcd.print("Photoresistor"); arrow_up_func();
    lcd.setCursor(0,1); indicator(); lcd.print("DC motor"); arrow_down_func();
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(20);
      break;
    case KY_UP:
      setStato(25);
      break;
    case KY_OK:
      setStato(28);
      break;
    case KY_DOWN:
      setStato(29);
      break;
  }   
}
void S_OC4_motor(){                     // 28
  if (FIRST){
    lcd_set();
    lcd.print("DC motor state:"); 
    lcd.setCursor(0,1); if (bool_motor == true){ lcd.print("ON --> WORK"); } else lcd.print("OFF --> NOT WORK"); 
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(27);
      bool_motor = false;
      break;
    case KY_OK:
      setStato(27);
      bool_motor = true;
      break;
  }    
}
void OC5_PWM(){                         // 29
  if (FIRST){
    lcd_set();
    lcd.print("DC motor"); arrow_up_func();
    lcd.setCursor(0,1); indicator(); lcd.print("PWM"); 
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(20);
      break;
    case KY_UP:
      setStato(27);
      break;
    case KY_OK:
      setStato(30);
      break;
  }   
}
void S_OC5_PWM(){                       // 30
  if (FIRST){
    lcd_set();
    lcd.print("PWM state:"); if (bool_PWM == true){ lcd.print("ON"); } else lcd.print("OFF");
    lcd.setCursor(0,1); if (bool_PWM == true){ lcd.print("ON --> WORK"); } else lcd.print("OFF --> NOT WORK"); 
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(29);
      bool_PWM = false;
      break;
    case KY_OK:
      setStato(29);
      bool_PWM = true;
      break;
  }    
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void on_off_components(){         //40
  if (FIRST){
    lcd_set();
    lcd.print("System outputs"); arrow_up_func();
    lcd.setCursor(0,1); indicator(); lcd.print("ON/OFF comp."); arrow_down_func();
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_UP:
      setStato(20);
      break;
    case KY_OK:
      setStato(41);
      break;
    case KY_DOWN:
      setStato(60);
      break;
  } 
}
void NFC1_DHT11(){         //41
  if (FIRST){
    lcd_set();
    lcd.print("ON/OFF components:");
    lcd.setCursor(0,1); indicator(); lcd.print("DHT11 sensor"); arrow_down_func();
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(40);
      break;
    case KY_OK:
      setStato(42);
      break;
    case KY_DOWN:
      setStato(43);
      break;
  }   
}
void S_NFC1_DHT11(){         //42
  if (FIRST){
    lcd_set();
    lcd.print("DHT11 sensor:"); if (bool_DHT11==true){ lcd.print("ON"); } else lcd.print("OFF");
    lcd.setCursor(0,1); lcd.print("Set:   ON   OFF"); 
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_OK:
      setStato(41);
      break;
    case KY_NO:
      setStato(41);
      break;
  }   
}
void NFC2_thermistor(){         //43
  if (FIRST){
    lcd_set();
    lcd.print("DHT11 sensor"); arrow_up_func();
    lcd.setCursor(0,1); indicator(); lcd.print("Thermistor"); arrow_down_func();
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(40);
      break;
    case KY_UP:
      setStato(41);
      break;
    case KY_OK:
      setStato(44);
      break;
    case KY_DOWN:
      setStato(45);
      break;
  }   
}
void S_NFC2_thermistor(){         //44
  if (FIRST){
    lcd_set();
    lcd.print("Thermistor: "); if (bool_thermistor==true){ lcd.print("ON"); } else lcd.print("OFF");
    lcd.setCursor(0,1); lcd.print("Set:   ON   OFF");
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_OK:
      setStato(43);
      break;
    case KY_NO:
      setStato(43);
      break;
  }    
}
void NFC3_photoresistor(){         //45
  if (FIRST){
    lcd_set();
    lcd.print("Thermistor"); arrow_up_func();
    lcd.setCursor(0,1); indicator(); lcd.print("Photoresistor"); arrow_down_func();
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(40);
      break;
    case KY_UP:
      setStato(43);
      break;
    case KY_OK:
      setStato(46);
      break;
    case KY_DOWN:
      setStato(47);
      break;
  }   
}
void S_NFC3_photoresistor(){         //46
  if (FIRST){
    lcd_set();
    lcd.print("Photoresistor: "); if (bool_photoresistor==true){ lcd.print("ON"); } else lcd.print("OFF");
    lcd.setCursor(0,1); lcd.print("Set:   ON   OFF"); 
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_OK:
      setStato(45);
      break;
    case KY_NO:
      setStato(45);
      break;
  }    
}
void NFC4_motor(){         //47
  if (FIRST){
    lcd_set();
    lcd.print("Photoresistor"); arrow_up_func();
    lcd.setCursor(0,1); indicator(); lcd.print("DC motor"); arrow_down_func();
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(40);
      break;
    case KY_UP:
      setStato(45);
      break;
    case KY_OK:
      setStato(48);
      break;
  }   
}
void S_NFC4_motor(){                    // 48
  if (FIRST){
    lcd_set();
    lcd.print("DC motor: "); if (bool_motor==true){ lcd.print("ON"); } else lcd.print("OFF");
    lcd.setCursor(0,1); lcd.print("Set:   ON   OFF"); 
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_OK:
      setStato(47);
      bool_motor=true;
      break;
    case KY_NO:
      setStato(47);
      bool_motor=false;
      break;
  }    
}
void NFC5_PWM(){                        // 49
  if (FIRST){
    lcd_set();
    lcd.print("DC motor"); arrow_up_func();
    lcd.setCursor(0,1); indicator(); lcd.print("PWM");
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_NO:
      setStato(40);
      break;
    case KY_UP:
      setStato(47);
      break;
    case KY_OK:
      setStato(50);
      break;
  }   
}
void S_NFC5_PWM(){                      // 50
  if (FIRST){
    lcd_set();
    lcd.print("PWM: "); if (bool_PWM==true){ lcd.print("ON"); } else lcd.print("OFF");
    lcd.setCursor(0,1); lcd.print("Set:   ON   OFF"); 
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_OK:
      setStato(49);
      bool_PWM=true;
      break;
    case KY_NO:
      setStato(49);
      bool_PWM=false;
      break;
  }    
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void shutdown_system(){         //60
  if (FIRST){
    lcd_set();
    lcd.print("ON/OFF components"); arrow_up_func();
    lcd.setCursor(0,1); indicator(); lcd.print("Turn off system");
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_UP:
      setStato(40);
      break;
    case KY_OK:
      setStato(61);
      break;
  }  
}
void confirm_shutdown_system(){         //61
  if (FIRST){
    lcd_set();
    lcd.print("Turn off system?");
    lcd.setCursor(0,1); lcd.print("    YES   NO");
    FIRST = false;
  }
  int key = readKeys();
  switch(key){
    case KY_OK:
      setStato(0);
      break;
    case KY_NO:
      setStato(60);
      break;
  }   
}



  
