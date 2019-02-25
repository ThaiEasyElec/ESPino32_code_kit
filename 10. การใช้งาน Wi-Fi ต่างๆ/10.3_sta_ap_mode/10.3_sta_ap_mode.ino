#include <WiFi.h>
#define SSID_AP_NAME "ESPino32 AP mode"
#define SSID_AP_PASS "password"
#define SSID_NAME "ThaieasyElec"
#define SSID_PASS "password"
void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_AP_STA);
  delay(100);
  WiFi.softAP(SSID_AP_NAME, SSID_AP_PASS);
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(SSID_NAME);
  WiFi.begin(SSID_NAME, SSID_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("STA IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}
void loop()
{
}
