#include <stdint.h>
#include <stdbool.h>

#include "gpio_manip.h"

uint32_t direction_gpio_bank1 = 0;
uint32_t value_gpio_bank1 = 0;

//for limit values (negative ones) the bit change backword ( exp : -1 = 31th bit , -2 = 30th bit...)

int set_gpio_output(int gpio_index){
    // change the bit value to one of the specific gpio_index.
    direction_gpio_bank1 |= 1 << gpio_index;
}

int set_gpio_input(int gpio_index){
    // change the bit value to zero of the specific gpio_index.
    direction_gpio_bank1 |= 0 << gpio_index;
}

int write_gpio(int gpio_index, bool value){
    //check the value if it's true then gpio_index = 1 else gpio_index = 0
    value? (value_gpio_bank1 |= 1 << gpio_index) : (value_gpio_bank1 |= 0 << gpio_index);
}
