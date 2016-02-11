#include <IRLib.h>
// Create a reciever object listening on pin 11
int RECV_PIN = 11;
IRrecv Reciever(RECV_PIN);
IRdecode Decoder;
IRdecodeHash Hash_Decoder;
IRsend Sender;

// Data storage
IRTYPES codeType;

// Non-Raw Data storage
unsigned long codeValue;  // non-raw data 
int codeBits;         //length of codeValue

// Raw (unknown type) Data storage
unsigned int rawCodes[RAWBUF];  // raw-durations
int rawCount;     // number of raw-samples

bool GotOne, GotNew;

void setup() {
  GotOne=false; GotNew=false;
  codeType = UNKNOWN;
  codeValue=0;
  pinMode(13,OUTPUT); // Onboard LED
  Serial.begin(9600);
  Serial.println(F("Recording IR Code..."));
  Serial.println(F("Send any not-null input to broadcast recorded code"));
  Reciever.enableIRIn(); // Start the reciever
}

void storeCode(void) {
  GotNew=true;
  codeType=Decoder.decode_type;
  if (codeType == UNKNOWN) {
    Serial.println("Recieved unknown code, storing as raw");

    // First bit is a control char
    rawCount = Decoder.rawlen-1;

    for(int i=1; i <=rawCount; i++) {
      rawCodes[i - 1] = Decoder.rawbuf[i];
    };
    Decoder.DumpResults();
    codeType=UNKNOWN;
  }
  else {
    Serial.print(F("Recieved: "));
    Serial.print(Pnames(codeType));

    if (Decoder.value==REPEAT) {
      //Dont record repeat values
      Serial.println(F("Repeatcode:IGNORING"));
    }
    else {
      codeValue = Decoder.value;
      codeBits = Decoder.bits;
    }
    Serial.print(F(" Value:0x"));
    Serial.println(Decoder.value, HEX);
  }
}

void sendCode(int repeat) {
  if(codeType == UNKNOWN) {
    // Assume 38 Khz
    Sender.IRsendRaw::send(rawCodes,rawCount,38);
    Serial.println(F("SENT RAW"));
    return;    
  }
  if (!GotNew) {
    if (codeType == RC5) {
      codeValue ^= 0x0800;
    } else if (codeType == RC6) {
      codeValue ^= 0x100000;
    }
  }
  GotNew=false;
  Sender.send(codeType, codeValue, codeBits);
  Serial.print(F("SENT "));
  Serial.print(Pnames(codeType));
  Serial.print(F(" Value:0x"));
  Serial.println(codeValue,HEX);
}
void loop() {
  if (Serial.read() != -1) {
    if (GotOne) {
      sendCode(0);
      Reciever.enableIRIn();
    }
  } else if (Reciever.GetResults(&Decoder)) {
    Hash_Decoder.copyBuf(&Decoder);
    digitalWrite(13,HIGH); // Flash onboard LED
    Decoder.decode();
    Hash_Decoder.decode();
    Serial.print(", hash decode: 0x");
    Serial.println(Hash_Decoder.hash, HEX);
    GotOne=true;
    storeCode();
    delay(1000);
    digitalWrite(13,LOW);
    Reciever.resume();
  }
}
