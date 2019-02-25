#include<WiFi.h>
#define SSID_NAME "ESPino32 AP mode"
#define SSID_PASS "password"
IPAddress local_ip = {192, 168, 1, 1};
IPAddress gateway = {192, 168, 1, 1};
IPAddress subnet = {255, 255, 255, 0};
void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  WiFi.softAP(SSID_NAME, SSID_PASS);
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
  delay(60000);
  WiFi.softAPdisconnect();
  Serial.print("SoftAPdisconnect");
}
void loop()
{
}
