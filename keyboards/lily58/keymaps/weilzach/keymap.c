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

    //TODO Change upper left -/_
    //TODO add layer to thumb -/_

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | -/_  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | =/+  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | `/~  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \|  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------| Esc   |    |   '/" |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Shift|
 * `-----------------------------------------/ -/_   /     \  '/" \-----------------------------------------'
 *                   |  Ctl |  Cmd | Space| /       /       \      \  | Space| Cmd  | Alt  |
 *                   |      |      | Nav  |/       /         \      \ | Num  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_QWERTY] = LAYOUT(
  SY_MIN,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQUAL,
  KC_GRV,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   KC_ESC,        KC_QUOT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                             KC_LCTRL, KC_LGUI, SY_SPC, KC_MINS,      KC_QUOT,  LT(SYMBOL, KC_SPC),   KC_LGUI, KC_RALT
),

/* Nav
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |Send 1|Send 2|Send 3|Send 4|Send 5|                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |Move 1|Move 2|Move 3|Move 4|Move 5|-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| SYM + |    | SYM - |------+------+------+------+------+------|
 * | Omni |      |      |      |      |      |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Shift|
 * `-----------------------------------------/ Shift /     \  SYM \-----------------------------------------'
 *                   |  ADJ |  Alt |  Cmd | / Enter /       \ Space\  |  Alt | Home | End  |
 *                   |      |      |   ,  |/       /         \      \ |   .  |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 //TODO make move macro
 //TODO make Omni a macro
  

 //TODO remove unused keys
 [_NAV] = LAYOUT(
  KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,                           KC_TRNS,       KC_TRNS,       KC_TRNS,     KC_TRNS,        KC_TRNS,       KC_TRNS,
  KC_TRNS,     LSA(KC_1), LSA(KC_2), LSA(KC_3), LSA(KC_4), LSA(KC_5),                         LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_UP), LALT(KC_RIGHT), LALT(KC_BSPC), KC_BSLS,
  KC_TRNS,     LCA(KC_1), LCA(KC_2), LCA(KC_3), LCA(KC_4), LCA(KC_5),                         KC_LEFT,       KC_DOWN,       KC_UP,       KC_RIGHT,       KC_BSPC,       KC_QUOT,
  LCA(KC_SPC), KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_TRNS, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_UP), LGUI(KC_RIGHT), LGUI(KC_BSPC), KC_RSFT,
                                     ADJ,       KC_LALT,   G_COMM,    KC_SFTENT,     SY_SPC,  A_DOT,         KC_HOME,       KC_END
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

