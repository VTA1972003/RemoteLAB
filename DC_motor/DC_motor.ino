
#define l2985v 42
#define l298ena 8
#define l298in1 44
#define l298in2 45

long pulse = 0;
int speed_motor = 255;

void setup() 
{
  pinMode(l2985v, OUTPUT);
  pinMode(l298ena, OUTPUT);
  pinMode(l298in1, OUTPUT);
  pinMode(l298in2, OUTPUT);

  Serial.begin(230400);
}

void loop() 
{
  
}

void forward()
{
  digitalWrite(l298in1, HIGH);
  digitalWrite(l298in2, LOW);
  analogWrite(l298ena, speed_motor);
  digitalWrite(l2985v, HIGH);
}
void reverse()
{
  digitalWrite(l298in1, LOW);
  digitalWrite(l298in2, HIGH);
  analogWrite(l298ena, speed_motor);
  digitalWrite(l2985v, HIGH);
}
void stop_motor()
{
  digitalWrite(l298in1, LOW);
  digitalWrite(l298in2, LOW);
  analogWrite(l298ena, 0);
  digitalWrite(l2985v, LOW);
}
