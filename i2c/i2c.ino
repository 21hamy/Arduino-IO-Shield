#include <Wire.h>
int Sw1, Sw2, Sw3;
int svseg1 = 7;
int svseg2 = 6;
int pos1, pos2;
int a, b;
int c = 0;
int d = 0;

const int Data7seg1 [] = {
  //     0     1     2     3     4     5     6     7     8     9
  0x00, 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F
};
const int Data7seg2 [] = {
  //     0     1     2     3     4     5     6     7     8     9
  0x00, 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F
};

void setup() {
  Wire.begin();
  Serial.begin(9600);

  pinMode(svseg1, OUTPUT);
  pinMode(svseg2, OUTPUT);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);

  pinMode(8, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);

  a = 1;
  b = 1;
  pos1 = Data7seg1[a];
  pos2 = Data7seg2[b];
}

void loop() {
  swplus();
  swdis();
  swreset();
  if ((a >= 1) && (b == 10)) {
    digitalWrite(12, 0);
    digitalWrite(10, 0);
    digitalWrite(11, 0);
    digitalWrite(9, 0);
  }
  else if ((a >= 1) && (b == 9)) {
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, 0);
    digitalWrite(9, 0);
  }
  else if ((a >= 1) && (b == 8)) {
    digitalWrite(12, 0);
    digitalWrite(10, 0);
    digitalWrite(11, HIGH);
    digitalWrite(9, 1);
  }
  else if ((a >= 1) && (b == 7)) {
    digitalWrite(12, 0);
    digitalWrite(10, HIGH);
    digitalWrite(11, 0);
    digitalWrite(9, 1);
  }
  else if ((a >= 1) && (b == 6)) {
    digitalWrite(12, HIGH);
    digitalWrite(10, 0);
    digitalWrite(11, HIGH);
    digitalWrite(9, 0);
  }
  else if ((a >= 1) && (b == 5)) {
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(9, 0);
  }
  else if ((a >= 1) && (b == 4)) {
    digitalWrite(9, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, 0);
  }
  else if ((a >= 1) && (b == 3)) {
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, 0);
  }
  else if ((a >= 1) && (b == 2)) {
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, 0);
  } else {
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
  }

}

void ScanDisplay(void) {
  Wire.beginTransmission(0x38);
  Wire.write(pos1);
  Wire.endTransmission();

  digitalWrite(svseg1, LOW);
  digitalWrite(svseg2, HIGH);
  delay(1);

  Wire.beginTransmission(0x38);
  Wire.write(pos2);
  Wire.endTransmission();

  digitalWrite(svseg1, HIGH);
  digitalWrite(svseg2, LOW);
  delay(1);
}
