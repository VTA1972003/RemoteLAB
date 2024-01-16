
#define button_real_1 50
#define button_real_2 51
#define button_real_3 52
#define switch_real_1 A14
#define switch_real_2 A15
#define rheostat_real A3

#define button_virtual_1 34
#define button_virtual_2 35
#define button_virtual_3 36
#define switch_virtual_1 38
#define switch_virtual_2 39
#define rheostat_virtual A4

int val_button_real_1;
int val_button_real_2;
int val_button_real_3;
int val_switch_real_1;
int val_switch_real_2;
int val_rheostat_real;

int val_button_virtual_1;
int val_button_virtual_2;
int val_button_virtual_3;
int val_switch_virtual_1;
int val_switch_virtual_2;
int val_rheostat_virtual;

void setup() 
{
  pinMode(button_real_1, INPUT_PULLUP);
  pinMode(button_real_2, INPUT_PULLUP);
  pinMode(button_real_3, INPUT_PULLUP);
  pinMode(switch_real_1, INPUT_PULLUP);
  pinMode(switch_real_2, INPUT_PULLUP);
  pinMode(rheostat_real, INPUT);

  pinMode(button_virtual_1, INPUT);
  pinMode(button_virtual_2, INPUT);
  pinMode(button_virtual_3, INPUT);
  pinMode(switch_virtual_1, INPUT);
  pinMode(switch_virtual_2, INPUT);
  pinMode(rheostat_virtual, INPUT);

  Serial.begin(230400);
}

void loop() 
{
  read_input_data();
  Serial.println();
}

void read_input_data()
{
  val_button_real_1 = digitalRead(button_real_1);
  val_button_real_2 = digitalRead(button_real_1);
  val_button_real_3 = digitalRead(button_real_1);
  val_switch_real_1 = digitalRead(switch_real_1);
  val_switch_real_2 = digitalRead(switch_real_2);
  val_rheostat_real = analogRead(rheostat_real);
  
  val_button_virtual_1 = digitalRead(button_virtual_1);
  val_button_virtual_2 = digitalRead(button_virtual_2);
  val_button_virtual_3 = digitalRead(button_virtual_2);
  val_switch_virtual_1 = digitalRead(switch_virtual_1);
  val_switch_virtual_2 = digitalRead(switch_virtual_2);
  val_rheostat_virtual = analogRead(rheostat_virtual);
}
