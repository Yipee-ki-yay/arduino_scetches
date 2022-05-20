void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(8, HIGH);
//  delay(500);
//  digitalWrite(8, LOW);
//  delay(500);
  doSignal(3, 500);
  doSignal(3, 2 000);
  doSignal(3, 500);
}

void doSignal(int times, int delayMS) {
  for (int i = 0; i < times; i++) {
    digitalWrite(8, HIGH);
    delay(delayMS);
    digitalWrite(8, LOW);
    delay(delayMS);
  }
}
