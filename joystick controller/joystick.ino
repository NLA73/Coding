#include <AFMotor.h>
char val;
AF_DCMotor motor4(4, MOTOR12_64KHZ); //Jadikan motor kiri, 642hHZ
AF_DCMotor motor3(3, MOTOR12_64KHZ); //Jadikan motor kiri, 642hHZ
#define x A0
#define y A5
void setup() {
Serial.begin(9600);
}

void loop() {
  // Baca nilai dari joystick
  int xAxis = analogRead(x);
  Serial.print("X = ");
    Serial.println (xAxis);
  int yAxis = analogRead(y);
  Serial.print("Y =");
    Serial.println (yAxis);
delay(100);
if (yAxis <= 450) {
 motor4.setSpeed(255);
  motor4.run(BACKWARD); //Motor kanan maju
  // Tambahkan delay untuk menghindari pengiriman data terlalu cepat
}
else if (yAxis >= 550) {
 motor4.setSpeed(255);
  motor4.run(FORWARD); //Motor kanan maju
}
else{
 motor4.setSpeed(255);
  motor4.run(RELEASE); //Motor kanan maju
}
}