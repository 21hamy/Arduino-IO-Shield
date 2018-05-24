void swdis () {
  //  ++++++++++++++++++++Switch 2++++++++++++++++++++
  if ((a >= 1) && (b >= 1) && (c > 0)) {
    Sw1 = digitalRead(8);
    Sw2 = digitalRead(5);
    Sw3 = digitalRead(4);
    ScanDisplay();
    if (Sw1 == 1 && Sw2 == 0 && Sw3 == 1) {
      ScanDisplay();
      a -= 1;
      if ((a < 1) && (b > 1)) {
        a = 10+a;
        b--;
      }
      if ((a < 1) && (b == 1)) {
        a = 1;
        b = 1;
        c = 0;
      }
      pos1 = Data7seg1[a];
      pos2 = Data7seg2[b];
      while (Sw1 == 1 && Sw2 == 0 && Sw3 == 1) {
        Sw1 = digitalRead(8);
        Sw2 = digitalRead(5);
        Sw3 = digitalRead(4);
        ScanDisplay();
      }
    }
  }
  ScanDisplay();
}

