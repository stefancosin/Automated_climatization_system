#include "dht11.h"

DHT dht(DHTPIN, DHTTYPE);

void dht11Init() {
    dht.begin();
}

void readTemperatureAndHumidity(float* humidity, float* temperature) {
    *humidity = dht.readHumidity();
    *temperature = dht.readTemperature();
}

bool isTemperatureValid(float temperature) {
    return isnan(temperature);
}

bool isHumidityValid(float humidity) {
    return isnan(humidity);
}

