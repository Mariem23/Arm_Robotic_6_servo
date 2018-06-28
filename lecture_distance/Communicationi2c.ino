#include "Wire.h"
#include "SRF02.h"

SRF02 sensor(0x70, SRF02_CENTIMETERS);

unsigned long nextPrint = 0;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
}

void loop()
{
  SRF02::update();
  if (millis() > nextPrint)
  {
  Serial.println(sensor.read());
    nextPrint = millis () + 1000;
  }
}
