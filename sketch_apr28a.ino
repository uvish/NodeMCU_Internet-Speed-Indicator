#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>

#ifndef STASSID
#define STASSID "UVish"
#define STAPSK  "uvish460"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;



void setup() {
  pinMode(D0,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
 Serial.begin(115200);
Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  digitalWrite(D0,LOW);
  digitalWrite(LED_BUILTIN, HIGH);
  bool ret = Ping.ping("www.google.com",1);
 //int avg_time_ms = Ping.averageTime();
  
    digitalWrite(D0, HIGH);
      digitalWrite(LED_BUILTIN, LOW);
       delay(Ping.averageTime()*10);
 Serial.println(Ping.averageTime());
  
  

  
     
}
