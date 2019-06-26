#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.softAP("sneakernet","00000000");

  server.on("/", HTTP_POST, []() {
    Serial.println(server.arg(0));
    server.send(200, "text/plain", "BUCK YOUR CHUMBUS");
  });
  server.begin();
}

void loop() {
  server.handleClient();
}
