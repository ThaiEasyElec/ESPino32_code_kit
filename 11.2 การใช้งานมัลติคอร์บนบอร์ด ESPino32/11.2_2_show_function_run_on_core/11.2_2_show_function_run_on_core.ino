void functionX()
{
  Serial.println("FunctionX run on core " + String(xPortGetCoreID()));
}
void functionY()
{
  Serial.println("FunctionY run on core " + String(xPortGetCoreID()));
}
void functionZ()
{
  Serial.println("FunctionZ run on core " + String(xPortGetCoreID()));
}
void setup()
{
  Serial.begin(115200);
  functionX();
  functionY();
  functionZ();
}
void loop()
{
}
