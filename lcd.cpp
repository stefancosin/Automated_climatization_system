#include "lcd.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void lcdInit() {
    Wire.begin(21, 22);
    lcd.begin();
    lcd.backlight();
}

void lcdClear() {
    lcd.clear();
}

void lcdInitWrite() {
    lcd.setCursor(0, 0);
    lcd.print("ESP32 Weather");
    lcd.setCursor(0, 1);
    lcd.print("Initializing..");
    lcdClear();
}

void lcdTemperatureWrite(float temperature) {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature, 1);
    lcd.print((char)223);
    lcd.print("C");
}

void lcdHumidityWrite(float humidity) {
    lcd.setCursor(0, 1);
    lcd.print("Hum: ");
    lcd.print(humidity, 1);
    lcd.print("%");
}

void lcdSensorFaulttWrite() {
    lcdClear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
}