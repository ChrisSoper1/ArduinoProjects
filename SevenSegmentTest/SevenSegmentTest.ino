//const byte NUM_0 = B11111100;
//byte a = B10011001;
byte NUM_0 = B11000000;
byte NUM_1 = B11111001;
byte NUM_2 = B10100100;
byte NUM_3 = B10110000;
byte NUM_4 = B10011001;
byte NUM_5 = B10010010;
byte NUM_6 = B10000010;
byte NUM_7 = B11111000;
byte NUM_8 = B10000000;
byte NUM_9 = B10011000;

byte DIGITS[] = { B11000000, B11111001, B10100100, B10110000, B10011001,
          B10010010, B10000010, B11111000, B10000000, B10011000 };


//byte DIGIT[] = {11111100, 01100000, 11011010, 11110010, 01100110, 10110110, 10111110, 11100000, 11111110, 11100110];

const int IN    = 11;
const int CLK   = 12;
const int LATCH =  8;


void setup() {
  pinMode(IN,OUTPUT);
  pinMode(CLK,OUTPUT);
  pinMode(LATCH,OUTPUT);

}

void loop() {
  digitalWrite (LATCH, LOW);
  shiftOut (IN, CLK, MSBFIRST, NUM_0);
  digitalWrite (LATCH,HIGH);
  delay (500);
  digitalWrite (LATCH, LOW);
  shiftOut (IN, CLK, MSBFIRST, (NUM_1));
  digitalWrite (LATCH,HIGH);
  delay (500);

  digitalWrite (LATCH, LOW);
  shiftOut (IN, CLK, MSBFIRST, (NUM_2));
    digitalWrite (LATCH,HIGH);
  delay (500);

  digitalWrite (LATCH, LOW);
  shiftOut (IN, CLK, MSBFIRST, (NUM_3));
    digitalWrite (LATCH,HIGH);
  delay (500);

  digitalWrite (LATCH, LOW);
  shiftOut (IN, CLK, MSBFIRST, (NUM_4));
    digitalWrite (LATCH,HIGH);
  delay (500);

  digitalWrite (LATCH, LOW);
  shiftOut (IN, CLK, MSBFIRST, (NUM_5));
    digitalWrite (LATCH,HIGH);
  delay (500);

  digitalWrite (LATCH, LOW);
  shiftOut (IN, CLK, MSBFIRST, (NUM_6));
    digitalWrite (LATCH,HIGH);
  delay (500);

  digitalWrite (LATCH, LOW);
  shiftOut (IN, CLK, MSBFIRST, (NUM_7));
    digitalWrite (LATCH,HIGH);
  delay (500);

  digitalWrite (LATCH, LOW);
  shiftOut (IN, CLK, MSBFIRST, (NUM_8));
    digitalWrite (LATCH,HIGH);
  delay (500);

  digitalWrite (LATCH, LOW);
  shiftOut (IN, CLK, MSBFIRST, (NUM_9));
  digitalWrite (LATCH,HIGH);
  delay (500);

}
