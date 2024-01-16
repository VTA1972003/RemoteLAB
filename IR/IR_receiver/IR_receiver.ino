
#include <Arduino.h>
#include <IRremote.hpp>

#define DECODE_NEC
#define IR_RECEIVE_PIN 25

void setup() 
{
  Serial.begin(230400);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() 
{
  if (IrReceiver.decode()) 
  {
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) 
    {
      IrReceiver.printIRResultRawFormatted(&Serial, true);
    }
    IrReceiver.resume();
    Serial.println(IrReceiver.decodedIRData.command);
  }
}
