//const byte NUM_0 = B11111100;
//byte a = B10011001;


byte DIGITS[] = { B11000000, B11111001, B10100100, B10110000, B10011001,
          B10010010, B10000010, B11111000, B10000000, B10011000 };

const int IN    = 11;
const int CLK   = 12;
const int LATCH =  8;
int SWITCH = 7;
int SWITCH2 = 6;
int COUNTER;
void setup() {
  pinMode(IN,OUTPUT);
  pinMode(CLK,OUTPUT);
  pinMode(LATCH,OUTPUT);
  pinMode(SWITCH,INPUT);
  digitalWrite(SWITCH, HIGH);
    pinMode(SWITCH2,INPUT);
  digitalWrite(SWITCH2, HIGH);
  COUNTER = 0;
  digitalWrite (LATCH, LOW);
  shiftOut (IN, CLK, MSBFIRST, DIGITS[COUNTER]);
  digitalWrite (LATCH,HIGH);
}

void loop() {
  /*
  for (int i=0; i < 10 ; i++) {
    digitalWrite (LATCH, LOW);
    shiftOut (IN, CLK, MSBFIRST, DIGITS[i]);
    digitalWrite (LATCH,HIGH);
    delay (500);
  }
  */
  if (digitalRead(SWITCH) == LOW) {
    COUNTER ++;
    delay (500);
  }
  else if (digitalRead(SWITCH2) == LOW) {
    digitalWrite (LATCH, LOW);
    shiftOut (IN, CLK, MSBFIRST, DIGITS[COUNTER]);
    digitalWrite (LATCH,HIGH);
    delay (500);
    COUNTER = 0;
  }
  
}
