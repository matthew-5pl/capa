#include "quantum.h"
#include "capacitive.h"

#define PIN_LEFT	GP27
#define PIN_RIGHT	GP26

static matrix_row_t last_row = 0;

bool matrix_scan_custom(matrix_row_t mat[]) {
    bool pressed_left = capacitive_pressed(PIN_LEFT);
    bool pressed_right = capacitive_pressed(PIN_RIGHT);

    if(pressed_left) {
        mat[0] |= 0b01;
    } else {
        mat[0] &= 0b10;
    }
    
    if(pressed_right) {
        mat[0] |= 0b10;
    } else {
        mat[0] &= 0b01;
    }   
    
    bool changed = mat[0] != last_row;
    last_row = mat[0];
    
    return changed;
}
