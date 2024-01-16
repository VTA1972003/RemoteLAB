
#include "DFRobot_INA219.h"
#include <Wire.h>

DFRobot_INA219_IIC ina219(&Wire, INA219_I2C_ADDRESS4);

float ina219Reading_mA = 1000;
float extMeterReading_mA = 1000;

float voltage;
float current;
float power;

void setup() 
{
  Serial.begin(230400);
  while(ina219.begin() != true) 
  {
    Serial.println("INA219 begin faild");
    delay(2000);
  }
  ina219.linearCalibrate(ina219Reading_mA, extMeterReading_mA);
  Wire.begin();
  Wire.beginTransmission(0x45);// địa chỉ của cảm biến dòng điện
  Wire.write(8);
  Wire.endTransmission();
}

void loop() 
{
  
}

void read_data_wattmeter()
{
  voltage = ina219.getBusVoltage_V();
  current = ina219.getCurrent_mA();
  power = ina219.getPower_mW();
}
