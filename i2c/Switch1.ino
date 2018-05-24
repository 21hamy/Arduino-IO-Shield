void swplus () {
  //  ++++++++++++++++++++Switch 1++++++++++++++++++++
  int data = 0;
  Sw1 = digitalRead(8);
  Sw2 = digitalRead(5);
  Sw3 = digitalRead(4);
  if (Sw1 == 0 && Sw2 == 1 && Sw3 == 1) {
    a += 1;
    c++;
    if (a > 10) {
      a = a-10;
      b = b + 1;
      if (b > 10) {
        b = 1;
      }
    }
    pos1 = Data7seg1[a];
    pos2 = Data7seg2[b];
    while (Sw1 == 0 && Sw2 == 1 && Sw3 == 1) {
      Sw1 = digitalRead(8);
      Sw2 = digitalRead(5);
      Sw3 = digitalRead(4);
      ScanDisplay();
    }
    ScanDisplay();
  }
}

