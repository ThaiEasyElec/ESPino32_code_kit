void taskOne(void * parameter)
{
  Serial.println("TaskOne run on core " + String(xPortGetCoreID()));
  vTaskDelete(NULL);
}
void taskTwo(void * parameter)
{
  Serial.println("TaskTwo run on core " + String(xPortGetCoreID()));
  vTaskDelete(NULL);
}
void setup()
{
  Serial.begin(115200);
  xTaskCreate(taskOne, "taskOne", 1024, NULL, 1, NULL);
  delay(10);
  xTaskCreate(taskTwo, "taskTwo", 1024, NULL, 1, NULL);
  delay(10);
  Serial.println("Setup Function run on core " + String(xPortGetCoreID()));
}
void loop()
{
}
