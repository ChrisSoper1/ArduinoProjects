#include <IRLib.h>
// Create a reciever object listening on pin 11
int RECV_PIN = 11;

IRsend Sender;
char operation;
// Presets
unsigned long vol_down=0xE0E0D02F;
unsigned long vol_up=0xE0E0E01F;
unsigned long power=0xE0E040BF;
int codeBits=32;

// Data storage
IRTYPES codeType=NEC;

// Non-Raw Data storage
unsigned long codeValue;  // non-raw data 
// int codeBits;         //length of codeValue
void setup() {
  pinMode(13,OUTPUT); // Onboard LED
  Serial.begin(9600);
  Serial.println(F("Send '`' for power, '1' for vol_down and '2' for vol_up"));
}

void sendCode(unsigned long action) {
  Sender.send(codeType, action, codeBits);
  Serial.print(F("SENT: 0x"));
  Serial.println(action,HEX);
}

void loop() {
  while (Serial.available() == 0) {  }
    operation = Serial.read();
    digitalWrite(13,HIGH);
    if (operation == '1') {
      sendCode(vol_down);
    } else if (operation == '2') {
      sendCode(vol_up);
    } else if (operation == '`') {
      sendCode(power);
    }
    digitalWrite(13,LOW);
}
