const byte pin = 25;
void setup()
{
  Serial.begin(115200);
}
void loop()
{
  for (int i = 0; i <= 255; i += 63) {
    dacWrite(pin, i);
    Serial.print(i);
    Serial.print("\t");
    Serial.println(i*3.3/255.0);
    delay(3000);
  }
}
