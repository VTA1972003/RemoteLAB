
#include <Servo.h>

#define RCMOTOR 9

Servo myservo;

void setup() 
{
  myservo.attach(RCMOTOR);
}

void loop() 
{
  myservo.write(val);
}
