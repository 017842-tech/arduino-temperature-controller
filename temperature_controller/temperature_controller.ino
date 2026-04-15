#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int sensor = A0;
int ledVerde = 9;
int ledRojo = 10;

void setup() {
  lcd.begin(16, 2);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
}

void loop() {
  int lectura = analogRead(sensor);
  float voltaje = lectura * (5.0 / 1023.0);
  float temperatura = (voltaje - 0.5) * 100;

  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperatura);
  lcd.print(" C   ");

  lcd.setCursor(0, 1);

  // LÓGICA
  if (temperatura <= 25) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledRojo, LOW);

    lcd.print("Temp Bien       ");
  } 
  else {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledRojo, HIGH);

    lcd.print("Temp Alta       ");
  }

  delay(1000);
}