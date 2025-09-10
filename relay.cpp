#include "relay.h"

void relayInit() {
    pinMode(RELAY, OUTPUT);
}

void relayOn() {
    digitalWrite(RELAY, HIGH);
}

void relayOff() {
    digitalWrite(RELAY, LOW);
}
