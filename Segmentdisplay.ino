
// Pin 13 has an LED connected on most Arduino boards
int led = 13;
int gnd1 = 7;
int gnd2 = 6;
int segmentA = 0;
int segmentB = 1;
int segmentC = 3;
int segmentD = 10;
int segmentE = 9;
int segmentF = 11;
int segmentG = 8;
int segmentH = 2;

int segment1 = -1;
int segment2 = -1;
boolean dot1  = false;
boolean dot2  = false;
int delayTime = 200;

void setup() {                
  pinMode(led, OUTPUT);     
  pinMode(gnd1, OUTPUT);
  pinMode(gnd2, OUTPUT);
  /*
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(segmentH, OUTPUT);
  */
  digitalWrite(gnd1, HIGH);
  digitalWrite(gnd2, HIGH);
  Serial.begin(9600);
}

void loop() {
   if (Serial.available() > 0) {
     int rd = Serial.read();
     if (rd == '~') {
       if (delayTime > 499) { 
         delayTime = 200;
       } else {
         delayTime = 500;
       }
     } else if (rd == '#') {
       segment1 = -1;
       segment2 = -1;
     } else if (rd == '.') {
       dot1 = !dot1;
     } else if (rd == ':') {
       dot2 = !dot2;
     } else if (segment2 == -1) {
       segment2 = rd;
     } else {
       segment1 = segment2;
       segment2 = rd; 
     }
  }
  show(segment1, segment2, dot1, dot2, delayTime);
}

void show(char letterA, char letterB, boolean pointA, boolean pointB, int time) {
  byte byteA = getByte(letterA, pointA);
  byte byteB = getByte(letterB, pointB);
  showByte(byteA, byteB, time);
}

void showByte(byte letterA, byte letterB, int time) {
  long ctime = millis();
  while (ctime + time > millis()) {
    digitalWrite(gnd1, LOW);
    digitalWrite(gnd2, HIGH);
    showByte(letterA);
    delay(10);
    digitalWrite(gnd1, HIGH);
    digitalWrite(gnd2, LOW);
    showByte(letterB);
    delay(10);
  }
}

void showByte(byte letter) {
  if ((letter & B00000001) == B00000001) { digitalWrite(segmentA, HIGH); } else { digitalWrite(segmentA, LOW); }
  if ((letter & B00000010) == B00000010) { digitalWrite(segmentB, HIGH); } else { digitalWrite(segmentB, LOW); }
  if ((letter & B00000100) == B00000100) { digitalWrite(segmentC, HIGH); } else { digitalWrite(segmentC, LOW); }
  if ((letter & B00001000) == B00001000) { digitalWrite(segmentD, HIGH); } else { digitalWrite(segmentD, LOW); }
  if ((letter & B00010000) == B00010000) { digitalWrite(segmentE, HIGH); } else { digitalWrite(segmentE, LOW); }
  if ((letter & B00100000) == B00100000) { digitalWrite(segmentF, HIGH); } else { digitalWrite(segmentF, LOW); }
  if ((letter & B01000000) == B01000000) { digitalWrite(segmentG, HIGH); } else { digitalWrite(segmentG, LOW); }
  if ((letter & B10000000) == B10000000) { digitalWrite(segmentH, HIGH); } else { digitalWrite(segmentH, LOW); }
}

void off() {
  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);
  digitalWrite(segmentH, LOW);
}

byte getByte(char letter, boolean point) {
  byte seg = B0;
  
  if (letter == '0') { seg = B00111111; }
  if (letter == '1') { seg = B00000110; }
  if (letter == '2') { seg = B01011011; }
  if (letter == '3') { seg = B01001111; }
  if (letter == '4') { seg = B01100110; }
  if (letter == '5') { seg = B01101101; }
  if (letter == '6') { seg = B01111101; }
  if (letter == '7') { seg = B00000111; }
  if (letter == '8') { seg = B01111111; }
  if (letter == '9') { seg = B01101111; }
  
  if (letter == 'A') { seg = B01110111; }
  if (letter == 'a') { seg = B01110111; }
  if (letter == 'B') { seg = B01111111; }
  if (letter == 'b') { seg = B01111100; }
  if (letter == 'C') { seg = B00111001; }
  if (letter == 'c') { seg = B01011000; }
  if (letter == 'D') { seg = B00111111; }
  if (letter == 'd') { seg = B01011110; }
  if (letter == 'E') { seg = B01111001; }
  if (letter == 'e') { seg = B01111001; }
  if (letter == 'F') { seg = B01110001; }
  if (letter == 'f') { seg = B01110001; }
  if (letter == 'G') { seg = B01111101; }
  if (letter == 'g') { seg = B01101111; }
  if (letter == 'H') { seg = B01110110; }
  if (letter == 'h') { seg = B01110100; }
  if (letter == 'I') { seg = B00000110; }
  if (letter == 'i') { seg = B00000100; }
  if (letter == 'J') { seg = B00001111; }
  if (letter == 'j') { seg = B00001111; }
  if (letter == 'K') { seg = B01111000; }
  if (letter == 'k') { seg = B01111000; }
  if (letter == 'L') { seg = B00111000; }
  if (letter == 'l') { seg = B00111000; }
  if (letter == 'M') { seg = B00110111; }
  if (letter == 'm') { seg = B00110111; }
  if (letter == 'N') { seg = B01010100; }
  if (letter == 'n') { seg = B01010100; }
  if (letter == 'O') { seg = B00111111; }
  if (letter == 'o') { seg = B01011100; }
  if (letter == 'P') { seg = B01110011; }
  if (letter == 'p') { seg = B01110011; }
  if (letter == 'Q') { seg = B01100111; }
  if (letter == 'q') { seg = B01100111; }
  if (letter == 'R') { seg = B01010000; }
  if (letter == 'r') { seg = B01010000; }
  if (letter == 'S') { seg = B01101101; }
  if (letter == 's') { seg = B01101101; }
  if (letter == 'T') { seg = B00110001; }
  if (letter == 't') { seg = B01110000; }
  if (letter == 'U') { seg = B00111110; }
  if (letter == 'u') { seg = B00011100; }
  if (letter == 'V') { seg = B00011100; }
  if (letter == 'v') { seg = B00011100; }
  if (letter == 'W') { seg = B00111100; }
  if (letter == 'w') { seg = B00111100; }
  if (letter == 'X') { seg = B01010010; }
  if (letter == 'x') { seg = B01010010; }
  if (letter == 'Y') { seg = B01100110; }
  if (letter == 'y') { seg = B01100110; }
  if (letter == 'Z') { seg = B01011011; }
  if (letter == 'z') { seg = B01011011; }

  if (letter == '('){ seg = B00111001; }    
  if (letter == ')'){ seg = B00001111; }    
  if (letter == '>'){ seg = B01001100; }  
  if (letter == '<'){ seg = B01011000; }  
  if (letter == '\''){ seg = B00100000; }  
  if (letter == '|') { seg = B00110000; }
  if (letter == '-') { seg = B01000000; }
  if (letter == '_') { seg = B00001000; }
  if (letter == '=') { seg = B01001000; }
  
  if (point) { seg = seg | B10000000; }
  
  return seg;
}

