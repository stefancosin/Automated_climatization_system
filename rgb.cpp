#include "rgb.h"

void rgbInit() {
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
}

void rgbSetColor(RGB_COLOR color, RGB_STATE state) {
    if (color == RED) {
        if (state == ON) {
            digitalWrite(RED_PIN, HIGH);
        } else {
            digitalWrite(RED_PIN, LOW);
        }
    } else if (color == GREEN) {
        if (state == ON) {
            digitalWrite(GREEN_PIN, HIGH);
        } else {
            digitalWrite(GREEN_PIN, LOW);
        }
    } else {
        if (state == ON) {
            digitalWrite(BLUE_PIN, HIGH);
        } else {
            digitalWrite(BLUE_PIN, LOW);
        }
    }
}
