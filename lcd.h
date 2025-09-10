#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_SDA_PIN 21
#define I2C_SCL_PIN 22

void lcdInit();
void lcdClear();
void lcdInitWrite();
void lcdSensorFaulttWrite();
void lcdTemperatureWrite(float temperature);
void lcdHumidityWrite(float humidity);

#endif