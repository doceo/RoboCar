 // il progetto RoboWiFi è stato pensato e realizzato a scopo didattico dal 
// prof. Fabrizio Tamigi. 
// Le successive modifiche, sempre a scopo didattico, dal prof Diomede Mazzone

#include "ESP8266.h"
#include "Webpage.h"
//#include "WIFI_conf"

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
#define WLAN_PWD "robowifi"
#define WLAN_SSID "RoboWiFi"
#define IP_ADDRESS "192.168.1.10"
#define SERVER_PORT 80



ESP8266 ap;
unsigned int rho = 0,
             phi = 0;

void setup() {

    init_motor();

  pinMode(ESP_EN, OUTPUT);
  digitalWrite(ESP_EN, LOW);

  boot_wait();
  digitalWrite(ESP_EN, HIGH);

	if (!ap.baud() || !ap.reset() || \
		!ap.init(F(HOST), F(WLAN_SSID), F(WLAN_PWD)) || !ap.baud(BAUD_RATE))
		terminate();
}

void loop() {
	int link;
	String http_req = ap.receive(link);
	if (link != -1) {
		if (http_req.indexOf(F("GET / ")) != -1) {
			ap.send_P(link, webpage);
		}
		else {
      if (unsigned int pos = http_req.indexOf(F("POLAR /")) != -1) {
        rho = http_req.substring(pos + 7).toInt();
        phi = http_req.substring(pos + ((String)rho).length() + 8).toInt();
        ap.send(link, "OK");
      }
		}
    ap.stop(link);
	}
  drive_motor(rho, phi, distance());

}


