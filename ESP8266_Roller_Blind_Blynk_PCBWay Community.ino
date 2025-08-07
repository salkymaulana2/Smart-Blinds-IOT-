/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID "TMPLtgxld6kx"
#define BLYNK_DEVICE_NAME "RollerBlindControl"
#define BLYNK_AUTH_TOKEN "xx6AbhPgxxxxxxxxxxFcxxKgsxx"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Mert";
char pass[] = "xxxxxx";

#define IN1a 15
#define IN2a 13
#define IN3a 12
#define IN4a 14

#define ROLLERTIME 3000

int delayTime = 2;

bool Down_Roller;
bool Up_Roller;

BLYNK_WRITE(V0){
  Down_Roller = param.asInt();
}
BLYNK_WRITE(V1){
  Up_Roller = param.asInt();
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(IN1a, OUTPUT);
  pinMode(IN2a, OUTPUT);
  pinMode(IN3a, OUTPUT);
  pinMode(IN4a, OUTPUT);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();

  if(Down_Roller){
    for (int steps = 0; steps < ROLLERTIME; steps++) {
      Serial.println("DOWN ROLLER BLIND");
      backwardMotor();
    }
  }
  if(Up_Roller){
    for (int steps = 0; steps < ROLLERTIME; steps++) {
      Serial.println("UP ROLLER BLIND");
      forwardMotor();
    }
  }
}

void forwardMotor(void) {
  digitalWrite(IN4a, HIGH);
  digitalWrite(IN3a, LOW);
  digitalWrite(IN2a, LOW);
  digitalWrite(IN1a, LOW);
  delay(delayTime);
  digitalWrite(IN4a, LOW);
  digitalWrite(IN3a, HIGH);
  digitalWrite(IN2a, LOW);
  digitalWrite(IN1a, LOW);
  delay(delayTime);
  digitalWrite(IN4a, LOW);
  digitalWrite(IN3a, LOW);
  digitalWrite(IN2a, HIGH);
  digitalWrite(IN1a, LOW);
  delay(delayTime);
  digitalWrite(IN4a, LOW);
  digitalWrite(IN3a, LOW);
  digitalWrite(IN2a, LOW);
  digitalWrite(IN1a, HIGH);
  delay(delayTime);
}

void backwardMotor(void) {
  digitalWrite(IN4a, LOW);
  digitalWrite(IN3a, LOW);
  digitalWrite(IN2a, LOW);
  digitalWrite(IN1a, HIGH);
  delay(delayTime);
  digitalWrite(IN4a, LOW);
  digitalWrite(IN3a, LOW);
  digitalWrite(IN2a, HIGH);
  digitalWrite(IN1a, LOW);
  delay(delayTime);
  digitalWrite(IN4a, LOW);
  digitalWrite(IN3a, HIGH);
  digitalWrite(IN2a, LOW);
  digitalWrite(IN1a, LOW);
  delay(delayTime);
  digitalWrite(IN4a, HIGH);
  digitalWrite(IN3a, LOW);
  digitalWrite(IN2a, LOW);
  digitalWrite(IN1a, LOW);
  delay(delayTime);
}
