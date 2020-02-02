/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest
  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.
    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app
  Blynk library is licensed under MIT license
  This example code is in public domain.
 *************************************************************
  =>
  =>          USB HOWTO: http://tiny.cc/BlynkUSB
  =>
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT DebugSerial
#define dht_apin A2

// You could use a spare Hardware Serial on boards that have it (like Mega)
#include <SoftwareSerial.h>
#include <DHT.h>


DHT dht(dht_apin, DHT11);

SoftwareSerial DebugSerial(2, 3); // RX, TX

#include <BlynkSimpleStream.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "bXgQY2uWMfu0NBdNHyqIMXcUWhjHF428";
BlynkTimer timer;

// Pins 
const int lightPin = 1;
int lightCal = 0; 
int lightVal = 0; 
int sweat = 0; //value for storing moisture value 
int sweatPin = A0;//Declare a variable for the soil moisture sensor 
int sweatPower = 7;//Variable for Soil moisture Power
int piezoPin = 8; 
const int z_pin = 3; 
const int y_pin = 4; 
const int x_pin = 5; 

const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin =  13;
int buttonState = 0; 

void timerEvent()
{
   // Light Sensor 
  lightVal = analogRead(lightPin);
  Blynk.virtualWrite(4,lightVal); 


  //Temp/Humiditity Sensor 
  float temp, hum; 
  dht.read(dht_apin);
  temp=dht.readTemperature();
  temp = temp * (9/5) + 32; 
  //Serial.println(temp);
  hum=dht.readHumidity();
  ///Serial.println(hum);
  Blynk.virtualWrite(3, temp); 
  Blynk.virtualWrite(1, hum); 

  //Moisture
  float moisture; 
  moisture = readSoil(); 

  //Accelerometer 
  float x,y,z; 
  x = analogRead(x_pin); 
  y = analogRead(y_pin); 
  z = analogRead(z_pin); 

  float sleep_quality = moisture + abs(x) + abs(y) + abs(z); 
  float inv_sleep = (1/sleep_quality) * 1000000; 
  //Serial.println(sleep_quality); 
  Blynk.virtualWrite(0, inv_sleep); 
  Blynk.virtualWrite(2, LOW); 

  const int nightmare_threshold = 2000; 
  const int dead_threshold = 1500; 
  if (sleep_quality > nightmare_threshold) {
   int notes[] = {1136, 1014};
   //Serial.println("Breathing Exercise"); 
   for(int aa = 0; aa < 3; aa++)  {
      tone(piezoPin,notes[0],2000);
      delay(4000);
    
      tone(piezoPin,notes[1],4000);
      delay(6000);
      Blynk.virtualWrite(2, HIGH); 
  
  }
   }

   if (sleep_quality < dead_threshold) {

      int notes[] = {1136, 1136, 1275, 1519};
      //Serial.println("Trigger Wakeup"); 
      for(int aa = 0; aa < 4; aa ++)  {
         tone(piezoPin,notes[aa],1000);
         delay(1300);
      
  }

   }

     // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // Show the state of pushbutton on serial monitor
  // check if the pushbutton is pressed.
  if (buttonState == HIGH) {         // check if the input is HIGH (button released)
    digitalWrite(ledPin, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin, HIGH);  // turn LED ON
  }
  // Added the delay so that we can see the output of button
  delay(100);
}
void setup()
{
  // Debug console
  DebugSerial.begin(9600); 

  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(9600);
  Blynk.begin(Serial, auth);

  lightCal = analogRead(lightPin);
  
  pinMode(sweatPower, OUTPUT);//Set D7 as an OUTPUT
  digitalWrite(sweatPower, LOW);//Set to LOW so no power is flowing through the sensor

  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
  dht.begin();
  timer.setInterval(1000L, timerEvent);
   
}

void loop()
{
    Blynk.run();
    timer.run(); 
 
}

int readSoil()
{
    int val = 0; 
    digitalWrite(sweatPower, HIGH);//turn D7 "On"
    delay(10);//wait 10 milliseconds 
    val = analogRead(sweatPin);//Read the SIG value form sensor 
    digitalWrite(sweatPower, LOW);//turn D7 "Off"
    return val;//send current moisture value
}
