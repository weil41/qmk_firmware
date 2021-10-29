#include QMK_KEYBOARD_H
#include "layers.h"

#ifdef ENCODER_ENABLE

//TODO determine which encoder is which
//TODO add volume encoding
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        //switch (get_highest_layer(layer_state)) {
        }
    } else if (index == 1) {
    }
    return true;
}
#endif
