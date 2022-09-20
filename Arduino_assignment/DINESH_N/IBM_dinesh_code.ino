#define temp A0
#define pir 3
#define buzzer 8
int motion =0;
double t;

void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(temp, INPUT);
  pinMode(pir, INPUT);
  Serial.begin(9600);
}

void loop()
{
  motion = digitalRead(pir);
  int reading = analogRead(temp);
  t = (double)reading / 1024;
t = t * 5;
t = t-0.5;
t = t * 100;
  Serial.println("motion not detected");
  Serial.println("Temperature: ");
  Serial.println(t);
  if (motion == 1)
  {
    Serial.println("Motion Detected!!!");
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    delay(10);
  }
  else if(t > 60)
  {
    Serial.println("High Temperature Detected!!!");
    for(int i=0;i<3;i++)
    {
    digitalWrite(buzzer,HIGH);
    delay(1500);
    digitalWrite(buzzer,LOW);
    delay(500);
      i++;
    }
  }
  delay(1000);
}
