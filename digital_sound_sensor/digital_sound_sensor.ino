int soundDetectedPin = 10;
int soundDetectedVal = HIGH;
boolean bAlarm = false;
unsigned long lastSoundDetectTime;
int soundAlarmTime = 500;
int ledpin = 7;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(soundDetectedPin, INPUT);
  pinMode(ledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  soundDetectedVal = digitalRead(soundDetectedPin);
  Serial.println(soundDetectedVal);
  if(soundDetectedVal == 0) {
    digitalWrite(ledpin, HIGH);
    lastSoundDetectTime = millis();

    if(!bAlarm) {
      Serial.println("LOUD!");
      bAlarm = true;
    }
  }

//  Serial.println(millis());
//  Serial.println(lastSoundDetectTime);
//  Serial.println(soundAlarmTime);
//  Serial.println(bAlarm);
  
  if ( (millis() - lastSoundDetectTime) > soundAlarmTime && bAlarm) {
    Serial.println("quit");
    digitalWrite(ledpin, LOW);
    bAlarm = false;
  }
}
