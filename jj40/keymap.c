/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

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
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit( \
  KC_TAB,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,   KC_Y,  KC_U,         KC_I,         KC_O,         KC_P,            KC_BSPC, \
  KC_ESC,  LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,   KC_H,  RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT, \
  KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,   KC_N,  KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_ENT,  \
  _______, KC_LCTL,      KC_LALT,      KC_LGUI,      LOWER,        KC_SPC, RAISE, KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |     |    \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit( \
  KC_TILD, KC_EXLM,       KC_AT,         KC_HASH,       KC_DLR,        KC_PERC, KC_CIRC, KC_AMPR,         KC_ASTR,         KC_LPRN,         KC_RPRN,         KC_BSPC, \
  KC_DEL,  LGUI_T(KC_F1), LALT_T(KC_F2), LCTL_T(KC_F3), LSFT_T(KC_F4), KC_F5,   KC_F6,   RSFT_T(KC_UNDS), RCTL_T(KC_PLUS), RALT_T(KC_LCBR), RGUI_T(KC_RCBR), KC_PIPE, \
  _______, KC_F7,         KC_F8,         KC_F9,         KC_F10,        KC_F11,  KC_F12,  S(KC_NUHS),      S(KC_NUBS),      _______,         _______,         _______, \
  _______, _______,       _______,       _______,       _______,       _______, _______, KC_MNXT,         KC_VOLD,         KC_VOLU,         KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit( \
  KC_GRV,  KC_1,          KC_2,          KC_3,          KC_4,          KC_5,    KC_6,    KC_7,            KC_8,           KC_9,            KC_0,            KC_BSPC, \
  KC_DEL,  LGUI_T(KC_F1), LALT_T(KC_F2), LCTL_T(KC_F3), LSFT_T(KC_F4), KC_F5,   KC_F6,   RSFT_T(KC_MINS), RCTL_T(KC_EQL), LALT_T(KC_LBRC), RGUI_T(KC_RBRC), KC_BSLS, \
  _______, KC_F7,         KC_F8,         KC_F9,         KC_F10,        KC_F11,  KC_F12,  KC_NUHS,         KC_NUBS,        _______,         _______,         _______, \
  _______, _______,       _______,       _______,       _______,       _______, _______, KC_MNXT,         KC_VOLD,        KC_VOLU,         KC_MPLY \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |SESS_1|SESS_2|SESS_3|SESS_4|SESS_5|SESS_6|SESS_7|SESS_8|SESS_9|      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Down | Up   |Right |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |SESS_C|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  RESET,   SESS_1,          SESS_2,          SESS_3,          SESS_4,          SESS_5,  SESS_6,  SESS_7,  SESS_8,  SESS_9,  _______, KC_DEL,  \
  _______, LGUI_T(_______), LALT_T(BL_TOGG), LCTL_T(BL_STEP), LSFT_T(_______), _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, \
  _______, RGB_VAD,         RGB_TOG,         RGB_MOD,         RGB_VAI,         _______, _______, _______, _______, _______, _______, SESS_C,  \
  _______, _______,         _______,         _______,         _______,         _______, _______, _______, _______, _______, _______, _______ \
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
