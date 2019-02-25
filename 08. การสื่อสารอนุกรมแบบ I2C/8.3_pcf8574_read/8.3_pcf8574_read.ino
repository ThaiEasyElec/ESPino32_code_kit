#include <Wire.h>
#define PCF8574_I2C_ADDRESS 0x20
void setup()
{
  Wire.begin();
  Serial.begin(115200);
}
void loop()
{
  Wire.requestFrom(PCF8574_I2C_ADDRESS, 1);
  while (Wire.available())
  {
    Serial.println(Wire.read(), BIN);
  }
  delay(1000);
}

