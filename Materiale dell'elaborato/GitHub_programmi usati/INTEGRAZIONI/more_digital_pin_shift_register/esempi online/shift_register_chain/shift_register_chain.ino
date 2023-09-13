#define DATA_PIN 11
#define LATCH_PIN 12
#define CLOCK_PIN 13

void setup(){
  pinMode(DATA_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
}

void loop(){
  animation1(50);
  animation2(50);
}

void writeRegister(unsigned int value){
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, value >> 8);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, value);
  digitalWrite(LATCH_PIN, HIGH);
}

void animation1(unsigned int animationDelay){
  for(int i = 0; i < 16; i++){
    writeRegister(0x1 << i);
    delay(animationDelay);
  }
  for(int i = 0; i < 16; i++){
    writeRegister(0x8000 >> i);
    delay(animationDelay);
  }
}

void animation2(unsigned int animationDelay){
  unsigned int value = 0x1;
  for(int i = 0; i < 16; i++){
    writeRegister(value);
    value = (value << 1) + 1;
    delay(animationDelay);
  }
  for(int i = 0; i < 16; i++){
    writeRegister(value);
    value = value >> 1;
    delay(animationDelay);
  }
}
