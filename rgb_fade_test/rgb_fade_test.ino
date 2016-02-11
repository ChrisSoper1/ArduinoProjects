int RED_PIN   = 9;
int GREEN_PIN = 10;
int BLUE_PIN  = 11;
int red_lvl = 0;
int blu_lvl = 0;
int grn_lvl = 0;
int interval = 10;
int power_switch = 8;

//bool active=false;
String newColor;
//#define COMMON_ANNODE;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(power_switch, INPUT);
}

void loop() {
  for (grn_lvl; grn_lvl < 200; grn_lvl++) {
    setColor(red_lvl, grn_lvl, blu_lvl);
    delay(interval);
  }
  for (red_lvl; red_lvl > 0; red_lvl--) {
    setColor(red_lvl, grn_lvl, blu_lvl);
    delay(interval);
  }
  for (blu_lvl; blu_lvl < 200; blu_lvl++) {
    setColor(red_lvl, grn_lvl, blu_lvl);
    delay(interval);
  }
  for (grn_lvl; grn_lvl > 0; grn_lvl--) {
    setColor(red_lvl, grn_lvl, blu_lvl);
    delay(interval);
  }
  for (red_lvl; red_lvl < 200; red_lvl++) {
    setColor(red_lvl, grn_lvl, blu_lvl);
    delay(interval);
  }
  for (blu_lvl; blu_lvl > 0; blu_lvl--) {
    setColor(red_lvl, grn_lvl, blu_lvl);
    delay(interval);
  }
}

void setColor(int red, int green, int blue) {
#ifdef COMMON_ANODE
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
#endif

  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

