
#include <Arduino.h>
#include <IRremote.hpp>

#define DISABLE_CODE_FOR_RECEIVER
#define IR_SEND_PIN 3

uint8_t sCommand = 0x00;
uint8_t sRepeats = 0;
char sChar;

void setup() 
{
  Serial.begin(230400);
  IrSender.begin(DISABLE_LED_FEEDBACK);
}

void loop() 
{
  if (Serial.available() > 0) 
  {
    sChar = Serial.read();
    sCommand = (uint8_t)strtol(&sChar, NULL, 16);
    Serial.flush();
    IrSender.sendNEC(0x00, sCommand, 0);
    delay(20);
  }
}
