int LED = 13;
int LDR = 0;
int Poti = 1;
int cnt = 0;
int Flag = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LED, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {

  if (analogRead(LDR) < analogRead(Poti))cnt++;
  if (analogRead(LDR) > analogRead(Poti))cnt = 0;
  Serial.println(analogRead(LDR));

  if (cnt > 300) {

    digitalWrite(LED, HIGH);
    do {
      Serial.println(analogRead(LDR));
      delay(100);
    } while (analogRead(LDR) < analogRead(Poti));
    cnt = 0;
    Serial.println(analogRead(LDR));
    digitalWrite(LED, LOW);
  }

  if (analogRead(LDR) < 300) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
  delay(10);

}
