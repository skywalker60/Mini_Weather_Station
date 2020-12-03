#include <DHT.h>
#include <DHT_U.h>
#include "DHT.h"

#define DHTPIN 4     // Digital pin connected to the DHT sensor

#include <Adafruit_Sensor.h>

#define DHTTYPE DHT11   // DHT 11

#include <WiFi.h>

const char ssid[] = "siddhu";
const char password[] = "siddhu123";
WiFiClient client;

#include <ThingSpeak.h>

const long CHANNEL = 1245631;
const char *WRITE_API = "A79D4PRMN39SSYW5";
DHT dht(DHTPIN, DHTTYPE);

#include <Wire.h>
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;

float p = 0.0;
float a = 0.0;
float sp = 0.0;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("Send Sensor's Data to ThingSpeak Using ESP32");
  Serial.println();

  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop()
{
  Serial.println(F("DHT11 test!"));
if (!bmp.begin()) {
  Serial.println("Could not find a valid BMP085/BMP180 sensor, check wiring!");
  while (1) {}
  }

  
  // Connect or reconnect to WiFi
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, password);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
    dht.begin();
  }
  delay(2000);

//   Reading temperature or humidity takes about 250 milliseconds!
 
  float h = dht.readHumidity();
//   Read temperature as Celsius (the default)
float t = dht.readTemperature();
   p=bmp.readPressure(); 
   sp=bmp.readSealevelPressure();
   a = bmp.readAltitude();


    ThingSpeak.setField(1, t);
    ThingSpeak.setField(2, h);
    ThingSpeak.setField(3, p);
  ThingSpeak.setField(4, a);
  ThingSpeak.setField(5, sp);
     Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print("Pressure = ");
  Serial.print(p);
  Serial.println(" Pa");
    
   //Calculate altitude assuming 'standard' barometric
   //pressure of 1013.25 millibar = 101325 Pascal
  Serial.print("Altitude = ");
  Serial.print(bmp.readAltitude());
  Serial.println(" meters");

  Serial.print("Pressure at sealevel (calculated) = ");
  Serial.print(sp);
  Serial.println(" Pa");

    // Write to the ThingSpeak channel
    int x = ThingSpeak.writeFields(CHANNEL, WRITE_API);
    if (x == 200) {
      Serial.println("Channel update successful.");
    }
    else {
      Serial.println(" uploading");
    }

   
  }
