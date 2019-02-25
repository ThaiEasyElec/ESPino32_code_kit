void setup()
{
  sigmaDeltaSetup(0, 312500);
  sigmaDeltaAttachPin(4, 0);
}
void loop()
{
  for (int i = 0; i <= 255; i += 63) {
    sigmaDeltaWrite(0, i);
    delay(1000);
  }
}
