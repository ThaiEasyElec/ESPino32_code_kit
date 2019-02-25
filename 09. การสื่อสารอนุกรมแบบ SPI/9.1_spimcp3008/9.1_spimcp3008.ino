#include <SPI.h>
int result;
void setup()
{
  Serial.begin(115200);
  SPI.begin();
  SPI.beginTransaction (SPISettings (1000000, MSBFIRST, SPI_MODE0));
  pinMode(SS, OUTPUT);
}
void loop()
{
  digitalWrite(SS, LOW);
  SPI.transfer (0x01);
  result = SPI.transfer (0x80);
  result = (result & 0x03) << 8;
  result |= SPI.transfer (0);
  Serial.println(result * 5.0 / 1023.0, DEC);
  digitalWrite(SS, HIGH);
  delay(10);
}
