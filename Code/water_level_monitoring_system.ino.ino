int sensorPin = A0;

int ledHijau = 2;
int ledMerah = 3;
int buzzer = 4;

void setup() {

  pinMode(ledHijau, OUTPUT);
  pinMode(ledMerah, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int waterValue = analogRead(sensorPin);

  Serial.print("Water Level: ");
  Serial.println(waterValue);

  // Air rendah / sensor kering
  if(waterValue < 80) {

    digitalWrite(ledMerah, HIGH);
    digitalWrite(ledHijau, LOW);

    tone(buzzer, 1000);

  }

  // Air normal
  else {

    digitalWrite(ledMerah, LOW);
    digitalWrite(ledHijau, HIGH);

    noTone(buzzer);

  }

  delay(500);
}