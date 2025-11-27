 #include <LiquidCrystal_I2C.h>
#define a 4
  int n = 0;
LiquidCrystal_I2C lcd(0x27,16,2);  // Kalau gagal ganti 0x3F ke 0x27 for a 16 chars and 2 line display
void setup()
{
pinMode(a,INPUT);
Serial.begin(9600);
 lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("                                     ");
  delay(100);
  lcd.setCursor(0,1);
  lcd.print("                                      ");
}


void loop()
{
int tombol;
tombol = digitalRead(a);
Serial.print("tombol = ");
Serial.println(tombol);
Serial.print("n = ");
Serial.println(n);

if(tombol >= 1){
  n = n+1;
  delay(200);

   if(n == 1){
 lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("HAPPY BIRTHDAY");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("NATHANAEL LOUIS A");
  delay(2500);
  lcd.setCursor(0,0);
  lcd.print("Panjang Umur  ");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("Sehat Selalu      ");
  delay(2500);
  lcd.setCursor(0,0);
  lcd.print("Makin Pintar  ");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("Makin Diberkati");
  delay(2500);
  lcd.setCursor(0,1);
  lcd.print("GOD BLESS YOU :)");
  delay(2500);
  lcd.setCursor(0,0);
  lcd.print("Ultah Ke-17  ");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("10 February 2007  ");
  delay(2500);
  lcd.setCursor(0,0);
  lcd.print("                                  ");
  delay(100);
  lcd.setCursor(0,1);
  lcd.print("                                 ");
  delay(5000);
  }
}
}

