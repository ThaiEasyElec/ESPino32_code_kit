const byte sensorPin = A0;
const int threshold = 2000;
int sensorValue = 0;
void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  analogReadResolution(12);
}
void loop()
{
  sensorValue = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  if (sensorValue > threshold) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println(" LED OFF");
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println(" LED ON");
  }
  delay(100);
}
