#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = A0;
const int red1 = 6;
const int red2 = 7;
const int yellow = 8;
const int blue1 = 9;
const int blue2 = 10;

void setup() {
  Serial.begin(9600);
  
  lcd.begin(16, 2); // size of screen
  lcd.print("Temperature:");

  for (int i = 6; i < 11; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }

}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);

  float temp = (voltage - 0.5) * 100;
  Serial.print(", Temperature (deg C): ");
  Serial.println(temp);

  lcd.setCursor(0, 1);
  lcd.print(temp);
  lcd.print(" C");

  // LEDs
  if (temp > 35) {
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(blue1, LOW);
    digitalWrite(blue2, LOW);
  } else if (temp > 25) {
    digitalWrite(red1, HIGH);
    digitalWrite(red2, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(blue1, LOW);
    digitalWrite(blue2, LOW);
  } else if (temp > 20) {
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(blue1, LOW);
    digitalWrite(blue2, LOW);
  } else if (temp > 10) {
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(blue1, HIGH);
    digitalWrite(blue2, LOW);
  } else {
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(blue1, HIGH);
    digitalWrite(blue2, HIGH);
  }

  delay(500);
}
