#ifndef RGB_H
#define RGB_H

#include <Arduino.h>

#define RED_PIN   15
#define GREEN_PIN 16
#define BLUE_PIN  17

enum RGB_COLOR {RED = 0, GREEN = 1, BLUE = 2};
enum RGB_STATE {OFF = 0, ON = 1};

void rgbInit();
void rgbSetColor(RGB_COLOR color, RGB_STATE state);

#endif