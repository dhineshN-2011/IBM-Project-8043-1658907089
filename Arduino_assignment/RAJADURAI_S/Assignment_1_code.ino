#define temp A1
#define pir 5
#define buzzer 9
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
  Serial.println("movement unidentified");
  Serial.println("Temperature: ");
  Serial.println(t);
  if (motion == 1)
  {
    Serial.println("Movement identified!!!");
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    delay(10);
  }
  else if(t > 60)
  {
    Serial.println(" WARNING: High Temperature!!!!");
    for(int i=0;i<4;i++)
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
