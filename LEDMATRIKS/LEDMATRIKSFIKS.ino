// Include the required Arduino libraries:
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW
#define MAX_DEVICES 1
#define CS_PIN 3

MD_Parola myDisplay = MD_Parola (HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  myDisplay.begin();
  //set the intensity(brightness) of the display (0-15)
  myDisplay.setIntensity (0);
  //clear the display
  myDisplay.displayClear ();
}

void loop(){
   myDisplay.setTextAlignment (PA_CENTER);
   myDisplay.print("A");
   delay(200);
}