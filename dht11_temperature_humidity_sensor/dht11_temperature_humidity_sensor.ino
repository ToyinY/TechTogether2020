#include <DHT.h>
#define dht_apin A2
#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
DHT dht(dht_apin, DHT11);

void setup()

{
dht.begin();
Serial.begin(9600);
delay(3000);
}

void loop()

{
float temp, hum;
temp=dht.readTemperature();
hum=dht.readHumidity();

Serial.print("Temp : ");
Serial.println(temp);
Serial.print("Humi : ");
Serial.println(hum);
}
