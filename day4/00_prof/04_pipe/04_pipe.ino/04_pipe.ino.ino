char receive;
char send;

void setup()
{
  Serial.begin(19200);
  Serial1.begin(19200);
  Serial.println("Echo Program Start...\n");
}

void loop()
{
  if(Serial1.available()>0)
  {
    receive = Serial1.read();
    Serial.write(receive);
  }
}
