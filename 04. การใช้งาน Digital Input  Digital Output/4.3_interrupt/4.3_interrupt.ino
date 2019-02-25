const byte ledPin = 2;
const byte interruptPin = 15;
volatile byte state = LOW;
void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT);
  Serial.begin(115200);
  attachInterrupt(interruptPin, blink, RISING);
}
void loop()
{
  for (int i = 0; i < 100; i++)
  {
    Serial.println(i);
    delay(1000);
  }
}
void blink() 
{
  state = !state;
  digitalWrite(ledPin, state);
  Serial.println("put switch");
}
