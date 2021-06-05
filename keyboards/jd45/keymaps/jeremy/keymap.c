#include QMK_KEYBOARD_H

/* this keymap is to provide a basic keyboard layout for testing the matrix
 * for more practical and complicated keymap refer to other keymaps in the same folder
 */

enum custom_keycodes {
    MC_ONE = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, LT(4, KC_DEL),
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
    _______, KC_LGUI, KC_LALT, LT(1, KC_BSPC),   _______, KC_LALT, LT(2, KC_SPC),    KC_RALT, KC_RCTL,          _______
  ),

  // [1] = LAYOUT(
  //   KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_DEL,
  //   KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,          KC_SCLN,
  //   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
  //   _______, KC_LGUI, KC_LALT, LT(1, KC_BSPC),   _______, KC_LALT, LT(2, KC_SPC),    KC_RALT, KC_RCTL,          _______
  // ),

  [1] = LAYOUT(
    KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, TG(3),
    KC_LCTL, KC_GRV,  KC_PIPE, KC_SLSH, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_BSLS, KC_MINS, KC_PLUS,          KC_SCLN,
    KC_LSFT, KC_Z,    KC_X,    KC_C,  LGUI(KC_V),KC_B,    KC_SLSH, KC_UNDS, KC_LT,   KC_GT,   KC_EQL,           KC_RSFT,
    _______, KC_LGUI, KC_LALT, LT(1, KC_BSPC),   _______, KC_LALT, LT(2, KC_SPC),    KC_RALT, KC_RCTL,          _______
  ),

  [2] = LAYOUT(
    KC_ESC,  KC_Q,    KC_7,    KC_8,    KC_9,    KC_0,    KC_Y,    KC_PGUP, KC_UP,   KC_O,    KC_P,    KC_BSPC, TG(3),
    KC_LCTL, KC_A,    KC_4,    KC_5,    KC_6,    KC_G,    KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,           KC_SCLN,
    KC_LSFT, KC_Z,    KC_1,    KC_2,    KC_3,    KC_B,    KC_N,    KC_PGDN, KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
    _______, KC_LGUI, KC_LALT, LT(1, KC_BSPC),   _______, KC_LALT, LT(2, KC_SPC),    KC_RALT, KC_RCTL,          _______
  ),

  [3] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, TG(3),
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
    _______, KC_LGUI, KC_LALT, KC_SPC,   _______,        KC_LALT, LT(2, KC_SPC),    KC_RALT, KC_RCTL,          _______
  ),

  [4] = LAYOUT(
    RESET,   KC_Q,    KC_FN7,  KC_FN8,  KC_FN9,  KC_FN10, KC_FN11, KC_FN12, KC_I,    KC_O,    KC_P,    KC_BSPC, LT(4, KC_DEL),
    KC_LCTL, KC_A,    KC_FN4,  KC_FN5,  KC_FN6,  KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,          KC_ENT,
    KC_LSFT, KC_Z,    KC_FN1,  KC_FN2,  KC_FN3,  KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
    _______, KC_LGUI, KC_LALT, LT(1, KC_BSPC),   _______, MC_ONE,  LT(2, KC_SPC),    KC_RALT, KC_RCTL,          _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MC_ONE:
        if (record->event.pressed) {
            SEND_STRING("MACRO ONE STR");
        } else {
        }
        break;
    }
    return true;
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Bottom Left Encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) { /* Bottom Right Encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    } else if (index == 2) { /* Top Right Encoder */
        if (clockwise) {
            tap_code(KC_LEFT);
        } else {
            tap_code(KC_RIGHT);
        }
    }
    return true;
}