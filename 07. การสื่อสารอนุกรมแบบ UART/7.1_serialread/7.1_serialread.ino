void setup()
{
  Serial.begin(115200);
}
void loop()
{
  if (Serial.available()) {
    char c = Serial.read();
    Serial.print(c);
  }
}
