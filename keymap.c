#include QMK_KEYBOARD_H
#include <cyboard.h>
#include "oneshot.h"

enum layers {
  _ENTHIUM_REVERSED,
  _ENTHIUM,
  _LOWER,
  _RAISE,
  _ADJUST,
  _F_ROW,
  _GAME,
  _GAME_NUM
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //   z y u o ; q l d p x
    // w c i e a , k h t n s f
    //   ' - = . / j m g b v
    //         r
    [_ENTHIUM] = LAYOUT_fun(
        KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______,  KC_W,    KC_Y,    KC_U,    KC_O,    KC_SCLN,                       KC_Q,    KC_L,    KC_D,    KC_P,    KC_F,    _______,
        KC_Z,     KC_C,    KC_I,    KC_E,    KC_A,    KC_COMM,                       KC_K,    KC_H,    KC_T,    KC_N,    KC_S,    KC_X,
        KC_LSFT,  KC_QUOT, KC_MINS, KC_EQL,  KC_DOT,  KC_SLSH,                       KC_J,    KC_M,    KC_G,    KC_B,    KC_V,    KC_RSFT,

                       KC_LEFT, KC_RIGHT,   OS_SHFT, KC_R, KC_ESC,           KC_LCMD, KC_BSPC, KC_SPC,  KC_DOWN, KC_UP,
                                            LOWER, KC_LCTL, KC_TAB,           KC_LALT,  KC_ENT, RAISE
    ),

    //   x p d l q ; o u y z
    // f s n t h k , a e i c w
    //   v b g m j / . = - '
    //         r

    [_ENTHIUM_REVERSED] = LAYOUT_fun(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                               KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, KC_X,    KC_P,    KC_D,    KC_L,    KC_Q,                                KC_SCLN, KC_O,    KC_U,    KC_Y,    KC_Z,    _______,
        KC_F,    KC_S,    KC_N,    KC_T,    KC_H,    KC_K,                                KC_COMM, KC_A,    KC_E,    KC_I,    KC_C,    KC_W,
        KC_LSFT, KC_V,    KC_B,    KC_G,    KC_M,    KC_J,                                KC_SLSH, KC_DOT,  KC_EQL,  KC_MINS, KC_QUOT, KC_RSFT,

                       KC_LEFT, KC_RIGHT,   OS_SHFT, KC_R, KC_ESC,           KC_LCMD, KC_BSPC, KC_SPC,  KC_DOWN, KC_UP,
                                            LOWER, KC_LCTL, KC_TAB,           KC_LALT,  KC_ENT, RAISE
    ),

    [_LOWER] = LAYOUT_fun(
        QK_BOOT, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______,  _______,
        _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______,  _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     _______,
        _______, OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, KC_PERC,                  KC_ESC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  _______,
        _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,                  KC_DEL,  KC_BSPC, KC_TAB,  KC_ENT,  KC_SCLN,  _______,

                          _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),

    [_RAISE] = LAYOUT_fun(
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_TILD,                           KC_CIRC, KC_AMPR, KC_QUES, KC_SLSH, KC_ASTR, _______,
        _______, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_PERC,                           KC_PIPE, OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD, _______,
        _______, KC_LBRC, KC_RBRC, KC_UNDS, KC_MINS, KC_GRV,                            KC_BSLS, KC_EQL,  KC_RABK, KC_LABK, KC_PLUS, _______,

                          _______, _______, KC_SPC,  _______, _______,         _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_fun(
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______,    _______,
        _______, _______, _______, _______, _______, DF(_ENTHIUM),                      DF(_ENTHIUM_REVERSED), _______, _______, _______, _______,    _______,
        _______, KC_BTN2, KC_WH_U, KC_MS_U, KC_WH_D, KC_TAB,                            G(KC_N), G(KC_L), G(KC_T), G(KC_W), G(KC_SPC),  _______,
        _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_Q,                              C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5),    _______,
        _______, KC_BTN4, KC_BTN5, G(KC_C), G(KC_V), KC_ENT,                            KC_DEL,  KC_BSPC, KC_LGUI, KC_LALT, MO(_F_ROW), _______,
                          _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),

    [9] = LAYOUT_fun(
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    )
};


__attribute__((weak)) combo_t key_combos[] = {

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// one shot cancel
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LOWER:
    case RAISE:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LOWER:
    case RAISE:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
        update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}
// end of one shot cancel