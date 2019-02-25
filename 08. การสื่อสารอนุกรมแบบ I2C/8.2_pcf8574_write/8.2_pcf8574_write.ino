#include <Wire.h>
#define PCF8574_I2C_ADDRESS 0x20
void setup()
{
  Wire.begin();
}
void gpio_out(byte data)
{
  Wire.beginTransmission(PCF8574_I2C_ADDRESS);
  Wire.write(data);
  Wire.endTransmission();
}
void loop()
{
  gpio_out(B00001111);
  delay(1000);
  gpio_out(B11110000);
  delay(1000);
}

