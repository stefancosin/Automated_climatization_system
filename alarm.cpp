#include "alarm.h"

void alarmInit() {
    pinMode(ALARM, OUTPUT);
}

void alarmOn() {
    digitalWrite(ALARM, HIGH);
}

void alarmOff() {
    digitalWrite(ALARM, LOW);
}
