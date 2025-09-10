#ifndef DHT11_H
#define DHT11_H

#include <Arduino.h>
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

void dht11Init();
void readTemperatureAndHumidity(float* humidity, float* temperature);
bool isTemperatureValid(float temperature);
bool isProximityValid(float humidity);

#endif
