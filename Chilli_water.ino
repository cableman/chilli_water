// Needs to be included here to make parse by ref work.
#include <MoistureSensor.h>

//#define DEBUG;

const int moistureLow = 600;

void setup() {
  #ifdef DEBUG 
    Serial.begin(9600);
    Serial.print("DEBUG MODE");
  #endif
  
  moistureSetup();
  setupNeoRing();
  setupPumpe();
}

void loop() {
  // put your main code here, to run repeatedly:

  int low = moistureLevelLow(moistureLow);
  if (low) {
    pumpeOn(); 
    delay(3800);
  }
  pumpeOff();

  NoeRingdisplayLevel(getMoistureValue(), moistureLow);
  delay(4000);
  neoRingReset();

  delay(30000);
}
