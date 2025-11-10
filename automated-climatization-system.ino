#include "alarm.h"
#include "cooler.h"
#include "relay.h"
#include "rgb.h"
#include "dht11.h"
#include "lcd.h"

#define LOW_TEMPERATURE 25
#define HIGH_TEMPERATURE 30
#define TWO_SECONDS 2000
#define FIVE_SECONDS 5000

float hum;
float temp;

void setup() {
  /* Initialization */
  dht11Init();
  relayInit();
  alarmInit();
  coolerInit();
  lcdInit();
  rgbInit();

  lcdInitWrite();
  delay(FIVE_SECONDS);
  lcdClear();
}

void loop() {
  /* 1 - Read temperature and humidity */
  readTemperatureAndHumidity(&hum, &temp);
  /* 2 - Check if the temperature and humidity values are valid */
  if(isTemperatureValid(temp) || isHumidityValid(hum)) {
    lcdSensorFaulttWrite();
    /* Restart the loop function */
    return;
  }
  /* 3 - Show the values to the lcd screen */
  lcdTemperatureWrite(temp);
  lcdHumidityWrite(hum);
  /* 4 - Temperature logic */
  if (temp < LOW_TEMPERATURE) {
    /* Set the color of the RGB to BLUE */
    rgbSetColor(BLUE, ON);
    rgbSetColor(GREEN, OFF);
    rgbSetColor(RED, OFF);
    /* Turn the relay on */
    relayOn();
    /* Turn the alarm on */
    alarmOn();
    /* Turn the cooler off */
    coolerOff();
  } else if (temp >= LOW_TEMPERATURE && temp <= HIGH_TEMPERATURE) {
    /* Set the color of the RGB to GREEN */
    rgbSetColor(BLUE, OFF);
    rgbSetColor(GREEN, ON);
    rgbSetColor(RED, OFF);
    /* Turn the relay off */
    relayOff();
    /* Turn the alarm off */
    alarmOff();
    /* Turn the cooler off */
    coolerOff();
  } else {
    /* Set the color of the RGB to RED */
    rgbSetColor(BLUE, OFF);
    rgbSetColor(GREEN, OFF);
    rgbSetColor(RED, ON);
    /* Turn the relay off */
    relayOff();
    /* Turn the alarm on */
    alarmOn();
    /* Turn the cooler on */
    coolerOn();
  }

  delay(TWO_SECONDS);
  lcdClear();
}
