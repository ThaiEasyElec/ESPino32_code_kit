const int freq = 5000;
const byte ledChannel = 0;
const byte resolution = 8;
const byte ledPin = 4;
void setup() 
{
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(ledPin, ledChannel);
}
void loop() 
{
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle += 63) {
    ledcWrite(ledChannel, dutyCycle);
    delay(1000);
  }
}
