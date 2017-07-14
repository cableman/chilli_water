#include <MoistureSensor.h>

const int MoisturePowerPin = 12;
const int MoistureSensor1 = A0;

const int numReadings = 50;

MoistureSensor ms1 = MoistureSensor(MoistureSensor1, numReadings);

int ms1Value = 0;
int lowValue = false;

/**
 * Setup up power.
 */
void moistureSetup() {
  pinMode(MoisturePowerPin, OUTPUT);
}

/**
 * Is moisture level low.
 */
int moistureLevelLow(int moistureLow) {
  lowValue = false;
  
  // Power on.
  digitalWrite(MoisturePowerPin, HIGH);

  // let the sensor warm up, the initial readings are not
  // very accurate
  delay(500);

  // Read sensor value.
  ms1Value = moistureReadSensor(ms1);
  if (ms1Value > moistureLow) {
    lowValue = true;
  }

  // Power off.
  digitalWrite(MoisturePowerPin, LOW);

#ifdef DEBUG
    moisturePrint();
#endif

  return lowValue;
}

/**
 * Read sensor value.
 */
 int moistureReadSensor(MoistureSensor ms) {
  for (int i = 0; i < numReadings; i++) {
    ms.reset();
    ms.read();
    delay(1);
  }

  return ms.getSmoothedReading();
}

/**
 * Get the last read value.
 */
int getMoistureValue() {
  return ms1Value;
}

#ifdef DEBUG
/**
 * Print moisture debug levels.
 */
void moisturePrint() {
  Serial.print("Moisture 1: ");
  Serial.println(ms1Value);
  Serial.print("Moisture low: ");
  Serial.println(lowValue);
}
#endif
