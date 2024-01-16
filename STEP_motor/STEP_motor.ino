
#define step_motor_in_1 46
#define step_motor_in_2 47
#define step_motor_in_3 48
#define step_motor_in_4 49

int step_number = 0;

void setup() 
{
  pinMode(step_motor_in_1, OUTPUT);
  pinMode(step_motor_in_2, OUTPUT);
  pinMode(step_motor_in_3, OUTPUT);
  pinMode(step_motor_in_4, OUTPUT);
}

void loop() 
{
  
}

void stepmotor(bool dir)
{
  if(dir)
  {
    switch(step_number)
    {
      case 0:
        digitalWrite(step_motor_in_1, HIGH);
        digitalWrite(step_motor_in_2, LOW);
        digitalWrite(step_motor_in_3, LOW);
        digitalWrite(step_motor_in_4, LOW);
        break;
      case 1:
        digitalWrite(step_motor_in_1, LOW);
        digitalWrite(step_motor_in_2, HIGH);
        digitalWrite(step_motor_in_3, LOW);
        digitalWrite(step_motor_in_4, LOW);
        break;
      case 2:
        digitalWrite(step_motor_in_1, LOW);
        digitalWrite(step_motor_in_2, LOW);
        digitalWrite(step_motor_in_3, HIGH);
        digitalWrite(step_motor_in_4, LOW);
        break;
      case 3:
        digitalWrite(step_motor_in_1, LOW);
        digitalWrite(step_motor_in_2, LOW);
        digitalWrite(step_motor_in_3, LOW);
        digitalWrite(step_motor_in_4, HIGH);
        break;
    } 
  }
  else
  {
    switch(step_number)
    {
      case 0:
        digitalWrite(step_motor_in_1, LOW);
        digitalWrite(step_motor_in_2, LOW);
        digitalWrite(step_motor_in_3, LOW);
        digitalWrite(step_motor_in_4, HIGH);
        break;
      case 1:
        digitalWrite(step_motor_in_1, LOW);
        digitalWrite(step_motor_in_2, LOW);
        digitalWrite(step_motor_in_3, HIGH);
        digitalWrite(step_motor_in_4, LOW);
        break;
      case 2:
        digitalWrite(step_motor_in_1, LOW);
        digitalWrite(step_motor_in_2, HIGH);
        digitalWrite(step_motor_in_3, LOW);
        digitalWrite(step_motor_in_4, LOW);
        break;
      case 3:
        digitalWrite(step_motor_in_1, HIGH);
        digitalWrite(step_motor_in_2, LOW);
        digitalWrite(step_motor_in_3, LOW);
        digitalWrite(step_motor_in_4, LOW);
        break;
    } 
  }
  step_number++;
  if(step_number > 3)
  {
    step_number = 0;
  }
}
