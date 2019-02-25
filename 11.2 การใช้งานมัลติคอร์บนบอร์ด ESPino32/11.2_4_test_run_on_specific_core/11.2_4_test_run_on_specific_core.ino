const byte taskCore = 1;
void coreTask( void * pvParameters )
{
  Serial.println("Task running on core " + String(xPortGetCoreID()));
  vTaskDelete(NULL);
}
void setup() 
{
  Serial.begin(112500);
  xTaskCreatePinnedToCore(
    coreTask,   /* Function to implement the task */
    "coreTask", /* Name of the task */
    10000,      /* Stack size in words */
    NULL,       /* Task input parameter */
    1,          /* Priority of the task */
    NULL,       /* Task handle. */
    taskCore);  /* Core where the task should run */
}
void loop() 
{
}
