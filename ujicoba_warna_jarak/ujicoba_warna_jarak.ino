#define x A0
#define y A1
void setup() {
  // Tidak ada yang perlu diinisialisasi di sini
}

void loop() {
  // Baca nilai dari joystick
  int xAxis = analogRead(x);
    Serial.println (xAxis);
  int yAxis = analogRead(y);
    Serial.println (yAxis);
Serial.begin(9600);
  // Tambahkan delay untuk menghindari pengiriman data terlalu cepat
  delay(10);
}