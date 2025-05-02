// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "capacitive.h"

#define PIN_LEFT	GP27
#define PIN_RIGHT	GP26

void keyboard_post_init_user(void) {
	if(capacitive_pressed(PIN_LEFT)) {
		reset_keyboard();
	}

	debug_enable = true;
	debug_matrix = true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_osu(
        KC_Z,   KC_X
    )
};
