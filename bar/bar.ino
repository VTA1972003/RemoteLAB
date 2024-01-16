#include <Grove_LED_Bar.h>
Grove_LED_Bar bar(28, 29, 0, LED_BAR_10);
#define button 50
int button1 = 0;

void setup() 
{
  bar.begin();
  pinMode(button, INPUT_PULLUP);
}

void loop() 
{
  /*
  int read_button = digitalRead(button);
  if(read_button == 0)
  {
    button1++;
    delay(250);
  }
  bar.setLevel(button1);
  if(button1 == 10)
  {
    button1 = 0;
  }*/
  singleled();
  level();
  setled();
  randomled();
  reverseled();
  toggle();
  walk();
}
void singleled()
{
  /* bar.setLed(position led, 1=on/0=off) */
  // Turn all LEDs on
  for (int i = 1; i <= 10; i++)
  {
    bar.setLed(i, 1);
    delay(500);
  }
  // Turn all LEDs off
  for (int i = 1; i <= 10; i++)
  {
    bar.setLed(i, 0);
    delay(500);
  }
}

void level()
{
  /* bar.setLevel(min=0/max=10) */
  for (int i = 0; i <=10; i++)
  {
    bar.setLevel(i);
    delay(1000);
  }
}

void setled()
{
  // Turn on LEDs with binary
  // LEDs color     green        yellow  red
  // LEDs position     10 9 8 7 6 5 4 3 2 1
  // Binary          0b 1 1 1 1 1 1 1 1 1 1 = 0x3FF (HEX)
  bar.setBits(0x3ff);
  delay(1000);
  bar.setBits(0x0); // Turn off all LEDs
  delay(1000);
  bar.setBits(0b0000000001); // Turn on LED 1 
  delay(1000);
  bar.setBits(0x155); // Turn on LEDs 1, 3, 5, 7, 9 (0x155 = 0b0101010101)
  delay(1000);
  bar.setBits(0x2AA); // Turn on LEDs 2, 4, 6, 8, 10(0x2AA = 0b1010101010)
  delay(1000);
}

void randomled()
{
  // Display a random value between 0 (all LEDs off) and 1023 (all LEDs on)
  bar.setBits(random(1024));
  delay(50);
}

void reverseled()
{
  bar.setGreenToRed(1); // Swich to green to red
  level();
  bar.setGreenToRed(0); // Switch back to red to green
  level();
}

void toggle()
{
  bar.toggleLed(3); // Turn off LED 3
  delay(1000);
  bar.toggleLed(3); // Turn on LED 3
  delay(1000);
}

void walk()
{
  // 0 = 0x0 = all 10 LEDs turned off
  // 1023 = 0x3FF = all 10 LEDs lit up
  for (int i = 0; i <= 1023; i++)
  {
    bar.setBits(i);
    delay(50);
  }
}
