
#include "DHT.h"

#define DHTPIN 11
#define DHTTYPE11 DHT11

DHT dht(DHTPIN, DHTTYPE11);

void setup() 
{
  dht.begin();
  Serial.begin(230400);
}

void loop() 
{
  
}

void READ_DHT()
{
  int humidity = dht.readHumidity();
  int temperature = dht.readTemperature();
  if(isnan(humidity) || isnan(temperature))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" *C ");
  Serial.println();
}
