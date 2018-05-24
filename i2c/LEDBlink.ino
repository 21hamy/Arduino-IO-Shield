void ledblink (int i) {
  digitalWrite(9, i);
  digitalWrite(10, i);
  digitalWrite(11, i);
  digitalWrite(12, i);
  ScanDisplay();
}

