String text;
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}
void loop()
{
  if (Serial.available()) {
    text = Serial.readStringUntil('\n');
    if (text == "LEDON") {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("LED ON");
    } else {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LED OFF");
    }
  }
}
