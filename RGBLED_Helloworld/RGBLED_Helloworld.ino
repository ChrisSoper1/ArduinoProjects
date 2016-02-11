//int RED_PIN   = A3;
//int GREEN_PIN = A4;
//int BLUE_PIN  = A5;
int RED_PIN   = 9;
int GREEN_PIN = 10;
int BLUE_PIN  = 11;
int red_val;
int blu_val;
int grn_val;

void setup() {
  pinMode(RED_PIN,OUTPUT);
  pinMode(GREEN_PIN,OUTPUT);
  pinMode(BLUE_PIN,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    red_val = Serial.parseInt();
    Serial.read(); //read over comma
    
    grn_val = Serial.parseInt();
    Serial.read(); // read over comma
    
    blu_val = Serial.parseInt();
    while (Serial.available() > 0) {
      Serial.read();
    }
    setColor(red_val,grn_val,blu_val);
    Serial.println(red_val);
    Serial.println(grn_val);
    Serial.println(blu_val);
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN,red);
  analogWrite(GREEN_PIN,green);
  analogWrite(BLUE_PIN,blue);
}

