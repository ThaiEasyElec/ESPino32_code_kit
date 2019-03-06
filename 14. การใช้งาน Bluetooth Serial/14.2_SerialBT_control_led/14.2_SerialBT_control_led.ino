#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;
void setup() 
{
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}
void loop() 
{
  if (SerialBT.available()) {
    char c = SerialBT.read();
    if (c == '0') {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LED OFF");
      SerialBT.println("LED OFF");
    }
    else if (c == '1') {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("LED ON");
      SerialBT.println("LED ON");
    }
  }
}