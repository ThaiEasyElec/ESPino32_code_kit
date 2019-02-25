const int pirPin = 4;
void setup()
{
  Serial.begin(115200);
  pinMode(pirPin, INPUT);
}
void loop()
{
  int pirState = digitalRead(pirPin);
  Serial.println(pirState);
  delay(10);
}

