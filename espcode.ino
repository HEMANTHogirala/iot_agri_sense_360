#include <SoftwareSerial.h>
#include <ThingSpeak.h>
 #include<ESP8266WiFi.h>
#define esp8266 Serial
WiFiClient client;


const char* ssid = ".";
const char* password = "12345678";
const char* thingspeakAPIKey = "NE9FVTU9W33DEIZP";
const unsigned long channelID = 2339007;  // Replace with your ThingSpeak Channel ID

void setup() {
  Serial.begin(9600);
  esp8266.begin(9600);

  ThingSpeak.begin(client);  // Initialize ThingSpeak library

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
}

void loop() {
  if (esp8266.available() > 0) {
    String data = esp8266.readStringUntil('\n');
    Serial.println("Received from Arduino: " + data);

    // Parse data into separate values
    int soilMoisture;
    float airTemperature, airHumidity;
    sscanf(data.c_str(), "SM=%d%%&AH=%f%%&AT=%f°C", &soilMoisture, &airHumidity, &airTemperature);

    Serial.print("Parsed Values - Soil Moisture: ");
    Serial.print(soilMoisture);
    Serial.print(", Air Humidity: ");
    Serial.print(airHumidity);
    Serial.print(", Air Temperature: ");
    Serial.println(airTemperature);


    // Send data to ThingSpeak
    ThingSpeak.setField(1, soilMoisture);
    ThingSpeak.setField(2, airHumidity);
    ThingSpeak.setField(3, airTemperature);
    ThingSpeak.writeFields(channelID, thingspeakAPIKey);


    Serial.println("ThingSpeak update successful");
  }
}
