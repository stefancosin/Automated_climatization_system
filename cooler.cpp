#include "cooler.h"

void coolerInit() {
    pinMode(COOLER, OUTPUT);
}

void coolerOn() {
    digitalWrite(COOLER, HIGH);
}

void coolerOff() {
    digitalWrite(COOLER, LOW);
}
