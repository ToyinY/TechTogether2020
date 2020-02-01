#define BLYNK_PRINT Serial
#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

char auth[] = "bXgQY2uWMfu0NBdNHyqIMXcUWhjHF428";

BlynkTimer timer;

// Sensor pins
int moisturePin = A0;
int lightPin = A1;
int tempHumPin = A2;
int xAccPin = A3;
int yAccPin = A4;
int zAccPin = A5;
int speakerPin = 8;

void myTimerEvent()
{
  Blynk.virtualWrite(lightPin, millis() / 1000);
}

void setup() {
  Serial.begin(9600);
  pinMode(lightPin, OUTPUT);
  Blynk.begin(auth);
  timer.setInterval(1000L, myTimerEvent);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();

  int lightVal = analogRead(lightPin);
  Serial.print("Light: "); 
  Serial.println(lightVal);
  delay(1000);//take a reading every second
}
