#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  

long duration;
int distance;

const int trigPin = 10;
const int echoPin = 11;

// Include the required Arduino libraries:

void setup() {
// put your setup code here, to run once:
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode (5, OUTPUT);
pinMode (6, OUTPUT);
pinMode (7, OUTPUT);
Serial.begin(115200);

 lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("                                     ");
  lcd.setCursor(0,1);
  lcd.print("                                      ");
}

void loop() {
function2();
  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("ALARM JARAK");
  lcd.setCursor(0,1);
  lcd.print("JARAK =  ");
  lcd.setCursor(11,1);
  lcd.print(" Cm");
function1();

}


void function1(){
digitalWrite(trigPin, LOW);
delayMicroseconds (2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;
if(distance >= 250){
  distance = 0;
}
Serial.print("Distance: ");
Serial.println(distance);

 lcd.setCursor(8,1);
  lcd.print(distance);
}

void function2(){
if(distance >=50 ){
  digitalWrite(5,LOW);
   digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  noTone(8);   
}
else if(distance <= 49 && distance >= 21){
  digitalWrite(5,HIGH);
   digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  tone(8, 500);
  delay(450);
  noTone(8);
  delay(500);
}
else if(distance <= 20 && distance >=10){
  digitalWrite(5,LOW);
   digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  tone(8, 500);
  delay(200);
  noTone(8);
  delay(70);
}
else if( distance <= 10 && distance >= 1){
    digitalWrite(5,LOW);
   digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
  tone(8, 500);
  
}
else {
      digitalWrite(5,LOW);
   digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  noTone(8);
}
}
