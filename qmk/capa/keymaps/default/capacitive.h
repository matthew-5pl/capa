#ifndef CAPACITIVE_H

#include QMK_KEYBOARD_H
#include "quantum.h"

#define SAMPLES 5
#define TIMEOUT 10000
#define THRESHOLD 1500

uint16_t capacitive_read(unsigned int pin);
bool capacitive_pressed(unsigned int pin);

#define CAPACITIVE_H
#endif // CAPACITIVE_H
