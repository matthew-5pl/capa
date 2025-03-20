#include "capacitive.h"

uint16_t capacitive_read(unsigned int pin) {
    uint16_t out = 0;

    for(int i = 0; i < SAMPLES; i++) {
        gpio_set_pin_output(pin);
        gpio_write_pin_high(pin);
        gpio_set_pin_input(pin);

        while(gpio_read_pin(pin) && out < TIMEOUT) {
            out++;
        }
    }

    return out;
}

bool capacitive_pressed(unsigned int pin) {
    return capacitive_read(pin) > THRESHOLD;
}
