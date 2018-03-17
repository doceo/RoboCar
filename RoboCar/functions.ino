
void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PWD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is acive low on the ESP-01)
  } else {
    digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
  }

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("Car", "presente CarOne");
      Serial.println("pubblicata la presenza sul Topic Car");
      // ... and resubscribe
      client.subscribe("direzione");
      Serial.println("sottoscritto il Topic direzione");

      client.subscribe("automobile");
      Serial.println("sottoscritto il Topic automobile");
 
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


//void boot_wait() {
//  pinMode(LED, OUTPUT);
//  for (int n = 0; n < 4*BOOT_DELAY/BLINK_TIME; n++) {
//    digitalWrite(LED, HIGH);
//    delay(BLINK_TIME/4);
//    digitalWrite(LED, LOW);
//    delay(BLINK_TIME/4);
//  }
//}
//
//
//void init_motor() {
//  pinMode(MOT_L_SPD, OUTPUT);
//  pinMode(MOT_R_SPD, OUTPUT);
//  pinMode(MOT_L_P, OUTPUT);
//  pinMode(MOT_L_N, OUTPUT);
//  pinMode(MOT_R_P, OUTPUT);
//  pinMode(MOT_R_N, OUTPUT);
//  
//  digitalWrite(MOT_L_SPD, LOW);
//  digitalWrite(MOT_R_SPD, LOW);
//  digitalWrite(MOT_L_P, LOW);
//  digitalWrite(MOT_L_N, LOW);
//  digitalWrite(MOT_R_P, LOW);
//  digitalWrite(MOT_R_N, LOW);
//}
//
//void drive_motor(unsigned int rho, unsigned int phi, unsigned int distance) {
//  if (rho > 0 && phi <= 180 && distance > MIN_DIST) {
//    digitalWrite(MOT_L_P, HIGH);
//    digitalWrite(MOT_L_N, LOW);
//    digitalWrite(MOT_R_P, HIGH);
//    digitalWrite(MOT_R_N, LOW);
//  }
//  else if (rho > 0 && phi > 180) {
//    digitalWrite(MOT_L_P, LOW);
//    digitalWrite(MOT_L_N, HIGH);
//    digitalWrite(MOT_R_P, LOW);
//    digitalWrite(MOT_R_N, HIGH);
//    phi = 360 - phi;
//  }
//  else {
//    digitalWrite(MOT_L_P, LOW);
//    digitalWrite(MOT_L_N, LOW);
//    digitalWrite(MOT_R_P, LOW);
//    digitalWrite(MOT_R_N, LOW);
//  }
//
//  if (phi <= 90) {
//    analogWrite(MOT_L_SPD, 255);
//    analogWrite(MOT_R_SPD, (255*phi)/(90));
//  }
//  else {
//    analogWrite(MOT_L_SPD, (255*(180 - phi))/(90));
//    analogWrite(MOT_R_SPD, 255);
//  }
//}
//
//unsigned int distance() {
//  pinMode(TRIG, OUTPUT);
//  pinMode(ECHO, INPUT);
//  digitalWrite(TRIG, HIGH);
//  delayMicroseconds(5);
//  digitalWrite(TRIG, LOW);
//  unsigned long tof = pulseIn(ECHO, HIGH);
//  return (tof%65536)/58.3;
//}
//
//
//void terminate() {
//    pinMode(LED, OUTPUT);
//
//  while (true) {
//    digitalWrite(LED, !digitalRead(LED));
//    delay(BLINK_TIME);
//  }
//}

