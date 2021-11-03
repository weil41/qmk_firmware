// Copyright 2020 Christian Eiden, cykedev
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

//TODO remove this crap
#define SY_PLS LT(_SYMBOL, KC_PPLS)
#define SY_MIN LT(_SYMBOL, KC_MINS)
#define SY_SPC LT(NAV, KC_SPC)
#define G_COMM LGUI_T(KC_COMM)
#define A_DOT  LALT_T(KC_DOT)

#define ADJ    MO(_ADJUST)
#define NAV    MO(_NAV)
#define SYMBOL MO(_SYMBOL)

//TODO

enum layer_names {
    _QWERTY,
    _NAV,
    _SYMBOL,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //IDEAS
    ///Thumbs
    ////Move
    
    //TODO match keycaps
    //TODO fix diagram


/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Back |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| SYM + |    | SYM - |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Shift|
 * `-----------------------------------------/ Shift /     \  SYM \-----------------------------------------'
 *                   |  ADJ |  Alt |  Cmd | / Enter /       \ Space\  |  Alt | Home | End  |
 *                   |      |      |   ,  |/       /         \      \ |   .  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_QWERTY] = LAYOUT(
  SY_MIN,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SY_PLS,
  KC_GRV,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   KC_ESC,        KC_QUOT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                             KC_LCTRL,     KC_LGUI,  SY_SPC, KC_MINS,      KC_QUOT,  LT(SYMBOL, KC_SPC),   KC_LGUI, KC_LALT
),

/* Nav
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Back |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| SYM + |    | SYM - |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Shift|
 * `-----------------------------------------/ Shift /     \  SYM \-----------------------------------------'
 *                   |  ADJ |  Alt |  Cmd | / Enter /       \ Space\  |  Alt | Home | End  |
 *                   |      |      |   ,  |/       /         \      \ |   .  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 //TODO make move macro
  

 [_NAV] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   LALT(LSFT(KC_1)),   LALT(LSFT(KC_2)),    LALT(LSFT(KC_3)),    LALT(LSFT(KC_4)),    KC_T,                           LALT(KC_LEFT),    LALT(KC_DOWN),    LALT(KC_UP),    LALT(KC_RIGHT),    LALT(KC_BSPC),    KC_BSLS,
  KC_LCTRL, LALT(LCTL(KC_1)),   LALT(LCTL(KC_2)),    LALT(LCTL(KC_3)),    LALT(LCTL(KC_4)),    KC_G,                           KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT,    KC_BSPC, KC_QUOT,
  LALT(LCTL(KC_SPC)),  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   SY_PLS,        SY_MIN,  LGUI(KC_LEFT),    LGUI(KC_DOWN),    LGUI(KC_UP),    LGUI(KC_RIGHT),  LGUI(KC_BSPC), KC_RSFT,
                             ADJ,     KC_LALT, G_COMM, KC_SFTENT,     SY_SPC,  A_DOT,   KC_HOME, KC_END
),
/* SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   {  |   }  |   |  |                    |  &   |   +  |  up  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   #  |   $  |   (  |   )  |   `  |-------.    ,-------|  =   | left | down |right |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   %  |   ^  |   [  |   ]  |   ~  |-------|    |-------|  *   |   -  |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYMBOL] = LAYOUT(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
  _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                   KC_AMPR, KC_7, KC_8,   KC_9, XXXXXXX, XXXXXXX,
  _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                    KC_0, KC_4, KC_5, KC_6, XXXXXXX, XXXXXXX,
  _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, KC_ASTR, KC_1, KC_2, KC_3, XXXXXXX, _______,
                             _______, _______, _______, _______, _______,  _______, XXXXXXX, XXXXXXX
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  RST |      |      |      |      |      |                    |      |      |      |      |      | RST  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |  V+  |                    |  Br+ |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |  V-  |-------.    ,-------|  Br- |  <<  | play |  >>  |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      | Mute |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT(
  EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EEP_RST,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,                   KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,                   KC_BRID, KC_MRWD, KC_MPLY, KC_MFFD, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)
};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SY_SPC:
            return true;
        default:
            return false;
    }
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;
  return rotation;
}

const char *read_logo(void);

void oled_task_user(void) {
  oled_write_ln(read_logo(), false);
}
#endif // OLED_ENABLE

