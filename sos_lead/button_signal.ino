int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(2);

  if (buttonState == HIGH) {
    Serial.println("HIGH");
  } else {
    Serial.println("LOW");
  }
}
