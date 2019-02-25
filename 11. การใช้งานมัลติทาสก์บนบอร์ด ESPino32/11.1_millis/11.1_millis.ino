#define LED1 27
#define LED2 25
#define LED3 26
unsigned long previousMillis1,previousMillis2,previousMillis3;
void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}
void loop()
{
  if (millis() - previousMillis1 >= 100) 
  {
    previousMillis1 = millis();
    digitalWrite(LED1, !digitalRead(LED1));
  }
  if (millis() - previousMillis2 >= 500) 
  {
    previousMillis2 = millis();
    digitalWrite(LED2, !digitalRead(LED2));
  }
  if (millis() - previousMillis3 >= 1000) 
  {
    previousMillis3 = millis();
    digitalWrite(LED3, !digitalRead(LED3));
  }
}
