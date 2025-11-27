#include <AFMotor.h>
char val;
AF_DCMotor motor1(2, MOTOR12_64KHZ); //Jadikan motor kanan, 64KHZ
AF_DCMotor motor2(1, MOTOR12_64KHZ); //Jadikan motor kiri, 642hHZ
AF_DCMotor motor4(4, MOTOR12_64KHZ); //Jadikan motor kiri, 642hHZ
AF_DCMotor motor3(3, MOTOR12_64KHZ); //Jadikan motor kiri, 642hHZ

const int pinSensorKiri = A0;
const int pinSensorKanan = A2;
const int pinSensorTengah = A5;

void setup() {
  // put your setup code here, to run once:
 Serial.begin (9600);
      pinMode (pinSensorKiri, INPUT);
        pinMode (pinSensorKanan, INPUT);
          pinMode (pinSensorTengah, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int dataAnalog1 = digitalRead (pinSensorKiri);
int dataAnalog2 = digitalRead (pinSensorKanan);
int dataAnalog3 = digitalRead (pinSensorTengah);
Serial.print ("Sensor1 : ");
  Serial.println (dataAnalog1);
Serial.print ("Sensor2 : ");
  Serial.println (dataAnalog2);
Serial.print ("Sensor3 : ");
  Serial.println (dataAnalog3);

if (dataAnalog1 == 0 && dataAnalog2 == 0) {
  motor1.setSpeed(100);
  motor1.run(BACKWARD); //Motor kanan maju
  motor2.setSpeed(100);
  motor2.run(BACKWARD); //Motor kiri maju
}
else if(dataAnalog1 == 1 && dataAnalog2 == 0) {
  motor1.setSpeed(100);
  motor1.run(BACKWARD); //Motor kanan mundur
  motor2.setSpeed(100);
  motor2.run(FORWARD); //Motor kiri maju
}
else if(dataAnalog1 == 0 && dataAnalog2 == 1){
  motor1.setSpeed(100);
  motor1.run(FORWARD); //Motor kanan maju
  motor2.setSpeed(100);
  motor2.run(BACKWARD); //Motor kiri mundur
}

else if(dataAnalog1 == 1 && dataAnalog2 == 1){
  delay(2000);
  motor1.setSpeed(0);
  motor1.run(RELEASE); //Motor kanan berhenti
  motor2.setSpeed(0);
  motor2.run(RELEASE); //Motor kiri berhenti
}
}