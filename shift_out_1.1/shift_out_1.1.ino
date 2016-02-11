const int IN = 11; // Data In (
const int CLK =12; // Clock
const int LATCH= 8; // Enable output latch pin
bool direct = true;
void setup() {
  pinMode(IN,OUTPUT);
  pinMode(CLK,OUTPUT);
  pinMode(LATCH,OUTPUT);
  
}

void loop() 
{
  for (int numberToDisplay=1; numberToDisplay <= 8; numberToDisplay ++) 
  {
    digitalWrite (LATCH, LOW);
    if (direct == true) {
      shiftOut (IN, CLK, MSBFIRST, pow(2,numberToDisplay)-1);
    } else {
      shiftOut (IN, CLK, LSBFIRST, pow(2,numberToDisplay)-1);
    }
    digitalWrite (LATCH,HIGH);
    delay (50);
  }
  direct = !direct;
}

/*
  for (int numberToDisplay=1; numberToDisplay <= 8; numberToDisplay ++) 
  {
    digitalWrite (LATCH, LOW);
    shiftOut (IN, CLK, LSBFIRST, pow(2,numberToDisplay)-1);
    digitalWrite (LATCH,HIGH);
    delay (50);  
  }
}
*/
/*
  for (int numberToDisplay=8; numberToDisplay >= 1; numberToDisplay --) 
{
  digitalWrite (LATCH, LOW);
  shiftOut (IN, CLK, LSBFIRST, pow(2,numberToDisplay)-1);
  digitalWrite (LATCH,HIGH);
  delay (50);
}
*/
/*
digitalWrite (LATCH,LOW);
shiftOut (IN, CLK, MSBFIRST, B10101010);
digitalWrite (LATCH,HIGH);
delay (100);

digitalWrite (LATCH,LOW);
shiftOut (IN, CLK, MSBFIRST, B01010101);
digitalWrite (LATCH,HIGH);
delay (100);
}*/

