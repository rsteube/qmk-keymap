#include QMK_KEYBOARD_H

enum layers {
  _QWERTY = 0,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define QWERTY  DF(_QWERTY)
#define COLEMAK DF(_COLEMAK)

#define SESS_1 LCTL(LALT(KC_1))
#define SESS_2 LCTL(LALT(KC_2))
#define SESS_3 LCTL(LALT(KC_3))
#define SESS_4 LCTL(LALT(KC_4))
#define SESS_5 LCTL(LALT(KC_5))
#define SESS_6 LCTL(LALT(KC_6))
#define SESS_7 LCTL(LALT(KC_7))
#define SESS_8 LCTL(LALT(KC_8))
#define SESS_9 LCTL(LALT(KC_9))
#define SESS_C LCTL(LALT(KC_C))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT( \
  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,    KC_Y,   KC_U,         KC_I,         KC_O,         KC_P, \
  LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,    KC_H,   RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), \
  KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,    KC_N,   KC_M,         KC_COMM,      KC_DOT,       KC_SLSH, \
                                            LOWER,        KC_BSPC, KC_SPC, RAISE \
),
[_COLEMAK] = LAYOUT( \
  KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,    KC_J,   KC_L,         KC_U,         KC_Y,         KC_SCLN, \
  LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,    KC_M,   RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), \
  KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,    KC_K,   KC_M,         KC_COMM,      KC_DOT,       KC_SLSH, \
                                            LOWER,        KC_BSPC, KC_SPC, RAISE \
),
[_LOWER] = LAYOUT( \
 KC_EXLM,       KC_AT,         KC_HASH,       KC_DLR,        KC_PERC, KC_CIRC, KC_AMPR,         KC_ASTR,         KC_LPRN,         KC_RPRN,         \
 LGUI_T(KC_F1), LALT_T(KC_F2), LCTL_T(KC_F3), LSFT_T(KC_F4), KC_F5,   KC_F6,   RSFT_T(KC_UNDS), RCTL_T(KC_PLUS), LALT_T(KC_LCBR), RGUI_T(KC_RCBR), \
 KC_F7,         KC_F8,         KC_F9,         KC_F10,        KC_F11,  KC_F12,  S(KC_NUHS),      S(KC_NUBS),      _______,         _______,         \
                                              LOWER,         KC_BSPC, KC_SPC,  RAISE \
),
[_RAISE] = LAYOUT( \
 KC_1,          KC_2,          KC_3,          KC_4,          KC_5,    KC_6,    KC_7,            KC_8,           KC_9,            KC_0,            \
 LGUI_T(KC_F1), LALT_T(KC_F2), LCTL_T(KC_F3), LSFT_T(KC_F4), KC_F5,   KC_F6,   RSFT_T(KC_MINS), RCTL_T(KC_EQL), LALT_T(KC_LBRC), RGUI_T(KC_RBRC), \
 KC_F7,         KC_F8,         KC_F9,         KC_F10,        KC_F11,  KC_F12,  KC_NUHS,         KC_NUBS,        _______,         _______,         \
                                              LOWER,         KC_BSPC, KC_SPC,  RAISE \
),
[_ADJUST] =  LAYOUT( \
  SESS_1,          SESS_2,          SESS_3,          SESS_4,          SESS_5,  SESS_6,  SESS_7,  SESS_8,  SESS_9,  _______, \
  LGUI_T(_______), LALT_T(_______), LCTL_T(_______), LSFT_T(_______), _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, \
  _QWERTY,         _COLEMAK,        _______,         _______,         _______, _______, _______, _______, _______, _______, \
                                              LOWER,         KC_BSPC, KC_SPC,  RAISE \
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}



const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {LALT_T(KC_S), LCTL_T(KC_D), COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {RCTL_T(KC_K), LALT_T(KC_L), COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(we_combo, KC_TAB),
    COMBO(sd_combo, KC_ESC),
    COMBO(io_combo, KC_BSPC),
    COMBO(kl_combo, KC_ENT),
};
