
float val = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(A0);
  val = val/100;
  if (val > 3 && val <= 7) {
     Serial.println(val);
      delay(500);
  }
}

