//library
#include <NewPing.h>
#include <AFMotor.h>

//sensor ultra
int trig = 13; 
int echo = 11;
int trigg = 10;
int echoo = 12;
long durasiA, jarakA;  
long durasiB, jarakB;

//sensor warna
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut1 8
int redFrequency1 = 0;
int greenFrequency1 = 0;
int blueFrequency1 = 0;
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

//line tracker
char val;
AF_DCMotor motor1(2, MOTOR12_64KHZ); //Jadikan motor kanan, 64KHZ
AF_DCMotor motor2(3, MOTOR12_64KHZ); //Jadikan motor kiri, 64KHZ
AF_DCMotor motor3(1, MOTOR12_64KHZ); //Jadikan motor kiri, 64KHZ
AF_DCMotor motor4(4, MOTOR12_64KHZ); //Jadikan motor kiri, 64KHZ

const int pinSensorKiri = A0;
const int pinSensorKanan = A1;
const int pinSensorTengah = A5;


void setup() {
  //ultrasonic
pinMode(trig, OUTPUT);    // set pin trig menjadi OUTPUT
pinMode(echo, INPUT);     // set pin echo menjadi INPUT
pinMode(trigg, OUTPUT);    // set pin trigg menjadi OUTPUT
pinMode(echoo, INPUT);     // set pin echoo menjadi INPUT

//warna
pinMode(S0, OUTPUT);
pinMode(S1, OUTPUT);
pinMode(S2, OUTPUT);
pinMode(S3, OUTPUT);
pinMode(sensorOut1,INPUT);
digitalWrite(S0,HIGH);
digitalWrite(S1,LOW);

//line tracker
pinMode (pinSensorKiri, INPUT);
pinMode (pinSensorKanan, INPUT);
pinMode (pinSensorTengah, INPUT);
AF_DCMotor motor1(1, MOTOR12_64KHZ); //Jadikan motor kanan, 64KHZ
AF_DCMotor motor2(2, MOTOR12_64KHZ); //Jadikan motor kiri, 64KHZ
AF_DCMotor motor3(3, MOTOR12_64KHZ); //Jadikan motor baling-baling, 64KHZ
AF_DCMotor motor4(4, MOTOR12_64KHZ); //Jadikan motor belakang, 64KHZ

//serial
Serial.begin(9600);
}

void loop() {
function2();
function1();
function3();
function4();
}

void function1(void){
int dataAnalog1 = digitalRead (pinSensorKiri);
  int dataAnalog2 = digitalRead (pinSensorKanan);
    int dataAnalog3 = digitalRead (pinSensorTengah);
Serial.print ("Sensor1 : ");
Serial.println (dataAnalog1);
Serial.print ("Sensor2 : ");
Serial.println (dataAnalog2);
Serial.print ("Sensor3 : ");
Serial.println (dataAnalog3);

if (dataAnalog1 == 1 && dataAnalog2 == 0 && dataAnalog3 == 0 ) {
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(BACKWARD); //Motor kanan mundur
  motor2.run(FORWARD); //Motor kiri maju
}
else if (dataAnalog1 == 0 && dataAnalog2 == 0 && dataAnalog3 == 1 ) {
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(FORWARD); //Motor kanan maju
  motor2.run(FORWARD); //Motor kiri mundur
}
else if (dataAnalog1 == 0 && dataAnalog2 == 1 && dataAnalog3 == 0 ) {
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(FORWARD); //Motor kanan maju
  motor2.run(BACKWARD); //Motor kiri mundur
}

else if (dataAnalog1 == 1 && dataAnalog2 == 1 && dataAnalog3 == 1 ) {
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(FORWARD); //Motor kanan maju
  motor2.run(BACKWARD); //Motor kiri mundur
}
else if (dataAnalog1 == 1 && dataAnalog2 == 1 && dataAnalog3 == 0) {
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(FORWARD); //Motor kanan berhenti
  motor2.run(FORWARD); //Motor kiri berhenti
  delay(3000);
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor1.run(RELEASE); //Motor kanan berhenti
  motor2.run(RELEASE);
}
}

void function2(void){
//merah
digitalWrite(S2,LOW);
digitalWrite(S3,LOW);
redFrequency1 = pulseIn(sensorOut1, LOW);
redColor = map(redFrequency1, 20, 70, 255, 0);
  Serial.print("R = ");
  Serial.print(redFrequency1);
  delay(100);
  
//hijau
digitalWrite(S2,HIGH);
digitalWrite(S3,HIGH);
greenFrequency1 = pulseIn(sensorOut1, LOW);\
greenColor = map(greenFrequency1, 78, 110, 255, 0);
  Serial.print(" G = ");
  Serial.print(greenFrequency1);
  delay(100);

//biru
digitalWrite(S2,LOW);
digitalWrite(S3,HIGH);
blueFrequency1 = pulseIn(sensorOut1, LOW);
blueColor = map(blueFrequency1, 45, 65, 255, 0);
  Serial.print(" B = ");
  Serial.println(blueFrequency1);
  delay(100);

}

void function3(void){
digitalWrite(trig, LOW);
  digitalWrite(trigg, LOW);
    delayMicroseconds(8);
digitalWrite(trig, HIGH);
  digitalWrite(trigg, HIGH);
    delayMicroseconds(8);
digitalWrite(trig, LOW);
  digitalWrite(trigg, LOW);
    delayMicroseconds(8);
    durasiA = pulseIn(echo, HIGH); // menerima suara ultrasonic
    jarakA = (durasiA / 2) / 29.1;  // mengubah durasi menjadi jarak (cm)
    durasiB = pulseIn(echoo, HIGH); // menerima suara ultrasonic
    jarakB = (durasiB / 2) / 29.1;  // mengubah durasi menjadi jarak (cm)
}

void function4(void){
//kipas
if(redFrequency1 <= 60 && 90 <= greenFrequency1 <=100 && 90 <= blueFrequency1 <= 110){
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  delay(4000);
  motor3.run(RELEASE);
  delay(1000);
  }

if(100 <= redFrequency1 <= 150 && 87 <= greenFrequency1 <=120 && 100 <= blueFrequency1 <= 120){
  motor3.run(RELEASE);
  }
else{
  motor3.run(RELEASE);
  delay(1000);
}

if(jarakA <= 16){
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(FORWARD); //Motor kanan maju
  motor2.run(BACKWARD); //Motor kiri mundur
  delay(2000);
  }

if(jarakB <= 16){
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(BACKWARD); //Motor kanan maju
  motor2.run(FORWARD); //Motor kiri mundur
  delay(2000);
}
}