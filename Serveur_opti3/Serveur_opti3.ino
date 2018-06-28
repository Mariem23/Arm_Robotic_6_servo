/// test to get connection between C/S, l'ennvoi d'une requête si nécessaire 
// code Alexandre
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

unsigned int UDPPort1 = 2490; 
unsigned int UDPPort2 = 2390;
unsigned int TestPort = 2380; // local port to listen on
char packetBuffer1[255]; //buffer to hold incoming packet
char packetBuffer2[255];
char finalBuffer[255];
char testBuffer[255];
char  ReplyBuffer[] = "acknowledged";
String tempo11;
String tempo22;
String state1;
String state2;
WiFiUDP Udp;
WiFiUDP Udp2;
WiFiUDP Udp1;
const IPAddress local(11, 11, 11, 11);
const IPAddress Client1(11, 11, 11, 112);
const IPAddress Client2(11, 11, 11, 113);
const IPAddress dns(11, 11, 11, 11);
const IPAddress netmask(255, 255, 255, 0);
const IPAddress remote(11,11,11,110);
String FinalBuffer;
String Buffer1;
String Buffer2;
String xxx;
String i;
String j;
String k;
String l;

void setup()
{
    WiFi.softAPdisconnect(true);
    WiFi.disconnect(true);
    Serial.begin(115200);
    WiFi.mode(WIFI_STA); 
    WiFi.softAPConfig(local, dns, netmask);
    WiFi.softAP("Horse");
    WiFi.begin();
    Udp.begin(TestPort);
    Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.softAPIP().toString().c_str(), TestPort);
    while (xxx != "Hello ESP!")
      {
           int packetSize = Udp.parsePacket();
 
           if (packetSize)
            {
              Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());  
              int len = Udp.read(testBuffer, 255);
              if (len > 0)
              {
               testBuffer[len] = 0;
              }
              xxx=String(testBuffer);
                            Serial.printf("UDP packet contents: %s\n", testBuffer);
                            Udp.beginPacket(remote, 12345);
                            Udp.write(ReplyBuffer);
                            Udp.endPacket();
                            Udp.beginPacket(remote, 12345);
                            Udp.write(ReplyBuffer);
                            Udp.endPacket();
            }
      }
      
Serial.printf("its Android !");
    
       Udp1.begin(UDPPort1);
       Udp2.begin(UDPPort2);
       Udp.beginPacket(Client1, 2500);
       Udp.write(ReplyBuffer);
       Udp.endPacket();
       Udp.beginPacket(Client2, 2400);
       Udp.write(ReplyBuffer);
       Udp.endPacket();
delay(1000);
     
}

void loop()
{
 
      
       
  ///////////////////////////////////////////////////partie udp///////////////////////////////////////////////////
    int packetSize1 = Udp1.parsePacket();

 
           if (packetSize1)
            { 
              int len = Udp1.read(packetBuffer1, 255);
              if (len > 0)
              {
               packetBuffer1[len] = 0;
              }
              Buffer1= String(packetBuffer1);
             
                          
            }
            
    int packetSize2 = Udp2.parsePacket();
    
 if (packetSize2)
            { 
              int len = Udp2.read(packetBuffer2, 255);
              if (len > 0)
              {
               packetBuffer2[len] = 0;
              }
              Buffer2= String(packetBuffer2);
             
                          
            }
    
    
 /*if(strlen(packetBuffer1) == 0){Buffer1="no data from client 1"; Serial.println("error client1");}
 else{Buffer1= String(packetBuffer1); }
 
 if(strlen(packetBuffer2) == 0){Buffer2="no data from client 1"; Serial.println("error client2");}
 else{Buffer2= String(packetBuffer1); }*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////partie web/////////////////////////////////////////////////////////    

if ((Buffer1 == tempo11) && (Buffer2 == tempo22)) //On conpare les nouvelles données
    {                                             //avec les précédentes.
Serial.println("same data");                      //Si elle sont identique,juste un println.
    }
else
    {
Udp.beginPacket(remote, 12345);                   //si l'une d'entre elles a changer,
FinalBuffer = (Buffer1 + "x" + Buffer2);          //on envoie le paquet à Android.
FinalBuffer.toCharArray(finalBuffer,255);
Udp.write(finalBuffer);
Udp.endPacket();
Serial.println("send data to Android");
tempo11=Buffer1;                                  //Et on met à jour les variables
tempo22=Buffer2;                                  //Temporaires!
    }
                 
                  
}           

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

