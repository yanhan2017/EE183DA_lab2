#include <Servo.h>
#include <ESP8266WiFi.h>

WiFiServer server(80);

Servo s;
Servo sr;

int ratio = 1.5;
int angle = 0;
int npos = 8; //total number of positions
int period = 250;
int curr_pos;
//unsigned long Timer = mills();

void setup()
{
  WiFi.mode(WIFI_AP); //Our ESP8266-12E is an AccessPoint
  WiFi.softAP("sssss", "12345678"); // Provide the (SSID, password); .
  server.begin();
  s.attach(D3);
  sr.attach(D4);
  curr_pos = 0; //start at before the leftmost position
}

void loop()
{
  WiFiClient client = server.available();
  if (!client) 
  {
   return; 
  }

  String request = client.readStringUntil('r');
  if (request.indexOf("/play1") != -1)
   {
     play(1); 
   }
   else if (request.indexOf("/play2") != -1)
   {
     play(2); 
   }
   else if (request.indexOf("/play3") != -1)
   {
     play(3); 
   }
   else if (request.indexOf("/play4") != -1)
   {
     play(4); 
   }
   else if (request.indexOf("/play5") != -1)
   {
     play(5); 
   }
   else if (request.indexOf("/play6") != -1)
   {
     play(6); 
   }
   else if (request.indexOf("/play7") != -1)
   {
     play(7); 
   }
   else if (request.indexOf("/Twinkle Twinkle Little Star") != -1)
   {
     Twinkle(); 
   }
   else if (request.indexOf("/endsong") != -1)
   {
     endsong(); 
   }

  String s = "HTTP/1.1 200 OK\r\n";
   s += "Content-Type: text/html\r\n\r\n";
   s += "<!DOCTYPE HTML>\r\n<html>\r\n";
   
   s += "<br><input type=\"button\" name=\"b1\" value=\"play1\" onclick=\"location.href='/play1'\">";
   s += "<br><input type=\"button\" name=\"b1\" value=\"play2\" onclick=\"location.href='/play2'\">";
   s += "<br><input type=\"button\" name=\"b1\" value=\"play3\" onclick=\"location.href='/play3'\">";
   s += "<br><input type=\"button\" name=\"b1\" value=\"play4\" onclick=\"location.href='/play4'\">";
   s += "<br><input type=\"button\" name=\"b1\" value=\"play5\" onclick=\"location.href='/play5'\">";
   s += "<br><input type=\"button\" name=\"b1\" value=\"play6\" onclick=\"location.href='/play6'\">";
   s += "<br><input type=\"button\" name=\"b1\" value=\"play7\" onclick=\"location.href='/play7'\">";
   s += "<br><br><br>";
   s += "<br><input type=\"button\" name=\"b1\" value=\"Twinkle Twinkle Little Star\" onclick=\"location.href='/Twinkle'\">";
   s += "<br><input type=\"button\" name=\"b1\" value=\"endsong\" onclick=\"location.href='/endsong'\">";
   s += "</html>\n";
   //Serve the HTML document to the browser.
   client.flush(); //clear previous info in the stream
   client.print(s); // Send the response to the client
   delay(1);
  //doublestroke(1);
  //doublestroke(2);
  /*play(1);
  play(3);
  play(2);
  play(1);
  
  delay(3000);*/
  /*doublestroke(1);
  play(2);
  play(1);
  play(4);
  play(3);
  doublestroke(1);
  play(2);
  play(1);
  play(5);
  play(4);
  doublestroke(1);
  play(8);
  play(6);
  play(4);
  play(3);
  play(2);
  doublestroke(7);
  play(6);
  play(4);
  play(5);
  play(4);
  endsong();*/
  /*sr.write(0);
  delay(500);
  sr.write(90);
  s.write(90);
  delay(200);
  s.write(0);
  delay(200);

  sr.write(180);
  delay(500);
  sr.write(90);
  s.write(90);
  delay(200);
  s.write(0);
  delay(200);*/
}

