void swreset () {
  //  ++++++++++++++++++++Switch 3++++++++++++++++++++
  Sw1 = digitalRead(8);
  Sw2 = digitalRead(5);
  Sw3 = digitalRead(4);
  if (Sw1 == 1 && Sw2 == 1 && Sw3 == 0) {
    a = 1;
    b = 1;
    c = 0;
    d = 0;
    pos1 = Data7seg1[a];
    pos2 = Data7seg2[b];
    while (Sw1 == 1 && Sw2 == 1 && Sw3 == 0) {
      Sw1 = digitalRead(8);
      Sw2 = digitalRead(5);
      Sw3 = digitalRead(4);
      ScanDisplay();
    }
  }
  ScanDisplay();
}

