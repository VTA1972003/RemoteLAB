
#include "Adafruit_NeoPixel.h"

#define led_stick_pin_1 5
#define led_stick_pin_2 6

#define num_pixels 10

Adafruit_NeoPixel led_stick_1 = Adafruit_NeoPixel(num_pixels, led_stick_pin_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_stick_2 = Adafruit_NeoPixel(num_pixels, led_stick_pin_2, NEO_GRB + NEO_KHZ800);

int brightness = 10;
int led_stick_num;
int num_led_of_led_stkick;
int red_led;
int green_led;
int blue_led;

void setup() 
{
  #if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) 
  {
    clock_prescale_set(clock_div_1);
  }
  #endif
  led_stick_1.setBrightness(brightness);
  led_stick_1.begin();
  led_stick_2.setBrightness(brightness);
  led_stick_2.begin();
}

void loop() 
{
  for (int i = 0; i < 10; i++)
  {
    control_single_led( 1, i, 255, 0, 0);
    delay(100);
  }
  for (int i = 0; i < 10; i++)
  {
    control_single_led( 1, 9 - i, 0, 0, 0);
    delay(100);
  }
  for (int i = 0; i < 10; i++)
  {
    control_single_led( 1, i, 0, 255, 0);
    delay(100);
  }
  for (int i = 0; i < 10; i++)
  {
    control_single_led( 1, 9 - i, 0, 0, 0);
    delay(100);
  }
  for (int i = 0; i < 10; i++)
  {
    control_single_led( 1, i, 0, 0, 255);
    delay(100);
  }
  for (int i = 0; i < 10; i++)
  {
    control_single_led( 1, 9 - i, 0, 0, 0);
    delay(100);
  }
  for (int i = 0; i < 10; i++)
  {
    control_single_led( 1, i, 255, 255, 255);
    delay(100);
  }
  for (int i = 0; i < 10; i++)
  {
    control_single_led( 1, 9 - i, 0, 0, 0);
    delay(100);
  }
}

void control_single_led(int led_stick_num, int num_led_of_led_stkick, int red, int green, int blue)
{
  if (led_stick_num == 1)
  {
    led_stick_1.setPixelColor(num_led_of_led_stkick, led_stick_1.Color(red, green, blue));
    led_stick_1.show();
  }
  else if (led_stick_num == 2)
  {
    led_stick_2.setPixelColor(num_led_of_led_stkick, led_stick_2.Color(red, green, blue));
    led_stick_2.show();
  }
}

void led_stick_all_on()
{
  for (int i = num_pixels; i >= 0; i--)
  {
    led_stick_1.setPixelColor(i, led_stick_1.Color(255, 255, 255));
    led_stick_2.setPixelColor(i, led_stick_2.Color(255, 255, 255));
  }
  led_stick_1.show();
  led_stick_2.show();
}

void led_stick_all_off()
{
  for (int i = num_pixels; i >= 0; i--)
  {
    led_stick_1.setPixelColor(i, led_stick_1.Color(0, 0, 0));
    led_stick_2.setPixelColor(i, led_stick_2.Color(0, 0, 0));
  }
  led_stick_1.show();
  led_stick_2.show();
}
