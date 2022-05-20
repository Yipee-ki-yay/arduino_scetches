int currentValue;
int maxValue;
int minValue;
unsigned long timer;
int sampleSpan = 200;
int volume;
int ledpin = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  resetValues();
}

void loop() {
  // put your main code here, to run repeatedly:
  currentValue = analogRead(A1);
//  Serial.println(currentValue);

  float voltage = currentValue * (5.0 / 1023.0);
  Serial.println(voltage);

  if(currentValue < minValue) {
    minValue = currentValue;  
  }
  if(currentValue > maxValue) {
    maxValue = currentValue;  
  }

  if(millis() - timer >= sampleSpan) {
    volume = maxValue - minValue;
//    Serial.println(volume);
    resetValues();
  }

  if(volume > 100) {
//    Serial.println("LOUD");
    digitalWrite(ledpin, HIGH);
  } else {
//    Serial.println("Quiet");
    digitalWrite(ledpin, LOW);
  }
}

void resetValues() {
  maxValue = 0;  
  minValue = 1024;
  timer = millis();
}
