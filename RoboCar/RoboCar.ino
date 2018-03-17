 // il progetto RoboWiFi è stato pensato e realizzato a scopo didattico dal 
// prof. Fabrizio Tamigi. 
// Le successive modifiche, sempre a scopo didattico, dal prof Diomede Mazzone

//#include "Webpage.h"
//#include "WIFI_conf"

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

WiFiClient espClient;

#define MOT_L_SPD 3
#define MOT_R_SPD 5
#define MOT_L_P 4
#define MOT_L_N 6
#define MOT_R_P 7
#define MOT_R_N 8
#define ESP_EN 2
#define LED 13
#define TRIG A3
#define ECHO A4

#define BOOT_DELAY 2000

#define BAUD_RATE 115200
#define BLINK_TIME 200
#define MIN_DIST 10

#define HOST "CarOne"
#define WLAN_PWD "robocar0"
#define WLAN_SSID "RoboCar"
//#define IP_ADDRESS "192.168.1.10"
//#define SERVER_PORT 80
#define SERVER_MQTT "192.168.43.179"


long lastMsg = 0;
char msg[50];
int value = 0;

PubSubClient client(espClient);


//ESP8266 ap;
unsigned int rho = 0,
             phi = 0;

void setup() {

//  init_motor();

  pinMode(ESP_EN, OUTPUT);
  digitalWrite(ESP_EN, LOW);

//  boot_wait();
  digitalWrite(ESP_EN, HIGH);

//	if (!ap.baud() || !ap.reset() || \
//		!ap.init(F(HOST), F(WLAN_SSID), F(WLAN_PWD)) || !ap.baud(BAUD_RATE))
//		terminate();

  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  setup_wifi();
  client.setServer(SERVER_MQTT, 1883);
  client.setCallback(callback);


}

void loop() {

    if (!client.connected()) {
    reconnect();
  }
  client.loop();

    long now = millis();
//  if (now - lastMsg > 2000) {
//    lastMsg = now;
//    ++value;
//    snprintf (msg, 75, "hello world #%ld", value);
//    Serial.print("Publish message: ");
//    Serial.println(msg);
// //   client.publish("outTopic", msg);
//  }
//      if (unsigned int pos = http_req.indexOf(F("POLAR /")) != -1) {
//        rho = http_req.substring(pos + 7).toInt();
//        phi = http_req.substring(pos + ((String)rho).length() + 8).toInt();
//        ap.send(link, "OK");
//      }

//  drive_motor(rho, phi, distance());

}


