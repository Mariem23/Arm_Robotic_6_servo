////lecture de distance// 
//
//
//void lecture_SRF02() {
//    byte t0, t1=0;
//    int16 val=0;
//
//    ecr_i2c(SRF02,0x00,0x51); // Commande
//    delay_ms(80);
//    t1=lec_i2c(SRF02,0x02,0);
//    t0=lec_i2c(SRF02,0x03,0);
//    val=t0+(t1*256);
//    printf(lcd_putc,"\fCapt. Distance \n");
//    printf(lcd_putc,"Dist:%ld Cm      ",val);
//    putc(entete);putc(adr_srf02);putc(typ_srf02);putc(t0);putc(t1);
//}
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

