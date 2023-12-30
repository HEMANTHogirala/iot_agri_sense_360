#include "HX711.h"

#define PH_DOUT 4
#define PH_SCK  3

HX711 phSensor;

void setup() {
  Serial.begin(9600);
  phSensor.begin(PH_DOUT, PH_SCK);
}

void loop() {
  // Read raw pH value
  long rawPH = phSensor.read();

  // Convert raw pH value to actual pH value using calibration factor
  float calibratedPH = map(rawPH, 0, 1023, 0, 14); // Map the raw value to the pH range

  // Print absolute values of raw and calibrated pH
  Serial.print(" Raw pH: ");
  Serial.print(abs(rawPH));

  Serial.print(" |  Calibrated pH: ");

  // Use fabs() for absolute value of floating-point numbers
  float absCalibratedPH = fabs(calibratedPH);
  
 
  
  Serial.println(abs(calibratedPH));

  delay(1000); // Adjust delay as needed
}
 
