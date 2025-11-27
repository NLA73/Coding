#include <SoftwareSerial.h>
#include <AFMotor.h>

char val;
AF_DCMotor motor3(3, MOTOR12_64KHZ); //Jadikan motor kiri, 642hHZ
AF_DCMotor motor4(4, MOTOR12_64KHZ);
const int kec = 100;
const int MAIN_LOOP_DELAY = 0;
void handleSerialInput(char data) {
  switch (data) {
    case 'f':
    case 'F':
      Serial.print("Perintah = ");
      Serial.println("Maju");
       motor3.setSpeed(kec);
       motor3.run(FORWARD);
       motor4.setSpeed(kec);
       motor4.run(FORWARD);
      break;
    case 'b':
    case 'B':
      Serial.print("Perintah = ");
      Serial.println("Mundur");
       motor3.setSpeed(kec);
       motor3.run(BACKWARD);
       motor4.setSpeed(kec);
       motor4.run(BACKWARD);
      break;
    case 'l':
    case 'L':
      Serial.print("Perintah = ");
      Serial.println("Kiri");
       motor3.setSpeed(kec);
       motor3.run(FORWARD);
       motor4.setSpeed(kec);
       motor4.run(BACKWARD);
      break;
    case 'r':
    case 'R':
      Serial.print("Perintah = ");
      Serial.println("Kanan");
       motor3.setSpeed(kec);
       motor3.run(BACKWARD);
       motor4.setSpeed(kec);
       motor4.run(FORWARD);
      break;
    case '0':
      Serial.print("Perintah = ");
      Serial.println("Berhenti");
       motor3.setSpeed(kec);
       motor3.run(RELEASE);
       motor4.setSpeed(kec);
       motor4.run(RELEASE);
      break;
    default:
      break;
  }
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char data = Serial.read();
    Serial.println(data);
    handleSerialInput(data);
  }

}