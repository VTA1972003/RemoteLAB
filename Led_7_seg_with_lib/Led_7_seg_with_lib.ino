#include "TM1637.h"
#define CLK1 30 // Pin CLK for display 1
#define DIO1 31 // Pin DIO for display 1
#define CLK2 32 // Pin CLK for display 2
#define DIO2 33 // Pin DIO for display 2
TM1637 tm1637_1(CLK1, DIO1); // Declare object TM1637 for display 1
TM1637 tm1637_2(CLK2, DIO2); // Declare object TM1637 for display 2
float number = -1234.5;
int reverse_value = 1;
void setup() {
  // put your setup code here, to run once:
  tm1637_1.init(); // initialization display 1
  tm1637_1.set(BRIGHT_TYPICAL); // set brightness display 1
  tm1637_2.init(); // initialization display 2
  tm1637_2.set(BRIGHT_TYPICAL); // set brightness display 2
  tm1637_1.clearDisplay();
  tm1637_2.clearDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  display_string();
  delay(2000);
  display_lock();
  delay(2000);
  display_number();
}

void display_number()
{
  /*
  The function prints a number value on a 4 digit display
  */
  tm1637_1.displayNum(number);
  number += 17.42 * reverse_value;
  if (abs(number) > 1500)
  {
    reverse_value *= -1;
  }
  delay(50);
}

void display_string()
{
  /*
  The function prints a number value on a 4 digit display
  */
  tm1637_2.clearDisplay();
  // ON
  tm1637_2.displayStr("ON");
  delay(2000);
  // loop
  tm1637_2.displayStr("REMOTELAB", 1000);
  delay(2000);
  // OFF
  tm1637_2.displayStr("0FF");
  delay(2000);
}

void display_lock()
{
  /*
  The function prints the value on each LED of the 4-digit display.
  tm1637.display(position, value);
  */
  tm1637_2.display(0,1);  // LED position 1 show number 1 on display
  tm1637_2.display(1,2);  // LED position 2 show number 2 on display
  tm1637_2.display(2,3);  // LED position 3 show number 3 on display
  tm1637_2.display(3,4);  // LED position 4 show number 4 on display
  tm1637_1.display(0,5);  // LED position 1 show number 5 on display
  tm1637_1.display(1,6);  // LED position 2 show number 6 on display
  tm1637_1.display(2,7);  // LED position 3 show number 7 on display
  tm1637_1.display(3,8);  // LED position 4 show number 8 on display
}
