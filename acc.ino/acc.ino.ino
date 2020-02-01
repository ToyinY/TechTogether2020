const int sensorPin = 5;

// We'll also set up some global variables for the light level a calibration value and
//and a raw light value
int lightCal;
int lightVal;


void setup()
{
  Serial.begin(9600); 
  // We'll set up the LED pin to be an output.
  lightCal = analogRead(sensorPin);
  //we will take a single reading from the light sensor and store it in the lightCal
  //variable. This will give us a prelinary value to compare against in the loop
}


void loop()
{
  //Take a reading using analogRead() on sensor pin and store it in lightVal
  lightVal = analogRead(sensorPin);
  Serial.print("Light: "); 
  Serial.println(lightVal);
  delay(1000);//take a reading every second

}
