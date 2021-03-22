#define DATA_PIN 11 // originale: 4
#define LATCH_PIN 12 // originale: 3
#define CLOCK_PIN 13 // originale: 2

void setup(){
  pinMode(DATA_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
}

void loop(){
  animation1(70);
  animation2(70);
}

void writeRegister(byte value){
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, value);
  digitalWrite(LATCH_PIN, HIGH);
}

void animation1(unsigned int animationDelay){
  for(int i = 0; i < 8; i++){
    writeRegister(0x1 << i);
    delay(animationDelay);
  }
  for(int i = 0; i < 8; i++){
    writeRegister(0x80 >> i);
    delay(animationDelay);
  }
}

void animation2(unsigned int animationDelay){
  byte value = 0x1;
  for(int i = 0; i < 8; i++){
    writeRegister(value);
    value = (value << 1) + 1;
    delay(animationDelay);
  }
  for(int i = 0; i < 8; i++){
    writeRegister(value);
    value = value >> 1;
    delay(animationDelay);
  }
}
