//Deklarasi PIN
int trig = 13; // membuat varibel trig yang di set ke-pin D6
int echo = 11; // membuat variabel echo yang di set ke-pin D7
long durasiA, jarakA;     // membuat variabel durasi dan jarak
long durasiB, jarakB;     // membuat variabel durasi dan jarak
int merah = 2;
int trigg = 10; // membuat varibel trig yang di set ke-pin D6
int echoo = 12; // membuat variabel echo yang di set ke-pin D7
int hijau = 3;

///////////////////////////////////////////////////////////////////////////////////

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut1 8
#include <NewPing.h>
int redFrequency1 = 0;
int greenFrequency1 = 0;
int blueFrequency1 = 0;

///////////////////////////////////////////////////////////////////////////////
#include <AFMotor.h>
const int pinSensorKiri = A0;
const int pinSensorKanan = A5;
///////////////////////////////////////////////////////////////////////////////

char val;
AF_DCMotor motor1(2, MOTOR12_64KHZ); //Jadikan motor kanan, 64KHZ
AF_DCMotor motor2(3, MOTOR12_64KHZ); //Jadikan motor kiri, 642hHZ

void setup() {
  pinMode(trig, OUTPUT);    // set pin trig menjadi OUTPUT
  pinMode(echo, INPUT);     // set pin echo menjadi INPUT
  pinMode(trigg, OUTPUT);    // set pin trig menjadi OUTPUT
  pinMode(echoo, INPUT);     // set pin echo menjadi INPUT
  pinMode(merah, OUTPUT);
  pinMode(hijau,OUTPUT);
  ////////////////////////////////////////////////////////////////////////////
   pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut1,INPUT);
  // Setting frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
   // Begins serial communication 
  Serial.begin(9600);       // digunakan untuk komunikasi Serial dengan komputer
  //////////////////////////////////////////////////////////////////////////////
  Serial.begin (9600);
  pinMode (pinSensorKiri, INPUT);
  pinMode (pinSensorKanan, INPUT);
  motor1.setSpeed(180); //Set kecepatan motor 1 240 (range 0-255)
  motor2.setSpeed(180); //Set kecepatan motor 2 240 (range 0-255)
}

void loop() {
     unsigned long currentTime = millis();
    unsigned long previousTime1 = 0;
  const unsigned long interval1 = 500; //////tiap 1/2 dtk
  ////////////////////////////////////////////////////////////////////////////////
  digitalWrite(trig, LOW);
   delayMicroseconds(8);
  digitalWrite(trig, HIGH);
  delayMicroseconds(8);
  digitalWrite(trig, LOW);
  delayMicroseconds(8);
  durasiA = pulseIn(echo, HIGH); // menerima suara ultrasonic
  jarakA = (durasiA / 2) / 29.1;  // mengubah durasi menjadi jarak (cm)

   
   if (currentTime - previousTime1 >= interval1) {
    previousTime1 = currentTime;
  if(jarakA >= 16){
    digitalWrite(merah, LOW);
  }
  else {
    digitalWrite(merah, HIGH);
  }
   }

  unsigned long previousTime2 = 0;
  const unsigned long interval2 = 500; //////tiap 1/2 dtk
   digitalWrite(trigg, LOW);
    delayMicroseconds(8);
   digitalWrite(trigg, HIGH);
    delayMicroseconds(8);
   digitalWrite(trigg, LOW);
    delayMicroseconds(8);
        durasiB = pulseIn(echoo, HIGH); // menerima suara ultrasonic
         jarakB = (durasiB / 2) / 29.1;  // mengubah durasi menjadi jarak (cm)

  if (currentTime - previousTime2 >= interval2) {
    previousTime2 = currentTime;
if(jarakB >= 16){
    digitalWrite(hijau, LOW);
  }
  else {
    digitalWrite(hijau, HIGH);
  }
   }
 ///////////////////////////////////////////////////////////////////////////////////////////////////////  
    unsigned long previousTime3 = 0;
  const unsigned long interval3 = 500; //////tiap 1/2 dtk
   if (currentTime - previousTime3 >= interval3) {
    previousTime3 = currentTime;
      // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Reading the output frequency
  redFrequency1 = pulseIn(sensorOut1, LOW);
  
   // Printing the RED (R) value
  Serial.print("R = ");
  Serial.print(redFrequency1);
  delay(100);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  greenFrequency1 = pulseIn(sensorOut1, LOW);
  
  // Printing the GREEN (G) value  
  Serial.print(" G = ");
  Serial.print(greenFrequency1);
  delay(100);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  blueFrequency1 = pulseIn(sensorOut1, LOW);
  
  // Printing the BLUE (B) value 
  Serial.print(" B = ");
  Serial.println(blueFrequency1);
  delay(100);
}
//////////////////////////////////////////////////////////////////////////////////////////
 unsigned long previousTime4 = 0;
  const unsigned long interval4 = 500; //////tiap 1/2 dtk
   if (currentTime - previousTime4 >= interval4) {
    previousTime4 = currentTime;
int dataAnalog1 = digitalRead (pinSensorKiri);
int dataAnalog2 = digitalRead (pinSensorKanan);
Serial.print ("Sensor1 : ");
Serial.println (dataAnalog1);
Serial.print ("Sensor2 : ");
Serial.println (dataAnalog2);

if (dataAnalog1 == 0 && dataAnalog2 == 0) {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(FORWARD); //Motor kanan maju
  motor2.run(FORWARD); //Motor kiri maju
}
else if(dataAnalog1 == 0 && dataAnalog2 == 1) {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(BACKWARD); //Motor kanan mundur
  motor2.run(FORWARD); //Motor kiri maju
}
else if(dataAnalog1 == 1 && dataAnalog2 == 0){
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(FORWARD); //Motor kanan maju
  motor2.run(BACKWARD); //Motor kiri mundur
}

else {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(RELEASE); //Motor kanan berhenti
  motor2.run(RELEASE); //Motor kiri berhenti
}
}
}