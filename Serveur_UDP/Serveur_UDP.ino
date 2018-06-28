#include <ESP8266WiFi.h>
#include <WiFiUdp.h>


unsigned int UDPPort = 2390;      // local port to listen on
char packetBuffer[255]; //buffer to hold incoming packet
char  ReplyBuffer[] = "acknowledged";       // a string to send back

WiFiUDP Udp;
                    
const IPAddress local(11, 11, 11, 11);
const IPAddress dns(11, 11, 11, 11);
const IPAddress netmask(255, 255, 255, 0);


void setup() 
{
    Serial.begin(115200);
    WiFi.mode(WIFI_AP); 
    WiFi.softAPConfig(local, dns, netmask);
    WiFi.softAP("Horse");
    WiFi.begin();
    Udp.begin(UDPPort);
    Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.softAPIP().toString().c_str(), UDPPort);
}

void loop() {
  
   int packetSize = Udp.parsePacket();
   
  if (packetSize)
  {
    // receive incoming UDP packets
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(packetBuffer, 255);
    
    if (len > 0)
    {
      packetBuffer[len] = 0;
    }
    
    Serial.printf("UDP packet contents: %s\n", packetBuffer);

    // send back a reply, to the IP address and port we got the packet from
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(ReplyBuffer);
    Udp.endPacket();
    
  }

}
