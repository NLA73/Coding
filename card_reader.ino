   #include <SPI.h> //library serial parallel interface
#include <Wire.h> //library untuk wire i2c
#include <RFID.h> //library RFID
#include <LiquidCrystal_I2C.h> //library LCD+I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize LCD Display at address 0x27 / 0X3F
int data1 = 51;
int data5 = 90;
#define sda 10 //Pin Serialdata (SDA)
#define rst 9 //pin Reset

RFID rfid(sda, rst);

void setup() {
  Serial.begin(9600); //baud komunikasi serial monitor
  lcd.init();
  lcd.setBacklight(255); //menghidupkan lampu latar LCD
  SPI.begin(); //Prosedur antarmuka SPI
  rfid.init(); //Memulai inialisasi module RFID

  lcd.setCursor (0, 0);
  lcd.clear();
}

void loop() {
  if(data1 == 0 && data5 == 0){
  lcd.setCursor (0, 0);
  lcd.print(" Please Register  ");
  lcd.setCursor (0, 1);
  lcd.print("     New ID  ");
  }
  else{
  lcd.setCursor (0, 0);
  lcd.print(" Card ID Reader ");
  lcd.setCursor (0, 1);
  lcd.print("Tap Card To Scan ");
  }
  function1();
  Serial.println(data1);
  Serial.println(data5);

}

void function1(){
if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      lcd.clear();
      Serial.print(rfid.serNum[0]); //serial no.1
      Serial.print(rfid.serNum[1]); //serial no.2
      Serial.print(rfid.serNum[2]); //serial no.3
      Serial.print(rfid.serNum[3]); //serial no.4
      Serial.print(rfid.serNum[4]); //serial no.5
   

  if(rfid.serNum[0] == 51 && rfid.serNum[4] == 90){
  lcd.setCursor (0, 0);
  lcd.print("  Registered ID   ");
  lcd.setCursor (0, 1);
  lcd.print("      Reset       ");
  data1 = 0;
  data5 = 0;
  delay(2000);
  lcd.clear();
 }
 
  else if(data1 == 0 && data5 == 0){
  lcd.setCursor (0, 0);
  lcd.print("     New ID   ");
  lcd.setCursor (0, 1);
  lcd.print("   Registered  ");
  data1 = rfid.serNum[0];
  data5 = rfid.serNum[4];
  delay(3000);
  lcd.clear();
  }
 else if(data1 == rfid.serNum[0] && data5 == rfid.serNum[4]){
  lcd.setCursor (0, 0);
  lcd.print(" ID Card Access     ");
  lcd.setCursor (0, 1);
  lcd.print("    Granteed    ");
  delay(2000);
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("      Gate ");
  lcd.setCursor (0, 1);
  lcd.print("     Opened ");
  delay(5000);
  lcd.setCursor (0, 0);
  lcd.print("      Gate ");
  lcd.setCursor (0, 1);
  lcd.print("     Closed ");
  delay(2000);
  lcd.clear();
 }
 else{
  lcd.setCursor (0, 0);
  lcd.print(" ID Card Access     ");
  lcd.setCursor (0, 1);
  lcd.print("     Denied    ");
  delay(2000);
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("      Gate ");
  lcd.setCursor (0, 1);
  lcd.print("     Closed ");
  delay(2000);
  lcd.clear();
 }
    }
  }
}