#include <DHT.h>

#define SOIL_MOISTURE_PIN A0     // Analog pin for soil moisture sensor
#define RELAY_PIN 8              // Digital pin for relay control (solenoid valve)
#define DHT_PIN 2                // Digital pin for DHT11 sensor
#define DHT_TYPE DHT11           // DHT11 sensor type

DHT dht(DHT_PIN, DHT_TYPE);

const int SOIL_MOISTURE_THRESHOLD = 30;  // Soil moisture threshold for activating solenoid valve

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);

  dht.begin();
}

void loop() {
  int soilMoistureRaw = analogRead(SOIL_MOISTURE_PIN);
  int soilMoisturePercentage = map(soilMoistureRaw, 0, 1023, 0, 100);

  float airHumidity = dht.readHumidity();
  float airTemperature = dht.readTemperature();

  Serial.print("Soil Moisture: ");
  Serial.print(soilMoisturePercentage);
  Serial.println("%");
  Serial.print("Air Humidity: ");
  Serial.print(airHumidity);
  Serial.print("%, Air Temperature: ");
  Serial.print(airTemperature);
  Serial.println("°C");

  // Send data to ESP8266 over Serial
  Serial.print("SM=");
  Serial.print(soilMoisturePercentage);
  Serial.print("%&AH=");
  Serial.print(airHumidity);
  Serial.print("%&AT=");
  Serial.println(airTemperature);

  // Control the solenoid valve based on soil moisture threshold
  if (soilMoisturePercentage < SOIL_MOISTURE_THRESHOLD) {
    digitalWrite(RELAY_PIN, HIGH);  // Activate the solenoid valve
    Serial.println("Solenoid Valve Activated");
  } else {
    digitalWrite(RELAY_PIN, LOW);   // Deactivate the solenoid valve
    Serial.println("Solenoid Valve Deactivated");
  }

  delay(15000);  // Adjust the delay based on your requirements
}
