#define LED1 27
#define LED2 25
#define LED3 26
hw_timer_t * timer = NULL;
hw_timer_t * timer1 = NULL;
void IRAM_ATTR onTimer()
{
  digitalWrite(LED1, !digitalRead(LED1));
}
void IRAM_ATTR onTimer1()
{
  digitalWrite(LED2, !digitalRead(LED2));
}
void setup() 
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 100000, true);
  timerAlarmEnable(timer);
  timer1 = timerBegin(1, 80, true);
  timerAttachInterrupt(timer1, &onTimer1, true);
  timerAlarmWrite(timer1, 500000, true);
  timerAlarmEnable(timer1);
}
void loop()
{
  digitalWrite(LED3, !digitalRead(LED3));
  delay(1000);
}
