#include "quantum.h"
#include "capacitive.h"

#define PIN_LEFT	GP27
#define PIN_RIGHT	GP26

static matrix_row_t last_row = 0;

bool matrix_scan_custom(matrix_row_t mat[]) {
    bool pressed_left = capacitive_pressed(PIN_LEFT);
    bool pressed_right = capacitive_pressed(PIN_RIGHT);

    mat[0] = (pressed_right << 1) | pressed_left;   
    
    bool changed = mat[0] != last_row;
    last_row = mat[0];
    
    return changed;
}
