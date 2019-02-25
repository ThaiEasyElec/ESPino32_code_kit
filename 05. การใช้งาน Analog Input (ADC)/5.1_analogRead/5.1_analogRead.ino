const byte sensorPin = A0;
int sensorValue = 0;
float voltageValue = 0;
void setup()
{
  Serial.begin(115200);
  analogReadResolution(12);
}
void loop()
{
  sensorValue = analogRead(sensorPin);
  voltageValue = sensorValue * (3.3 / 4095.00);
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print("\t");
  Serial.print("Voltage Value: ");
  Serial.println(voltageValue);
  delay(100);
}
