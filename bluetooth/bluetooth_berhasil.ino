//UNTUK BLUETOOTH
int i = 0;
int a = 0;
int b = 0;

//UNTUK LED MATRIX
// Include the required Arduino libraries:
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW
#define MAX_DEVICES 1
#define CS_PIN 3
MD_Parola myDisplay = MD_Parola (HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
Serial.begin(9600);

//UNTUK LED MATRIX
  myDisplay.begin();
  delayMicroseconds(100);
  Serial.begin(9600);
  //set the intensity(brightness) of the display (0-15)
  myDisplay.setIntensity (0);
  //clear the display
  myDisplay.displayClear ();
  pinMode(7,OUTPUT);
}

void loop() {
  digitalWrite(7,HIGH);
if(Serial.available()>0){
  char data =  Serial.read();
 a = b;
  switch(data){
    case '0':
   myDisplay.setTextAlignment (PA_CENTER);
   myDisplay.print("A");
   delay(200);
     break;

     case '1':
   myDisplay.setTextAlignment (PA_CENTER);
   myDisplay.print("B");
   delay(200);
     break;

     case '2':
   myDisplay.setTextAlignment (PA_CENTER);
   myDisplay.print("C");
   delay(200);
     break;

     default:
     break;

  }
}

}
