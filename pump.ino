/**                       
 * Handle water pumpe.
 */

const byte pumpe = 7;
const byte levelSensor = 8;

/**
 * Setup water pumpe.
 */
void setupPumpe() {
  pinMode(pumpe, OUTPUT);
  digitalWrite(pumpe, 0);

  // Set pull-up for level sensor
  pinMode(levelSensor, INPUT);
  digitalWrite(levelSensor, HIGH);
}

/**
 * Start water pumpe.
 */
void pumpeOn() {
#ifdef DEBUG
  pumpePrint();
#endif
  // Only pump if water level is high.
  digitalWrite(pumpe, !pumpeLevel());
}

/**
 * Stop water pumpe.
 */
void pumpeOff() {
  digitalWrite(pumpe, 0);
}

/**
 * Water level switch.
 */
boolean pumpeLevel() {
 return digitalRead(levelSensor);
}

#ifdef DEBUG
/**
 * Used to print debug water level.
 */
void pumpePrint() {
  Serial.print("Level low: ");
  Serial.println(!pumpeLevel());
}
#endif

