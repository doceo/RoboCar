
void boot_wait() {
  pinMode(LED, OUTPUT);
  for (int n = 0; n < 4*BOOT_DELAY/BLINK_TIME; n++) {
    digitalWrite(LED, HIGH);
    delay(BLINK_TIME/4);
    digitalWrite(LED, LOW);
    delay(BLINK_TIME/4);
  }
}


void init_motor() {
  pinMode(MOT_L_SPD, OUTPUT);
  pinMode(MOT_R_SPD, OUTPUT);
  pinMode(MOT_L_P, OUTPUT);
  pinMode(MOT_L_N, OUTPUT);
  pinMode(MOT_R_P, OUTPUT);
  pinMode(MOT_R_N, OUTPUT);
  
  digitalWrite(MOT_L_SPD, LOW);
  digitalWrite(MOT_R_SPD, LOW);
  digitalWrite(MOT_L_P, LOW);
  digitalWrite(MOT_L_N, LOW);
  digitalWrite(MOT_R_P, LOW);
  digitalWrite(MOT_R_N, LOW);
}

void drive_motor(unsigned int rho, unsigned int phi, unsigned int distance) {
  if (rho > 0 && phi <= 180 && distance > MIN_DIST) {
    digitalWrite(MOT_L_P, HIGH);
    digitalWrite(MOT_L_N, LOW);
    digitalWrite(MOT_R_P, HIGH);
    digitalWrite(MOT_R_N, LOW);
  }
  else if (rho > 0 && phi > 180) {
    digitalWrite(MOT_L_P, LOW);
    digitalWrite(MOT_L_N, HIGH);
    digitalWrite(MOT_R_P, LOW);
    digitalWrite(MOT_R_N, HIGH);
    phi = 360 - phi;
  }
  else {
    digitalWrite(MOT_L_P, LOW);
    digitalWrite(MOT_L_N, LOW);
    digitalWrite(MOT_R_P, LOW);
    digitalWrite(MOT_R_N, LOW);
  }

  if (phi <= 90) {
    analogWrite(MOT_L_SPD, 255);
    analogWrite(MOT_R_SPD, (255*phi)/(90));
  }
  else {
    analogWrite(MOT_L_SPD, (255*(180 - phi))/(90));
    analogWrite(MOT_R_SPD, 255);
  }
}

unsigned int distance() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIG, LOW);
  unsigned long tof = pulseIn(ECHO, HIGH);
  return (tof%65536)/58.3;
}


void terminate() {
    pinMode(LED, OUTPUT);

  while (true) {
    digitalWrite(LED, !digitalRead(LED));
    delay(BLINK_TIME);
  }
}

