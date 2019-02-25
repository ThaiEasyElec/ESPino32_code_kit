#include "WiFi.h"
#define pushButton 25
#define LED 26
void taskOne_SW(void * parameter)
{
  for (;;)
  {
    pinMode(pushButton, INPUT);
    if (digitalRead(pushButton) == HIGH)
    {
      Serial.println("Push Button");
      delay(500);
    }
  }
  vTaskDelete(NULL);
}
void taskTwo_LED(void * parameter)
{
  for (;;)
  {
    pinMode(LED, OUTPUT);
    digitalWrite(LED, !digitalRead(LED));
    delay(1000);
  }
  vTaskDelete(NULL);
}
void setup()
{
  Serial.begin(115200);
  xTaskCreate(taskOne_SW, "taskOne_SW", 1024, NULL, 1, NULL);
  xTaskCreate(taskTwo_LED, "taskTwo_LED", 1024, NULL, 1, NULL);
}
void loop()
{
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  Serial.println("scan start");
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0) {
    Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
      delay(10);
    }
  }
  Serial.println("");
  delay(1000);
}
