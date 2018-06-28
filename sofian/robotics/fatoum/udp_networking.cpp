//// 
//// 
//// 
//
//#include "udp_networking.h"
//
//#include <ESP8266WiFi.h>
//#include <WiFiUdp.h>
//
//
//#define AP_NAME "Horse"
//#define PACKET_SIZE 255
//
//#
//
//
//unsigned int UDPPort = 2390;      // local port to listen on
//char packetBuffer[PACKET_SIZE]; //buffer to hold incoming packet
//char  ReplyBuffer[] = "acknowledged";       // a string to send back
//
//WiFiUDP Udp;
//
//const IPAddress local(11, 11, 11, 11);
//const IPAddress dns(11, 11, 11, 11);
//const IPAddress netmask(255, 255, 255, 0);
//
//
//// call this function in the setup in main.ino
//void setup_udp_networking()
//{
////	Serial.begin(115200);
//	WiFi.mode(WIFI_AP);
//	WiFi.softAPConfig(local, dns, netmask);
//	WiFi.softAP();
//	WiFi.begin();
//	Udp.begin(UDPPort);
//	Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.softAPIP().toString().c_str(), UDPPort);
//}
//void recive_from_udp() {
//
//}
//
//void answer_back() {
//	// send back a reply, to the IP address and port we got the packet from
//	Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
//	Udp.write(ReplyBuffer);
//	Udp.endPacket();
//}
//void loop() {
//
//	int packetSize = Udp.parsePacket();
//
//	if (packetSize)
//	{
//		// receive incoming UDP packets
//		Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
//		int len = Udp.read(packetBuffer, PACKET_SIZE);
//
//		if (len > 0)
//		{
//			packetBuffer[len] = 0;
//		}
//
//		Serial.printf("UDP packet contents: %s\n", packetBuffer);
//		answer_back()
//
//	}
//
//}
//
